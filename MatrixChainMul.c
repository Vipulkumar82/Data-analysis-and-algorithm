#include <stdio.h>
#include <limits.h> 

int main() {
    int n = 5;
    int P[] = {2, 3, 4, 1, 5}; 
    int M[5][5] = {0};
    int S[5][5] = {0}; 
    int i, j, k, d, q, min;

    for (d = 1; d < n - 1; d++) {
        for (i = 1; i < n - d; i++) {
            j = i + d;
            M[i][j] = INT_MAX; 

            for (k = i; k <= j - 1; k++) {
                q = M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j];

                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k; 
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", M[1][n - 1]);

    return 0;
}
