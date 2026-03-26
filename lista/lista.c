#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "../nodo/nodo.h" 

Lista* lista_crear() {
    Lista* nueva = (Lista*)malloc(sizeof(Lista));
    if (nueva != NULL) {
        nueva->head = NULL;
        nueva->tail = NULL;
    }
    return nueva;
}

bool lista_vacia(Lista* lista) {
    return (lista == NULL || lista->head == NULL);
}

void lista_insertar_head(Lista* lista, int dato) {
    Nodo* nuevo = nodo_crear(dato); 
    if (nuevo == NULL) return;

    if (lista_vacia(lista)) {
        lista->head = lista->tail = nuevo;
    } else {
        nuevo->sig = lista->head;
        lista->head = nuevo;
    }
}

void lista_insertar_tail(Lista* lista, int dato) {
    Nodo* nuevo = nodo_crear(dato);
    if (nuevo == NULL) return;

    if (lista_vacia(lista)) {
        lista->head = lista->tail = nuevo;
    } else {
        lista->tail->sig = nuevo;
        lista->tail = nuevo;
    }
}

int lista_eliminar_head(Lista* lista) {
    if (lista_vacia(lista)) return -1;

    Nodo* temp = lista->head;
    int dato = temp->dato;

    lista->head = lista->head->sig;
    if (lista->head == NULL) {
        lista->tail = NULL;
    }

    nodo_destruir(temp); 
    return dato;
}

int lista_eliminar_tail(Lista* lista) {
    if (lista_vacia(lista)) return -1;

    Nodo* elim = lista->tail;
    int dato = elim->dato;

    if (lista->head == lista->tail) {
        lista->head = lista->tail = NULL;
    } else {
        Nodo* actual = lista->head;
        while (actual->sig != lista->tail) {
            actual = actual->sig;
        }
        actual->sig = NULL;
        lista->tail = actual;
    }

    nodo_destruir(elim); 
    return dato;
}

void lista_imprimir(Lista* lista) {
    if (lista == NULL) return;
    Nodo* actual = lista->head;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->sig;
    }
    printf("NULL\n");
}

void lista_destruir(Lista* lista) {
    if (lista == NULL) return;
    while (!lista_vacia(lista)) {
        lista_eliminar_head(lista);
    }
    free(lista);
}