#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo *siguiente;
    struct nodo *previo;
};

struct nodo *inicio = NULL;
struct nodo *fin = NULL;

int listaVacia() {
    if (inicio == NULL && fin == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int longitudLista() {
    struct nodo *temp;
    int longitud = 0;
    temp = inicio;
    while (temp != NULL) {
        longitud++;
        temp = temp->siguiente;
    }
    return longitud;
}

void push(int numero) {
    struct nodo *nuevo = malloc(sizeof (struct nodo));
    if (nuevo == NULL) {
        printf("No hay memoria disponible!");
    }

    if(listaVacia()) {
        nuevo->valor = numero;
        inicio = nuevo;
        fin = nuevo;
        nuevo->siguiente = NULL;
        nuevo->previo = NULL;
    } else {
        nuevo->valor = numero;
        nuevo->siguiente = NULL;
        nuevo->previo = fin;
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

void insertarInicioLista(int numero){
    struct nodo *nuevo = malloc(sizeof (struct nodo));

    if (nuevo == NULL) {
        printf("No hay memoria disponible!");
    }

    if(listaVacia()) {
        nuevo->valor = numero;
        inicio = nuevo;
        fin = nuevo;
        nuevo->siguiente = NULL;
        nuevo->previo = NULL;
    } else {
        nuevo->valor = numero;
        nuevo->siguiente = inicio;
        nuevo->previo = NULL;
        inicio->previo=nuevo;
        inicio = nuevo;

    }
}

void eliminarLista(int numero) {
    struct nodo *anterior = NULL;
    struct nodo *actual = inicio;
    struct nodo *siguiente = inicio->siguiente;
    struct nodo *temp;

    while(actual != NULL) {
        if (actual->valor == numero) {
            if(anterior == NULL && siguiente == NULL) {
                temp = actual;
                inicio = inicio->siguiente;
                inicio->previo = NULL;
                printf("Eliminando %d", temp->valor);
                free(temp);
                return;
            } 

        }

    }

    
}


int main() {

}
