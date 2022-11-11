#include<stdlib.h>
#include<stdio.h>

struct nodo {
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct nodo *primero = NULL;
struct nodo *ultimo = NULL;

int longitud() {
    int cont = 0;
    struct nodo *aux = primero;
    if (primero != NULL) {
        do {
            cont++;
            aux = aux->siguiente;
        } while (aux != primero);
    }
    return cont;
}

int listaVacia() {
    if (primero == NULL) {
        printf("La lista esta vacia");
        return 1;
    } else {
        return 0;
    }
}

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
    if(listaVacia())
        printf("No se puede eliminar un elemento de una lista circular vacia");
    struct nodo *actual = primero;
    struct nodo *anterior = actual->anterior;
    struct nodo *siguiente = actual->siguiente;
    struct nodo *temporal = NULL;
    printf("Eliminando un elemento de la lista circular: %d \n", valor);
    while(1) {
        if(actual->valor == valor) {
            if(actual == primero) {
                primero = primero->siguiente;
                primero->anterior = ultimo;
                ultimo->siguiente = primero;
            } else if(actual == ultimo) {
                ultimo = ultimo->anterior;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;
            } else {
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
            }
            temporal = actual;
            actual = actual->siguiente;
            free(temporal);
            break;
        } else {
            anterior = actual;
            actual = actual->siguiente;
            siguiente = actual->siguiente;
        }
    }
}


void imprimirLista() {
    printf("Los elementos en la lista son los siguientes: \n");
    struct nodo *actual = (struct nodo *) malloc(sizeof(struct nodo));
    actual = primero;
    if (primero != NULL) {
        do {
            printf("%d \n", actual->valor);
            actual = actual->siguiente;
        } while (actual != primero);
    }
    printf("\n");
}

void eliminarRepetidos(int valor) {
    if(listaVacia())
        printf("No se puede eliminar un elemento de una lista circular vacia");
    struct nodo *actual = primero;
    struct nodo *anterior = ultimo;
    struct nodo *siguiente = primero->siguiente;
    while(1) {
        struct nodo *temporal = actual;
        if(actual->valor == valor) {
            if(actual == primero) {
                printf("Se elimina el nodo del inicio de la lista: %d \n", actual->valor);
                primero = primero->siguiente;
                primero->anterior = ultimo;
                ultimo->siguiente = primero;
            } else if(actual == ultimo) {
                printf("Se elimina el nodo del final de la lista: %d \n", actual->valor);
                ultimo = ultimo->anterior;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;
            } else {
                printf("Se elimina el nodo del medio de la lista: %d \n", actual->valor);
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
            }
            free(temporal);
            actual = siguiente;
            siguiente = actual->siguiente;
        } else {
            anterior = actual;
            actual = actual->siguiente;
            siguiente = actual->siguiente;
        }
        if(actual == primero)
            break;
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

int sumarPares() {
    struct nodo *actual = primero;
    int suma = 0;
    if (primero != NULL) {
        do {
            if (actual->valor % 2 == 0) {
                suma += actual->valor;
            }
            actual = actual->siguiente;
        } while (actual != primero);
        return suma;
    } else {
        printf("La lista circular esta vacia \n");
        return 0;
    }
}

int contarImpares() {
    struct nodo *actual = primero;
    int contador = 0;
    if (primero != NULL) {
        do {
            if (actual->valor % 2 != 0) {
                contador++;
            }
            actual = actual->siguiente;
        } while (actual != primero);
        return contador;
    } else {
        printf("La lista circular esta vacia \n");
        return 0;
    }
}

int main() {

    insertar(1);
    insertar(2);
    insertar(4);
    insertar(3);
    insertar(4);
    insertar(5);
    printf("\n");
    imprimirLista();
    agregarRepetidos(6, 3);
    printf("\n");
    imprimirLista();
    buscarNodo(4);
    printf("\n");
    printf("La suma de los numeros pares es: %d \n", sumarPares());
    printf("\n");
    printf("Existen %d elementos impares en la lista circular \n", contarImpares());
    printf("\n");
    contarNodos();
    printf("Eliminar: \n");
    eliminar(3);
    eliminar(1);
    printf("\n");
    imprimirLista();
    printf("Eliminar repetidos: \n");
    eliminarRepetidos(6);
    printf("\n");
    imprimirLista();
    eliminarLista();
    listaVacia();


}
