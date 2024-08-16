#include <stdio.h>

void countSort(int a[], int n, int k) {
    int count[k + 1], b[n];
    
    
    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }
 
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }
    
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

int main() {
    int a[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 9;

    countSort(a, n, k);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}