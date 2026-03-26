#ifndef BICOLA_H
#define BICOLA_H

#include "../lista/lista.h"

typedef Lista Bicola;

Bicola* bicola_crear();

bool bicola_vacia(Bicola* bicola);

void bicola_insertar_frente(Bicola* bicola, int dato);

void bicola_insertar_final(Bicola* bicola, int dato);

int bicola_eliminar_frente(Bicola* bicola);

int bicola_eliminar_final(Bicola* bicola);

int bicola_ver_frente(Bicola* bicola);

int bicola_ver_final(Bicola* bicola);

void bicola_destruir(Bicola* bicola);

#endif