#include<stdlib.h>
#include<stdio.h>

struct nodo {
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct nodo *primero = NULL;
struct nodo *ultimo = NULL;

void insertar(int valor) {
    struct nodo *nuevo = (struct nodo *) malloc(sizeof(struct nodo));
    nuevo->valor = valor;
    if (primero == NULL) {
        printf("Insertando el primer elemento en la lista circular: %d \n", valor);
        primero = nuevo;
        primero->siguiente = primero;
        primero->anterior = primero;
        ultimo = primero;
        ultimo->siguiente = primero;
        ultimo->anterior = primero;
    } else {
        printf("Insertando un elemento en la lista circular: %d \n", valor);
        ultimo->siguiente = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
        primero->anterior = ultimo;
    }
}

void eliminar(int valor) {
    struct nodo *actual = primero;
    struct nodo *anterior = NULL;
    printf("Eliminando un elemento de la lista circular: %d \n", valor);
    if (primero != NULL) {
        do {
            if (actual->valor == valor) {
                if (actual == primero) {
                    primero = primero->siguiente;
                    primero->anterior = ultimo;
                    ultimo->siguiente = primero;
                } else if (actual == ultimo) {
                    ultimo = anterior;
                    ultimo->siguiente = primero;
                    primero->anterior = ultimo;
                } else {
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = anterior;
                }
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != primero);
    }
}

void eliminarRepetidos(int valor) {
    struct nodo *actual = primero;
    struct nodo *anterior = NULL;
    printf("Eliminando todos los nodos de un elemento de la lista circular: %d \n", valor);
    if (primero != NULL) {
        do {
            if (actual->valor == valor) {
                if (actual == primero) {
                    primero = primero->siguiente;
                    primero->anterior = ultimo;
                    ultimo->siguiente = primero;
                } else if (actual == ultimo) {
                    ultimo = anterior;
                    ultimo->siguiente = primero;
                    primero->anterior = ultimo;
                } else {
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = anterior;
                }
            } 
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != primero);
    }
}

void agregarRepetidos(int valor, int cantidad) {
    while (cantidad > 0) {
        struct nodo *nuevo = (struct nodo *) malloc(sizeof(struct nodo));
        nuevo->valor = valor;
        if (primero == NULL) {
            printf("Insertando el primer elemento en la lista circular: %d \n", valor);
            primero = nuevo;
            primero->siguiente = primero;
            primero->anterior = primero;
            ultimo = primero;
            ultimo->siguiente = primero;
            ultimo->anterior = primero;
        } else {
            printf("Insertando un elemento en la lista circular: %d \n", valor);
            ultimo->siguiente = nuevo;
            nuevo->siguiente = primero;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
            primero->anterior = ultimo;
        }
        cantidad--;
    }
}

void eliminarLista() {
    struct nodo *actual = primero;
    struct nodo *anterior = NULL;
    printf("Eliminando todos los elementos de la lista circular \n");
    if (primero != NULL) {
        do {
            anterior = actual;
            actual = actual->siguiente;
            free(anterior);
        } while (actual != primero);
    }
    primero = NULL;
    ultimo = NULL;
}

void buscarNodo(int valor) {
    struct nodo *actual = primero;
    int encontrado = 0, contador = 0;
    printf("Buscando un elemento en la lista circular: %d \n", valor);
    if (primero != NULL) {
        do {
            contador++;
            if (actual->valor == valor) {
                printf("El elemento %d ha sido encontrado en la lista circular en la posicion %d \n", valor, contador);
                encontrado = 1;
            }
            actual = actual->siguiente;
        } while (actual != primero && encontrado != 1);
        if (encontrado == 0) {
            printf("El elemento %d no ha sido encontrado en la lista circular \n", valor);
        }
    } else {
        printf("La lista circular esta vacia \n");
    }
}

void listaVacia() {
    if (primero == NULL) {
        printf("La lista circular esta vacia \n");
    } else {
        printf("La lista circular no esta vacia \n");
    }
}

void contarNodos() {
    struct nodo *actual = primero;
    int contador = 0;
    printf("Contando los elementos de la lista circular \n");
    if (primero != NULL) {
        do {
            contador++;
            actual = actual->siguiente;
        } while (actual != primero);
        printf("La lista circular tiene %d elementos \n", contador);
    } else {
        printf("La lista circular esta vacia \n");
    }
}

void imprimirLista() {
    struct nodo *actual = (struct nodo *) malloc(sizeof(struct nodo));
    actual = primero;
    if (primero != NULL) {
        do {
            printf("%d \n", actual->valor);
            actual = actual->siguiente;
        } while (actual != primero);
    }
}

int main() {

    insertar(1);
    insertar(2);
    insertar(4);
    insertar(3);
    insertar(4);
    insertar(5);
    imprimirLista();
    agregarRepetidos(6, 3);
    imprimirLista();
    buscarNodo(4);
    contarNodos();
    printf("Eliminar: \n");
    eliminar(3);
    eliminar(1);
    printf("Eliminar repetidos: \n");
    eliminarRepetidos(6);
    imprimirLista();


}
