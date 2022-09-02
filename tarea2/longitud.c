#include <stdio.h>

int main() {
    char str[100];
   int suma = 0, i=0;
    printf("Cadena de texto: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        printf("%c\n", str[i]);
        i++;
        suma++;
    }
    printf("\n%d", suma);
}
