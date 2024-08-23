#include <stdio.h>
#define MAX 10000

// maximum value in the array
int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}


void countSort(int A[], int n, int pos) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(A[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / pos) % 10] - 1] = A[i];
        count[(A[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void radixSort(int A[], int n) {
    int max = getMax(A, n);

    for (int pos = 1; max / pos > 0; pos *= 10) {
        countSort(A, n, pos);
    }
}

int main() {
    int A[] = {194, 234, 5, 2359, 19, 424, 379};
    int n = sizeof(A) / sizeof(A[0]);

    radixSort(A, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
