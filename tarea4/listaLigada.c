#include <stdlib.h>
#include <stdio.h>

struct nodo {
    int valor;
    struct nodo *siguiente;
};

struct nodo *primero = NULL;

int listaVacia() {
    if(primero == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void longitudLista() {
    struct nodo *temp;
    int i = 0;
    temp = primero;
    while(temp != NULL) {
        i++;
        temp = temp->siguiente;
    }
    printf("La longitud de la lista es: %d", i);
}

void pushFinal(int valor) {
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    if(nuevo == NULL) {
        printf("No hay memoria disponible!");
        return;
    }
    if(listaVacia()) {
        nuevo->valor = valor;
        nuevo->siguiente = NULL;
        primero = nuevo;
        return;
    }  
    struct nodo *actual;
    struct nodo *anterior;
    while(actual != NULL) {
        anterior = actual;
        actual = actual->siguiente;
    }
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    anterior->siguiente = nuevo;
}

void eliminarLista(int numero) {
    if (listaVacia()) {
        printf("La lista ya esta vacia.");
        return;
    }
    struct nodo *actual;
    struct nodo *anterior;
    struct nodo *temp;
    while(actual != NULL) {
        if(actual->valor == numero) {
            if(anterior == NULL) {
                temp = actual;
                actual = actual->siguiente;
                printf("Se elimino el nodo: %d", temp->valor);
                free(temp);
                return;
            } else {
                temp = actual;
                printf("Se elimino el nodo: %d", temp->valor);
                anterior->siguiente = actual->siguiente;
                free(temp);
                return;
            }
        }
    }
    printf("No se encontro el nodo %d.", numero);
}

void imprimirLista() {
    struct nodo *temp;
    printf("Elementos en la lista:\n");
    while(temp != NULL) {
        printf("%d", temp->valor);
        temp = temp->siguiente;
    }
}

int main() {
    printf("Uso de una lista ligada: \n");
    printf("Inserciones \n");
    pushFinal(1);
    pushFinal(2);
    pushFinal(3);
    pushFinal(4);
    pushFinal(5);
    imprimirLista();
    printf("Longitud: \n");
    longitudLista();
    printf("\n");
    printf("Eliminacion de un nodo \n");
    eliminarLista(3);
    eliminarLista(4);
    eliminarLista(1);
    imprimirLista();

}
