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
    return c->frente == c->atras;
}

int colaLlena(struct cola *c) {
    return c->atras == MAX;
}

void queue(struct cola *c, int numero) {
    if (colaLlena(c)) {
        printf("Cola llena.\n");
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
    for (int i = 0; i < MAX; i++) {
        num = (rand() % 5) + 1;
        queue(&c, num);
    }
    mostrarElementos(&c);
    for (int i = 0; i < MAX; i++) {
        c.valores[i] = c.valores[i] * c.valores[i];
    }
    mostrarElementos(&c);
}
