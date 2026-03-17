#include <stdlib.h>
#include "nodo.h"

Nodo* nodo_crear(int dato)
{
    Nodo* PlusNodo= (Nodo*)malloc(sizeof(Nodo));
    if(PlusNodo != NULL){
        PlusNodo -> dato = dato;
        PlusNodo -> sig = NULL;
    }
    return PlusNodo;
} 

void nodo_destruir(Nodo* nodo)
{
    if(nodo != NULL){
        free(nodo);
    } 
}
