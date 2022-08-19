#include <stdio.h>

// Decorators 
int suma(int a, int b);

int main() {
    printf("%d\n", suma(5,8));
    return 0;
}

int suma(int a, int b) {
    return a + b;
}
