#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

Lista* lista_crear()
{
    Lista* ProLista = (Lista*)malloc(sizeof(Lista));
    if(ProLista != NULL){
        ProLista->head = NULL;
        ProLista->tail = NULL;
    }
    return ProLista;
}

bool lista_vacia(Lista* lista){
    return (lista == NULL || lista -> head == NULL);
}

void lista_insertar_head(Lista* lista, int dato){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return;

    nuevo->dato = dato;
    nuevo->sig = lista->head;
    
    if (lista_vacia(lista)) {
        lista->tail = nuevo;
    }
    
    lista->head = nuevo;
}

void lista_insertar_tail(Lista* lista, int dato)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if (lista_vacia(lista)) {
        lista->head = nuevo;
        lista->tail = nuevo;
    } else {
        lista->tail->sig = nuevo;
        lista->tail = nuevo;
    }
}

int lista_eliminar_head(Lista* lista)
{
    if (lista_vacia(lista)) return -1;
    Nodo* temp = lista->head;
    int dato = temp->dato;

    lista -> head = lista->head->sig;
    if (lista->head == NULL) {
        lista->tail = NULL;
    }
    free(temp);
    return dato;
}

int lista_eliminar_tail(Lista* lista)
{
    if (lista_vacia(lista)) return -1;

    int dato;
    Nodo* elim = lista->tail;

    if (lista->head == lista->tail) {
        dato = elim->dato;
        free(elim);
        lista->head = NULL;
        lista->tail = NULL;
    } 
    else {
        Nodo* actual = lista->head;
        while (actual->sig != lista->tail) {
            actual = actual->sig;
        }
        
        dato = elim->dato;
        actual->sig = NULL;
        lista->tail = actual;
        
        free(elim);
    }
    return dato;
}

void lista_imprimir(Lista* lista)
{
    if (lista == NULL) return;
    Nodo* actual = lista->head;
    while(actual != NULL)
    {
        printf("%d -> ", actual -> dato);
        actual = actual->sig;
    }
    printf("NULL\n");
}

void lista_destruir(Lista* lista)
{
    if (lista == NULL) return;

    while (!lista_vacia(lista)) {
        lista_eliminar_head(lista);
    }
    free(lista);
}
