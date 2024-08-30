//bucket sorting are used to sort the floating numbers 0.1,0.02  etc.

#include <stdio.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bucketSort(float a[], int n) {
    float B[n][n];
    int bucketCount[n];
    for (int i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bi = n * a[i]; 
        B[bi][bucketCount[bi]] = a[i];
        bucketCount[bi]++;
    }
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(B[i], bucketCount[i]);
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            a[index++] = B[i][j];
        }
    }
}
int main() {
    float a[] = {0.25, 0.09, 0.12, 0.69, 0.15, 0.21, 0.45, 0.62, 0.72, 0.17};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");
    bucketSort(a, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");
    return 0;
}

