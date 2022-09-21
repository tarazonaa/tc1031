#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6

struct cola {
    int frente;
    int atras;
    int valores[MAX];
};

void inicializar(struct cola *c) {
    c->frente = 0;
    c->atras = 0;
}

int colaVacia(struct cola *c) {
    if (c->frente == c->atras ) {
        printf("La cola esta vacia. \n");
        return 1;
    } else {
        return 0;
    }
}

int colaLlena(struct cola *c) {
    if (c->atras == MAX) {
        printf("La cola esta llena. \n");
        return 1;
    } else {
        return 0;
    }
}

void queue(struct cola *c, int numero) {
    printf("Nuevo elemento en la cola: %d\n", numero);
    if (colaLlena(c)) {
        return;
    }
    c->valores[c->atras] = numero;
    c->atras++;
}

void dequeue(struct cola *c) {
    if(colaVacia(c)) {
        printf("Cola vacia.\n");
        return;
    }
    for(int i = 0; i < c->atras; i++) {
        printf("Quitando el numero %d \n", c->valores[i]);
        c->valores[i] = c->valores[i+1];
    }
}

void cuadrar(struct cola *c) {
    for (int i = 0; i <= MAX; i++) {
        c->valores[i] = c->valores[i] * c->valores[i];
    }
}

void mostrarElementos(struct cola *c) {
    if(colaVacia(c)) {
        printf("Cola vacia.\n");
        return;
    }
    for (int i = 0; i < c->atras; i++) {
        printf("Elemento %d: %d\n", i, c->valores[i + 1]);
    }
}

int main() {
    srand(time(NULL));
    int num = 0;
    struct cola c;
    inicializar(&c);
    for (int i = 0; i < MAX; i++) {
        num = (rand() % 5) + 1;
        queue(&c, num);
    }
    printf("Elementos de la cola: \n");
    mostrarElementos(&c);
    cuadrar(&c);
    printf("Elementos cuadrados de la cola: \n");
    mostrarElementos(&c);
}
