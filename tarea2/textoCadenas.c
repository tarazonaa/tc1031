#include <stdio.h>
#include <string.h>


int main() {
    char nombre1[100], nombre2[100];
    printf("Nombre 1: ");
    scanf("%s", &nombre1);   
    printf("Nombre 2: ");
    scanf("%s", &nombre2);   

    if (strcmp(nombre1, nombre2) == 0){
        printf("Son iguales");
    } else {
        printf("Son distintos");
    }
}
