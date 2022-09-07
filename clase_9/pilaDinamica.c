#include <stdlib.h>
#include <stdio.h>

struct nodo {
    int valor;
    struct nodo *siguiente;
};

struct nodo *tope = NULL;

int pilaVacia() {
    if(tope == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(int numero) {
    printf("Nuevo elemento en la lista: %d\n", numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL) {
        printf("No hay memoria disponible!");
        return;
    }
    elemento->valor = numero;
    elemento->siguiente = tope;
    tope = elemento;
}

int pop() {
    if(pilaVacia()) {
        printf("La pila esta vacia");
        return -1;
    }
    struct nodo *elemento = tope;
    int valor = elemento->valor;
    tope = elemento->siguiente;
    free(elemento);
    return valor;
}

void mostrarElementos() {
    int i = 0;
    struct nodo *temporal = tope;
    while(temporal != NULL) {
        printf("Elemento[%d] %d\n", i, temporal->valor);
        temporal = temporal->siguiente;
        i++;
    }
}

int main() {

}
