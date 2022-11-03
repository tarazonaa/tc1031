#include <stdio.h>
#include <stdlib.h>

struct queue {
    int valor;
    struct queue *siguiente;
};

struct queue *primero = NULL;

