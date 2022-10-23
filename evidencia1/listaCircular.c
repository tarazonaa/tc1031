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
        primero = nuevo;
        primero->siguiente = primero;
        primero->anterior = primero;
        ultimo = primero;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
        primero->anterior = ultimo;
    }
}

int main() {


}
