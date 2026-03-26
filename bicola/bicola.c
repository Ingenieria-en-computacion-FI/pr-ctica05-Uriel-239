#include <stdlib.h>
#include "bicola.h"

Bicola* bicola_crear() {
    return (Bicola*)lista_crear();
}

bool bicola_vacia(Bicola* bicola) {
    return lista_vacia(bicola);
}

void bicola_insertar_frente(Bicola* bicola, int dato) {
    lista_insertar_head(bicola, dato);
}

void bicola_insertar_final(Bicola* bicola, int dato) {
    lista_insertar_tail(bicola, dato);
}

int bicola_eliminar_frente(Bicola* bicola) {
    return lista_eliminar_head(bicola);
}

int bicola_eliminar_final(Bicola* bicola) {
    return lista_eliminar_tail(bicola);
}

int bicola_ver_frente(Bicola* bicola) {
    if (bicola_vacia(bicola)) return -1;
    return bicola->head->dato;
}

int bicola_ver_final(Bicola* bicola) {
    if (bicola_vacia(bicola)) return -1;
    return bicola->tail->dato;
}

void bicola_destruir(Bicola* bicola) {
    lista_destruir(bicola);
}