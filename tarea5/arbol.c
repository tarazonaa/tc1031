#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int valor;
  struct nodo *izq;
  struct nodo *der;
};

struct nodo *raiz = NULL;

void insertarNodo(int numero) {
  struct nodo *nuevo = malloc(sizeof(struct nodo));
  nuevo->valor = numero;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  printf("Se inserta el nodo con el valor %d \n", numero);

  if (raiz == NULL) {
    raiz = nuevo;
  } else {
    struct nodo *anterior = NULL;
    struct nodo *actual = raiz;
    while (actual != NULL) {
      anterior = actual;
      if (numero < actual->valor) {
        actual = actual->izq;
      } else {
        actual = actual->der;
      }
    }
    if (numero < anterior->valor) {
      anterior->izq = nuevo;
    } else {
      anterior->der = nuevo;
    }
  }
}

void borrarArbol(struct nodo *elemento) {
  if (elemento != NULL) {
    printf("Elemento %d eliminado \n", elemento->valor);
    borrarArbol(elemento->izq);
    borrarArbol(elemento->der);
    free(elemento);
  }
}

void preOrder(struct nodo *elemento) {
  if (elemento != NULL) {
    printf("%d ", elemento->valor);
    preOrder(elemento->izq);
    preOrder(elemento->der);
  }
}

void inOrder(struct nodo *elemento) {
  if (elemento != NULL) {
    inOrder(elemento->izq);
    printf("%d ", elemento->valor);
    inOrder(elemento->der);
  }
}

void postOrder(struct nodo *elemento) {
  if (elemento != NULL) {
    postOrder(elemento->izq);
    postOrder(elemento->der);
    printf("%d ", elemento->valor);
  }
}

struct nodo *nodoMenor(struct nodo *elemento) {
  struct nodo *actual = elemento;
  while (actual && actual->izq != NULL) {
    actual = actual->izq;
  }
  return actual;
}

struct nodo *borrarNodo(struct nodo *inicio, int valor) {
  if (inicio == NULL) {
    return inicio;
  }
  if (valor < inicio->valor)
    inicio->izq = borrarNodo(inicio->izq, valor);

  else if (valor > inicio->valor)
    inicio->der = borrarNodo(inicio->der, valor);

  else {
    printf("Se borra el nodo con el valor %d del arbol. \n", valor);
    if (inicio->izq == NULL) {
      struct nodo *temp = inicio->der;
      free(inicio);
      return temp;
    } else if (inicio->der == NULL) {
      struct nodo *temp = inicio->izq;
      free(inicio);
      return temp;
    }
    struct nodo *temp = nodoMenor(inicio->der);
    inicio->valor = temp->valor;
    inicio->der = borrarNodo(inicio->der, temp->valor);
  }
  return inicio;
}

int nodeCount(struct nodo *inicio) {
  if (inicio == NULL) {
    return 0;
  } else {
    return 1 + nodeCount(inicio->izq) + nodeCount(inicio->der);
  }
}

int sumaPares(struct nodo *inicio) {
  if (inicio == NULL) {
    return 0;
  } else {
    if (inicio->valor % 2 == 0)
      return inicio->valor + sumaPares(inicio->izq) + sumaPares(inicio->der);
    else
      return sumaPares(inicio->izq) + sumaPares(inicio->der);
  }
}

int sumaImpares(struct nodo *inicio) {
  if (inicio == NULL) {
    return 0;
  } else {
    if (inicio->valor % 2 != 0)
      return inicio->valor + sumaImpares(inicio->izq) + sumaImpares(inicio->der);
    else
      return sumaImpares(inicio->izq) + sumaImpares(inicio->der);
  }
}

void nodoHoja(struct nodo *inicio) {
  if (inicio == NULL) {
    return;
  } else {
    if (inicio->izq == NULL && inicio->der == NULL) {
      printf("%d ", inicio->valor);
    }
    nodoHoja(inicio->izq);
    nodoHoja(inicio->der);
  }
}


/* int nivel(struct nodo *inicio, int valor) {
    if (inicio == NULL) {
        return 0;
    } else {
        if (inicio->valor == valor) {
            return 1;
        } else {
            int izq = nivel(inicio->izq, valor);
            int der = nivel(inicio->der, valor);
            if (izq > der) {
                return izq + 1;
            } else {
                return der + 1;
            }
        }
    }
}
*/
int altura(struct nodo *inicio) {
    if (inicio == NULL) {
        return 0;
    } else {
        int izq = altura(inicio->izq);
        int der = altura(inicio->der);
        if (izq > der) {
            return izq + 1;
        } else {
            return der + 1;
        }
    }
}

void imprimirNivel(struct nodo *inicio, int nivel) {
    if (inicio == NULL) {
        return;
    } else {
        if (nivel == 1) {
            printf("%d ", inicio->valor);
        } else {
            imprimirNivel(inicio->izq, nivel - 1);
            imprimirNivel(inicio->der, nivel - 1);
        }
    }
}

void imprimirNiveles(struct nodo *inicio) {
    int h = altura(inicio);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(inicio, i);
    }
}
/*
void busquedaAnchura(struct nodo *inicio, int nivel) {
    if (inicio == raiz) {
        printf("%d ", inicio->valor);
    }
    if (inicio == NULL) 
        return;
    if(nivel == 1){
        return;
    } else if (nivel > 1) {
        if (inicio->izq != NULL) 
            printf("%d ", inicio->izq->valor);
        if (inicio->der != NULL) 
            printf("%d ", inicio->der->valor);
        busquedaAnchura(inicio->izq, nivel - 1);
        busquedaAnchura(inicio->der, nivel - 1);
    } else {
        return;
    }
}
*/
int main() {
  printf("ARBOL BINARIO: \n");
  printf("Insertando valores: \n");
  insertarNodo(10);
  insertarNodo(9);
  insertarNodo(8);
  insertarNodo(5);
  insertarNodo(15);
  insertarNodo(3);
  insertarNodo(4);
  insertarNodo(5);
  insertarNodo(6);
  insertarNodo(7);
  insertarNodo(12);
  insertarNodo(18);
  insertarNodo(19);
  insertarNodo(21);
  insertarNodo(22);
  printf("Raiz: %d\n", raiz->valor);
  printf("Operacion anchura: \n");
  imprimirNiveles(raiz);
  printf("\n");
  printf("Operacion preorden: \n");
  preOrder(raiz);
  printf("\n");
  printf("Operacion inorden: \n");
  inOrder(raiz);
  printf("\n");
  printf("Operacion postorden: \n");
  postOrder(raiz);
  printf("\n");
  printf("Nodos pares: %d \n", sumaPares(raiz));
  printf("Nodos impares: %d \n", sumaImpares(raiz));
  printf("Nodos: %d\n", nodeCount(raiz));
  printf("Nodos hoja: \n");
  nodoHoja(raiz);
  printf("\n");
  printf("Operacion eliminar: \n");
  borrarNodo(raiz, 10);
  borrarNodo(raiz, 15);
  borrarNodo(raiz, 5);
  inOrder(raiz);
}
