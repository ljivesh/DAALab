#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of the sorted portion to the right until the correct position is found
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Palak Garg 35514811621\n";

    int arr[] = {10, 50, 20, 30, 15};
    int N = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, N);

    std::cout << "Sorted array: " << std::endl;
    printArray(arr, N);

    return 0;
}
