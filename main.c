#include "helper.h"

    int main() {

        lista * lista=newlist();

        apilar(lista, newnodo(3));
        apilar(lista, newnodo(2));
        apilar(lista, newnodo(5));
        apilar(lista, newnodo(4));
        apilar(lista, newnodo(6));

        eliminarElemento(lista,5);

        modificaElemento(lista,6,8);

        imprimir(lista);

        imprimirReves(lista);

        ordenarLista(lista);

        imprimir(lista);

        return 0;
    }
