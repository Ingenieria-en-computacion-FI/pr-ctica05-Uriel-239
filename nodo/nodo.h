#ifndef NODO_H
#define NODO_H

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;

Nodo* nodo_crear(int dato);
void nodo_destruir(Nodo* nodo);

#endif
