#include <stdio.h>
#include <stdlib.h>

struct queue {
    int valor;
    float weight;
    struct queue *siguiente;
};

struct queue *primero = NULL;

int queueVacio() {
    if(primero == NULL)
        return 1;
    else
        return 0;
}

void insertar(int valor, float weight) {
    struct queue *nuevo = (struct queue *) malloc(sizeof(struct queue));
    nuevo->valor = valor;
    nuevo->weight = weight;
    if (queueVacio()) {
        primero = nuevo;
        primero->siguiente = NULL;
    } else {
        struct queue *aux = primero;
        while (aux->siguiente->weight < weight) {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
}

void imprimir() {
    struct queue *aux = primero;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->siguiente;
    }
}

int main() {
    insertar(1, 1.0);
    insertar(2, 2.0);
    insertar(3, 3.0);
    imprimir();
}
