
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void imprimir(lista * listaTrabajo) {

    int i=0;
    nodo * aux= listaTrabajo->pri;

    if(aux==NULL){
        printf("la lista esta vacia\n");
    }

    for(;aux!=NULL;aux=aux->sig){

        printf("%d:el codigo es: %d\n",i+1, aux->cod);
        i++;

    }
}


lista * newlist(void){

    lista * nueva = (lista *) malloc(sizeof (lista));

    if(nueva==NULL){
        printf("\nNo se ha podido asignar memoria a la nueva lista\n");
        exit(-1);
    }

    nueva->pri=NULL;
    nueva->cant=0;
    nueva->ult=NULL;

    return nueva;
}

nodo * newnodo(int cod){

    nodo * nuevo= (nodo *) malloc(sizeof (nodo));

    if(nuevo==NULL){
        printf("\nNo posee memoria suficiente, para crear un nuevo nodo\n");
        exit(-1);
    }

    nuevo->cod=cod;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    return nuevo;
}

lista *apilar(lista * listaTrabajo, nodo * nodoActual) {

    nodo * aux= listaTrabajo->pri;

    if(aux==NULL){

        listaTrabajo->pri=nodoActual;
        listaTrabajo->ult=nodoActual;
        listaTrabajo->cant++;
    }else{
        nodoActual->sig=aux;
        aux->ant=nodoActual;
        listaTrabajo->pri=nodoActual;
    }

    return listaTrabajo;

}

void eliminarElemento(lista * listaTrabajo, int numero) {

    nodo * aux= listaTrabajo->pri;

    for(;aux->sig!=NULL && aux->cod!=numero; aux=aux->sig){}

    if(aux->sig==NULL && aux->cod!=numero){
        printf("el numero a eliminar, no se encuentra en la lista\n");
        return;
    }else if(aux->cod==numero) {
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        aux->sig = NULL;
        aux->ant = NULL;
        free(aux);
    }
}

void imprimirReves(lista * lista) {

    nodo * aux=lista->ult;

    for(;aux!=NULL;aux=aux->ant){
        printf("el codigo es %d\n", aux->cod);
    }
}

void modificaElemento(lista * lista, int numeroModificar, int numeroNuevo) {

    nodo * aux= lista->pri;

    for(;aux->sig!=NULL && aux->cod!=numeroModificar; aux=aux->sig){}

    if(aux->cod==numeroModificar) {
        aux->cod=numeroNuevo;
    }else{
        printf("el numero a modificar, no se encuentra en la lista\n");
    }

}

void ordenarLista(lista * lista) {

    //metodo burbuja

    nodo * aux=lista->pri;
    nodo * aux2=aux;
    if(aux==NULL){
        printf("la lista, esta vacia\n");
        return;
    }
    int NN;
    for(;aux2->sig!=NULL;aux2=aux2->sig) {
        aux=lista->pri;
        for(;aux->sig!=NULL;aux=aux->sig){
            if(aux->cod>aux->sig->cod){
                NN=aux->sig->cod;
                aux->sig->cod=aux->cod;
                aux->cod=NN;
            }}
    }

    }


