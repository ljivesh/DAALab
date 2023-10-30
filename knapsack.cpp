#include <stdio.h>
#include<stdlib.h>
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int knapsack(int P[], int W[], int n, int M) {
    int knap[n + 1][M + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (W[i - 1] <= w)
                knap[i][w] = max(P[i - 1] + knap[i - 1][w - W[i - 1]], knap[i - 1][w]);
            else
                knap[i][w] = knap[i - 1][w];
        }
    }
    return knap[n][M];
}
int main() {
    int n, M, *P, *W;
    printf("Palak Garg 35514811621\n");
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the capacity: ");
    scanf("%d", &M);
    P = (int *)malloc(n * sizeof(int));
    W = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter the Profit and Weight for object [%d]\n", i + 1);
        printf("Profit: ");
        scanf("%d", &P[i]);
        printf("Weight: ");
        scanf("%d", &W[i]);
    }
    printf("The solution is: %d", knapsack(P, W, n, M));
    free(P);
    free(W);
    return 0;
}
