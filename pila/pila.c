#include <stdlib.h>
#include "pila.h"
#include "lista.h"

Pila* pila_crear()
{
    Pila* nuevaPila = (Pila*)malloc(sizeof(Pila));
    if (nuevaPila != NULL) {
        nuevaPila->lista = lista_crear();
    }
    return nuevaPila;
}

int pila_vacia(Pila* pila)
{
    if (pila == NULL || lista_vacia(pila->lista)) {
        return 1;
    }
    return 0;
}

void pila_push(Pila* pila, int dato)
{
    if (pila != NULL) {
        lista_insertar_tail(pila->lista, dato);
    }
}

int pila_pop(Pila* pila)
{
    if (pila_vacia(pila)) {
        return -1; 
    }
    return lista_eliminar_tail(pila->lista);
}

int pila_top(Pila* pila)
{
    if (pila_vacia(pila)) {
        return -1;
    }
    
    return pila->lista->tail->dato;
}

void pila_destruir(Pila* pila)
{
    if (pila != NULL) {
        lista_destruir(pila->lista);
        free(pila);
    }
}
