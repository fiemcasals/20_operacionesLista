//
// Created by mauri on 03/09/22.
//

#ifndef INC_20_OPERACIONESLISTA_HELPER_H
#define INC_20_OPERACIONESLISTA_HELPER_H

typedef struct nodo{

    int cod;
    struct nodo * sig;
    struct nodo * ant;

}nodo;

typedef struct lista{

    int cant;
    nodo * pri;
    nodo * ult;

}lista;

lista * newlist(void);

nodo * newnodo(int);

lista * apilar(lista*, nodo*);

void imprimir(lista*);

void imprimirReves(lista*);

void eliminarElemento(lista*,int);

void modificaElemento(lista*,int,int);
#endif //INC_20_OPERACIONESLISTA_HELPER_H
