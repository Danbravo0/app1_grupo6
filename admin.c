
#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];
extern int contador_libro;
extern char sedes[1000][100];
extern char pisos[1000][100];
extern char estantes_secciones[1000][100];


void llenar(){
        for (int i = 0; i < contador_libro; ++i) {
        strcpy(sedes[i], libros[i].sede);
        strcpy(pisos[i], libros[i].piso);
        strcpy(estantes_secciones[i], libros[i].estante_seccion);
        }
}

void sede_add(){
//añadir aca la expresion/ funcion para aladir una nueva sede al array
}

void piso_add(){
//añadir aca la expresion/ funcion para aladir una nuevo piso al array
}


void seccion_add(){
//añadir aca la expresion/ funcion para aladir una nueva seccion al array
}
