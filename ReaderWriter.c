#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t mutex, writeMutex;
int data = 0;
int readersCount = 0;

void *reader(void *arg) {
    int readerID = *((int *)arg);
    while (1) {
        sem_wait(&mutex);

        readersCount++;

        if (readersCount == 1) {
            sem_wait(&writeMutex);
        }

        sem_post(&mutex);

        printf("Reader %d is reading data: %d\n", readerID, data);

        sem_wait(&mutex);

        readersCount--;

        if (readersCount == 0) {
            sem_post(&writeMutex);
        }

        sem_post(&mutex);

        // Introduce a delay to slow down readers
        sleep(1);
    }
}

void *writer(void *arg) {
    int writerID = *((int *)arg);
    while (1) {
        sem_wait(&writeMutex);

        data++;
        printf("Writer %d is writing data: %d\n", writerID, data);

        sem_post(&writeMutex);

        // Introduce a delay to slow down writers
        sleep(1);
    }
}
int main() {

    printf("Jivesh Lakhani 04714811621");

    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int readerIDs[NUM_READERS];
    int writerIDs[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&writeMutex, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        readerIDs[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIDs[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIDs[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIDs[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeMutex);

    return 0;
}
