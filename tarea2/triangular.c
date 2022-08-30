#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            arr[i][j]=rand() % 10;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int suma = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i); j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n%d", suma);

}
