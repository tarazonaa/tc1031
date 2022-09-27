#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz = NULL;

void insertarNodo(int numero) {
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->valor = numero;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    printf("Se insertó el nodo %d", numero);
    if(raiz == NULL) {
        raiz = nuevo;
    } else {
        struct nodo *actual = raiz;
        struct nodo *anterior = NULL;
        while(actual != NULL) {
            anterior = actual;
            if(numero < actual->valor)
                actual = actual->izquierda;
            else
                actual = actual->derecha;
        }
        if (numero < anterior->valor)
            anterior->izquierda = nuevo;
        else
            anterior->derecha = nuevo;
    }
}

void borrarArbol(struct nodo *elemento) {
    if(elemento != NULL) {
        borrarArbol(elemento->izquierda);
        borrarArbol(elemento->derecha);
        free(elemento);
    }
}

void recorridoPreOrder(struct nodo *elemento) {
    if(elemento != NULL) {
        printf("%d ", elemento->valor);
        recorridoPreOrder(elemento->izquierda);
        recorridoPreOrder(elemento->derecha);
    }
}

void recorridoInOrder(struct nodo *elemento) {
    if(elemento != NULL) {
        recorridoPreOrder(elemento->izquierda);
        printf("%d ", elemento->valor);
        recorridoPreOrder(elemento->derecha);
    }
}

void recorridoPostOrder(struct nodo *elemento) {
    if(elemento != NULL) {
        recorridoPreOrder(elemento->izquierda);
        recorridoPreOrder(elemento->derecha);
        printf("%d ", elemento->valor);
    }
}

int main() {

}
