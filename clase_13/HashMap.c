#include <stdio.h>
#include <stdlib.h>

struct hash {
    int valor;
    int llave;
};

struct hash *tabla;
int capacidad = 10;
int longitud = 0;

void inicializarTabla() {
    printf("Inicializando tabla. \n");
    tabla = malloc(capacidad * sizeof(struct hash));
    for (int i = 0; i < capacidad; i++) {
        tabla[i].valor = 0;
        tabla[i].llave = 0;
    }
}

int funcionHash(int llave) {
    return llave % capacidad;
}

void insertar(int llave, int valor) {
    int indice = funcionHash(llave);
    if (tabla[indice].llave == 0) {
        tabla[indice].llave = llave;
        tabla[indice].valor = valor;
        longitud++;
        printf("Insertado: %d, %d \n", llave, valor);
    } else if (tabla[indice].llave == llave) {
        tabla[indice].valor = valor;
    } else {
        printf("No se puede insertar: %d, %d \n", llave, valor);
    }
}

void eliminar(int llave) {
    int indice = funcionHash(llave);
    if (tabla[indice].llave == 0) {
        printf("No se puede eliminar: %d \n", llave);
    } else {
        printf("Eliminado: %d \n", tabla[indice].valor);
        tabla[indice].llave = 0;
        tabla[indice].valor = 0;
        longitud--;
    }
}

void mostrar() {
    for(int i = 0; i < capacidad; i++) {
        if (tabla[i].llave == 0) {
            printf("NULL \t");
        } else {
            printf("%d \t", tabla[i].valor);
        }
    }
}

void eliminarHash() {
    free(tabla);
    return;
}

int main() {

}
