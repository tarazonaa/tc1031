#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct pila {
    int tope;
    int valores[MAX];
};

void inicializacion(struct pila *instancia) {
    instancia->tope = -1;
}

int estaLlena(struct pila *instancia) {
    return instancia->tope == MAX - 1;
}

void push(struct pila *p, int numero) {
    printf("Nuevo elemento en la pila: %d\n", numero);
    if (estaLlena(p)) {
        printf("La pila esta llena");
        return;
    }
    p->tope++;
    p->valores[p->tope] = numero;
}

void pop(struct pila *p) {
    if (p->tope == -1) {
        printf("La pila esta vacia. \n");
        return;
    }
    printf("Numero eliminado: %d\n", p->valores[p->tope]);
    p->valores[p->tope] = 0;
    p->tope--;
}

void mostrarElementos(struct pila *p) {
    printf("Elementos: \n");
    for(int i = p->tope; i >= 0; i--) 
        printf("%d ", p->valores[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct pila pilaMain;
    int n;
    printf("Numero de operaciones por pila: ");
    scanf("%d", &n);
    inicializacion(&pilaMain);
    for (int i = 0; i < n; i++) {
        int n = rand() % 2;
        int num = rand() % 10;
        if(n == 0) {
            printf("Operacion Pop. \n");
            pop(&pilaMain);
        } else if(n == 1) {
            push(&pilaMain, num);
            printf("Operacion Push. \n");
        }
        mostrarElementos(&pilaMain);
    }
    printf("Estado final de la pila: \n");
    mostrarElementos(&pilaMain);
}


