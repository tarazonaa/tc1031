#include <stdio.h>
#include <stdlib.h>

struct queue {
    int valor;
    int weight;
    struct queue *siguiente;
};

struct queue *tope = NULL;

int queueVacio() {
    if(tope == NULL)
        return 1;
    else
        return 0;
}

void push(int valor, int weight) {
    struct queue *nuevo = malloc(sizeof(struct queue));
    if (nuevo == NULL)
        printf("No hay memoria disponible");
    nuevo->valor = valor;
    nuevo->weight = weight;
    nuevo->siguiente = NULL;
    if (queueVacio())
        tope = nuevo;
    else {
        if(weight >= tope->weight) {
            nuevo->siguiente = tope;
            tope = nuevo;
        }
        else {
            struct queue *aux = tope;
            while (aux->siguiente != NULL && weight < aux->siguiente->weight)
                aux = aux->siguiente;
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    printf("Metiendo el numero %d con peso %d \n", valor, weight);
}

void pop() {
    if (queueVacio())
        printf("La cola esta vacia");
    else {
        printf("Sacando el numero %d con peso %d \n", tope->valor, tope->weight);
        struct queue *aux = tope;
        tope = tope->siguiente;
        free(aux);
    }
}

void imprimir() {
    struct queue *aux = tope;
    printf("La lista contiene los siguientes elementos: \n");
    while (aux != NULL) {
        printf("%d con peso %d \n", aux->valor, aux->weight);
        aux = aux->siguiente;
    }
}

int main() {
    push(1, 1);
    push(2, 2);
    push(3, 4);
    push(3, 3);
    push(5, 4);
    imprimir();
    pop();
    imprimir();
}
