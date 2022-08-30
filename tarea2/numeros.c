#include <stdio.h>

int main() {
    int arr[5];
    int numero;
    for (int i = 0; i<5; i++) {
        printf("Digite numero %d: ", i+1);
        scanf("%d", &numero);
        arr[i] = numero * 2;
    }
    for (int i = 0; i<5; i++) {
        printf("%d\n", arr[i]);
    }
}
