
#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];
extern int contador_libro;
extern char sedes[1000][100];
extern char pisos[1000][100];
extern char estantes_secciones[1000][100];

void sede_add(){
    for (int i = 0; i < contador_libro; ++i) {
        strcpy(sedes[i], libros[i].sede);
        printf("%s",sedes[i]);
    }

//añadir aca la expresion/ funcion para aladir una nueva sede al array
}

void piso_add(){
    for (int i = 0; i < contador_libro; ++i) {
        strcpy(pisos[i], libros[i].piso);
        printf("%s",pisos[i]);
    }

//añadir aca la expresion/ funcion para aladir una nuevo piso al array
}

void seccion_add(){
    for (int i = 0; i < contador_libro; ++i) {
        strcpy(estantes_secciones[i], libros[i].estante_seccion);
        printf("%s",estantes_secciones[i]);
    }

//añadir aca la expresion/ funcion para aladir una nueva seccion al array
}
