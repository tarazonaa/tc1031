#include <stdio.h>

void cambio(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a = 1, b = 2;
    printf("%d %d\n", a, b);
    cambio(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
