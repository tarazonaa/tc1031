#include <stdio.h>
#include <stdlib.h>

//Definicion de la estructura del nodo en la lista
struct nodo {
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

//Elemento que apunta parte inicial de la lista
struct nodo *inicio = NULL;

//ELemento que apunta final de la lista
struct nodo *fin = NULL;

//Verifica si la lista esta vacia
int listaVacia() {
    if (inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}



//Inserta un elemento a la lista circular
void insertaElemento(int numero) {
    printf("Nuevo elemento la lista: %d \n",numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL) {
    printf("NO se puede crear un elemento en la lista");
    return;
        
    }
    if (listaVacia()==1){
        elemento->valor=numero;
        inicio=elemento;
        inicio->siguiente=inicio;
        inicio->anterior=inicio;
        fin=inicio;
        fin->siguiente=inicio;
        fin->anterior=inicio;
    }
    else{
        elemento->valor=numero;
        fin->siguiente=elemento;
        fin=elemento;
        fin->siguiente=inicio;
        inicio->anterior=fin;
    }
}

//Devuelve la longitud de la lista
void mostrar() {
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *temporal;
    int i= 0;
    temporal = inicio;
    if(inicio!=NULL){
        do {
            printf("Elemento[%d]=%d\n" ,i, temporal->valor);
            i++;
            temporal = temporal->siguiente;
        }while(temporal != inicio);
    }
}

//Insertar multiples valores a un arreglo
void insertarMultiple(int valores[], int numElementos){
    int i;
    for(i=0;i<numElementos;i++){
        printf("Nuevo elemento la lista: %d \n",valores[i]);
        struct nodo *elemento = malloc(sizeof(struct nodo));
        if (elemento == NULL) {
        printf("NO se puede crear un elemento en la lista");
        return;
            
        }
        if (listaVacia()==1){
            elemento->valor=valores[i];
            inicio=elemento;
            inicio->siguiente=inicio;
            inicio->anterior=inicio;
            fin=inicio;
            fin->siguiente=inicio;
            fin->anterior=inicio;
        }
        else{
            elemento->valor=valores[i];
            fin->siguiente=elemento;
            fin=elemento;
            fin->siguiente=inicio;
            inicio->anterior=fin;
        }
    }
}

//Eliminar un elemento de una lista
void eliminaLista(int numero){
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *indiceAnterior=inicio->anterior;
    struct nodo *indiceActual=inicio;
    struct nodo *indiceSiguiente=inicio->siguiente;
    struct nodo *temporal;
    do{
        if (indiceActual->valor==numero){
            //Primer elemento en la lista
            if(indiceActual==inicio){
                temporal=indiceActual;
                inicio=indiceActual->siguiente;
                inicio->anterior=fin;
                fin->siguiente=inicio;
                printf("Eliminando %d\n", temporal->valor);
                free(temporal);
                return;
            }
            //Elemento a eliminar va en medio o al final de la lista
            else if(indiceActual==fin){
                temporal=indiceActual;
                printf("Eliminando %d\n",temporal->valor);
                
                indiceAnterior->siguiente=inicio;
                fin=indiceAnterior;
                fin->siguiente=inicio;
                inicio->anterior=fin;
                free(temporal);
                return;
                }
            else{
                temporal=indiceActual;
                printf("Eliminando %d\n",temporal->valor);
                indiceAnterior->siguiente=indiceSiguiente;
                indiceSiguiente->anterior=indiceAnterior;
                free(temporal);
                return;
            }
           
            }
        indiceAnterior=indiceActual;
        indiceActual=indiceActual->siguiente;
        indiceSiguiente=indiceSiguiente->siguiente;
 
    }while(indiceActual!=inicio);
    printf("Elemento: %d no se puede eliminar", numero);
}

void eliminarRepetidos(int numero){
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *indiceAnterior=inicio->anterior;
    struct nodo *indiceActual=inicio;
    struct nodo *indiceSiguiente=inicio->siguiente;
    struct nodo *temporal;
    do{
        if (indiceActual->valor==numero){
            //Primer elemento en la lista
            if(indiceActual==inicio){
                temporal=indiceActual;
                inicio=indiceActual->siguiente;
                inicio->anterior=fin;
                fin->siguiente=inicio;
                printf("Eliminando %d\n", temporal->valor);
                free(temporal);

            }
            //Elemento a eliminar va en medio o al final de la lista
            else if(indiceActual==fin){
                temporal=indiceActual;
                printf("Eliminando %d\n",temporal->valor);
                
                indiceAnterior->siguiente=inicio;
                fin=indiceAnterior;
                fin->siguiente=inicio;
                inicio->anterior=fin;
                free(temporal);
    
                }
            else{
                temporal=indiceActual;
                printf("Eliminando %d\n",temporal->valor);
                indiceAnterior->siguiente=indiceSiguiente;
                indiceSiguiente->anterior=indiceAnterior;
                free(temporal);
        
            }
            indiceAnterior=indiceActual;
            indiceActual=indiceActual->siguiente;
            indiceSiguiente=indiceSiguiente->siguiente;
            }
        indiceAnterior=indiceActual;
        indiceActual=indiceActual->siguiente;
        indiceSiguiente=indiceSiguiente->siguiente;
    }while(indiceActual!=inicio);
}

void longitud(){
    int i=0;
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *temporal;
    temporal=inicio;
    if(inicio!=NULL){
        do{
            i++;
            temporal=temporal->siguiente;
        }while(inicio!=temporal);
    }
    printf("La longitud de la lista es: %d\n", i);
}

void buscarNodo(int numero){
    int pos =0;
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *temporal;
    temporal=inicio;
    if(inicio!=NULL){
        do{
            if(temporal->valor==numero){
                printf("El nodo %d se encuentra en la posición %d\n", numero,pos);
            }
            temporal=temporal->siguiente;
            pos++;
        }while(temporal!=inicio);
    }
}

void eliminarTodo(){
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo *indiceAnterior=NULL;
    struct nodo *indiceActual=inicio;
    if(inicio!=NULL){
        do{
            indiceAnterior=indiceActual;
            indiceActual=indiceActual->siguiente;
            printf("Eliminando %d\n", indiceAnterior->valor);
            free(indiceAnterior);

        }while(indiceActual!=inicio);
                
        }
    inicio=NULL;
    fin=NULL;
        }
    

void reemplazar(int numero, int pos){
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    int i=0;
    int x=0;
    struct nodo *temporal;
    temporal=inicio;
    if(inicio!=NULL){
        do{
            temporal=temporal->siguiente;
            i++;
        }while(inicio!=temporal);
    }
    if (pos>i && pos<0){
        printf("La posición es inválida\n");
        return;
    }
    else{
        if(inicio!=NULL){
            do{
                temporal=temporal->siguiente;
                x++;
                if(x==pos){
                    printf("Número %d en la posición %d ha sido reemplazado por %d\n", temporal->valor, pos,numero);
                    temporal->valor=numero;
                }
            }while(temporal!=inicio);
        }
    }
}

void parynon(){
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    printf("Los números pares y nones son: \n");
    struct nodo *temporal;
    temporal=inicio;
    if(inicio!=NULL){
        do{
            if(temporal->valor%2==0){
                printf("El nodo %d es par\n", temporal->valor);
            }
            else{
                printf("El nodo %d es non\n", temporal->valor);
            }
            temporal=temporal->siguiente;
            
        }while(inicio!=temporal);
    }
}

void acomodarMenor()
{
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo* indiceAnterior = inicio;
    struct nodo* indiceSiguiente = inicio;
    int num;
    printf("Acomodando números de menor a mayor\n");
 
    do {
        indiceSiguiente = indiceAnterior->siguiente;
        while(indiceSiguiente != inicio)
        {
            if (indiceAnterior->valor > indiceSiguiente->valor)
            {
                num = indiceAnterior->valor;
                indiceAnterior->valor = indiceSiguiente->valor;
                indiceSiguiente->valor = num;
            }
           
            indiceSiguiente = indiceSiguiente->siguiente;
            
        }
        indiceAnterior = indiceAnterior->siguiente;
    }while (indiceAnterior->siguiente != inicio);
}
void acomodarMayor()
{
    if (listaVacia()==1){
        printf("La lista esta vacia\n");
        return;
    }
    struct nodo* indiceAnterior = inicio;
    struct nodo* indiceSiguiente = inicio;
    int num;
    printf("Acomodando números de mayor a menor\n");
    do {
        indiceSiguiente = indiceAnterior->siguiente;
        while(indiceSiguiente != inicio)
        {
            if (indiceAnterior->valor < indiceSiguiente->valor)
            {
                num = indiceAnterior->valor;
                indiceAnterior->valor = indiceSiguiente->valor;
                indiceSiguiente->valor = num;
            }
           
            indiceSiguiente = indiceSiguiente->siguiente;
            
        }
        indiceAnterior = indiceAnterior->siguiente;
    }while (indiceAnterior->siguiente != inicio);
}

void main(){
    printf("Uso de una lista circlar doblemente ligada\n\n");
    printf("Operaciones \'insercion\"\n");
    insertaElemento(6);
    insertaElemento(4);
    insertaElemento(5);
    insertaElemento(6);
    insertaElemento(1);
    insertaElemento(2);
    insertaElemento(3);
    insertaElemento(6);
    insertaElemento(6);
    int valores[]={10,11,12,6,7};
    insertarMultiple(valores,5);
    mostrar();
    eliminaLista(4);
    eliminaLista(12);
    eliminaLista(3);
    eliminarRepetidos(6);
    mostrar();
    longitud();
    insertaElemento(5);
    mostrar();
    buscarNodo(5);
    reemplazar(9, 5);
    mostrar();
    acomodarMayor();
    mostrar();
    acomodarMenor();
    mostrar();
    parynon();
    eliminarTodo();
    mostrar();
}
