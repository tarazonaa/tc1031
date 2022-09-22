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

void pushInicio(int valor) {
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    if (nuevo == NULL) {
        printf("No hay memoria disponible");
    } else {
        nuevo->valor = valor;
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

void pushFinal(int valor) {
    printf("Nuevo elemento: %d", valor);
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    if(nuevo == NULL) {
        printf("No hay memoria disponible!");
        return;
    }
    if(listaVacia()) {
        nuevo->valor = valor;
        nuevo->siguiente = primero;
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

void repeticion(int numero) {
    struct nodo *temp;
    int i = 0;
    int pos = 0;
    temp = primero;
    while(temp != NULL) {
        if(temp->valor == numero) {
            i++;
            printf("Posicion: %d", pos);
        }
        temp = temp->siguiente;
        pos++;
    }
    printf("El numero %d se repite %d veces.", numero, i);
}

void eliminarPares() {
    struct nodo *temp;
    temp = primero;
    while(temp != NULL) {
        if(temp->valor % 2 == 0) {
            printf("Se elimino el nodo: %d", temp->valor);
            eliminarLista(temp->valor);
        }
        temp = temp->siguiente;
    }
}

void eliminarValor(int valor) {
    struct nodo *temp;
    temp = primero;
    while(temp != NULL) {
        if(temp->valor == valor) {
            printf("Se elimino el nodo: %d", temp->valor);
            eliminarLista(temp->valor);
        }
        temp = temp->siguiente;
    }
}

void promedio() {
    struct nodo *temp;
    temp = primero;
    int i = 0;
    int suma = 0;
    while(temp != NULL) {
        suma += temp->valor;
        i++;
        temp = temp->siguiente;
    }
    printf("El promedio de la lista es: %d", suma/i);
}

int main() {
    printf("Uso de una lista ligada: \n");
    printf("Inserciones \n");
    pushFinal(1);
    pushFinal(3);
    pushFinal(5);
    pushFinal(3);
    pushFinal(4);
    pushFinal(5);
    pushFinal(5);
    pushFinal(5);
    pushFinal(5);
    pushFinal(5);
    printf("Inserciones terminadas \n");
    imprimirLista();
    printf("Longitud: \n");
    longitudLista();
    repeticion(3);
    imprimirLista();
    promedio();
    imprimirLista();
    eliminarValor(5);
    imprimirLista();
    printf("\n");
    printf("Eliminacion de un nodo \n");
    eliminarLista(3);
    eliminarLista(4);
    eliminarLista(1);
    imprimirLista();

}
