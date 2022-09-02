#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    srand(time(NULL));
    int arr[n][n];
    int suma = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <=n; j++) {
            arr[i][j]=rand() % 10;
            printf("%d ", arr[i][j]);
            if (j > i) {
                suma += arr[i][j];
            }
        }
        printf("\n");
    }
    
    printf("\nSuma de triangular superior %d\n", suma);

}
