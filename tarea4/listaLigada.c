#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo {
  int valor;
  struct nodo *siguiente;
};

struct nodo *primero = NULL;

int listaVacia() {
  if (primero == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void longitudLista() {
  struct nodo *temp;
  int i = 0;
  temp = primero;
  while (temp != NULL) {
    i++;
    temp = temp->siguiente;
  }
  printf("La longitud de la lista es: %d \n", i);
}

void pushInicio(int numero) {
  struct nodo *nuevo = malloc(sizeof(struct nodo));
  if (nuevo == NULL) {
    printf("No hay memoria disponible");
  } else {
    nuevo->valor = numero;
    nuevo->siguiente = primero;
    primero = nuevo;
  }
}

void pushFinal(int numero) {
  printf("Nuevo elemento: %d \n", numero);
  struct nodo *nuevo = malloc(sizeof(struct nodo));
  if (nuevo == NULL) {
    printf("No hay memoria disponible! \n");
    return;
  }
  if (listaVacia() == 1) {
    nuevo->valor = numero;
    nuevo->siguiente = primero;
    primero = nuevo;
    return;
  }
  struct nodo *actual = primero;
  struct nodo *anterior = NULL;
  while (actual != NULL) {
    anterior = actual;
    actual = actual->siguiente;
  }
  nuevo->valor = numero;
  nuevo->siguiente = NULL;
  anterior->siguiente = nuevo;
}

void eliminarLista(int numero) {
  if (listaVacia()) {
    printf("La lista ya esta vacia.");
    return;
  }
  struct nodo *actual = primero;
  struct nodo *anterior = NULL;
  struct nodo *temp;
  int i = 0;
  while (actual != NULL) {
    if (actual->valor == numero) {
      if (anterior == NULL) {
        temp = actual;
        primero = actual->siguiente;
        printf("Se elimino el nodo: %d \n", temp->valor);
        free(temp);
        return;
      } else {
        temp = actual;
        anterior->siguiente = actual->siguiente;
        printf("Se elimino el nodo: %d \n", temp->valor);
        free(temp);
        return;
      }
    }
    anterior = actual;
    actual = actual->siguiente;
    i++;
  }
  printf("No se encontro el nodo %d. \n", numero);
}

void imprimirLista() {
  struct nodo *temp = primero;
  printf("Elementos en la lista:\n");
  while (temp != NULL) {
    printf("%d \n", temp->valor);
    temp = temp->siguiente;
  }
}

void repeticion(int numero) {
  struct nodo *temp;
  int i = 0;
  int pos = 0;
  temp = primero;
  while (temp != NULL) {
    if (temp->valor == numero) {
      i++;
      printf("Posicion: %d \n", pos);
    }
    temp = temp->siguiente;
    pos++;
  }
  printf("El numero %d se repite %d veces. \n", numero, i);
}

void eliminarPares() {
  struct nodo *actual = primero;
  struct nodo *anterior = NULL;
  while (actual != NULL) {
    struct nodo *temp = actual;
    if ((actual->valor % 2) == 0) {
      if (anterior == NULL) {
        primero = actual->siguiente;
        free(temp);
        actual = primero;
      } else if (anterior != NULL && actual->siguiente != NULL) {
        anterior->siguiente = actual->siguiente;
        free(temp);
        actual = anterior->siguiente;
      } else if (anterior != NULL && actual->siguiente == NULL) {
        anterior->siguiente = NULL;
        free(temp);
        actual = NULL;
      }
    } else {
      anterior = actual;
      actual = actual->siguiente;
    }
  }
}

void promedio() {
  struct nodo *temp;
  temp = primero;
  float i = 0;
  float suma = 0;
  while (temp != NULL) {
    suma += temp->valor;
    i++;
    temp = temp->siguiente;
  }
  printf("El promedio de la lista es: %.2f \n", suma / i);
}

void eliminarOcurrencias(int numero) {
  struct nodo *actual = primero;
  struct nodo *anterior = NULL;
  while (actual != NULL) {
    struct nodo *temp = actual;
    if (actual->valor == numero) {
      if (anterior == NULL) {
        primero = actual->siguiente;
        free(temp);
        actual = primero;
      } else if (anterior != NULL && actual->siguiente != NULL) {
        anterior->siguiente = actual->siguiente;
        free(temp);
        actual = anterior->siguiente;
      } else if (anterior != NULL && actual->siguiente == NULL) {
        anterior->siguiente = NULL;
        free(temp);
        actual = NULL;
      }
    } else {
      anterior = actual;
      actual = actual->siguiente;
    }
  }
}

int main() {
    srand(time(NULL));
  printf("Uso de una lista ligada: \n");
  printf("Inserciones \n");
  for (int i = 0; i < 10; i++) {
    pushFinal(rand() % 10);
  }
  printf("Inserciones terminadas \n");
  imprimirLista();
  printf("Longitud: \n");
  longitudLista();
  printf("Repetici??n: \n");
  repeticion(3);
  imprimirLista();
  promedio();
  imprimirLista();
  printf("\n");
  printf("Eliminacion de un nodo \n");
  eliminarLista(3);
  eliminarLista(4);
  eliminarLista(1);
  imprimirLista();
  printf("Insercion al inicio \n");
  for (int i = 0; i < 10; i++) {
    pushInicio(rand() % 10);
  }
  imprimirLista();
  printf("Eliminacion de pares \n");
  eliminarPares();
  imprimirLista();
  printf("Eliminacion de 5 \n");
  eliminarOcurrencias(5);
  imprimirLista();
}
