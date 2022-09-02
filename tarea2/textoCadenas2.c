#include <stdio.h>

int main() {
    char texto1[20], texto2[20];
    printf("Ingrese texto 1: ");
    scanf("%s", texto1);
    printf("Ingrese texto 2: ");
    scanf("%s", texto2);
    int i = 0, flag = 0;
    while (texto1[i] != '\0' && texto2[i] != '\0') {
        if (texto1[i] != texto2[i]) {
            flag += 1;
            break;
        }
        i++;
    }
    if (flag == 0) {
        printf("Son iguales \n");
    } else {
        printf("Son diferentes \n");
    }
}
