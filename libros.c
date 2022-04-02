#include "libros.h"
#include <stdio.h>

void infoLibro(Libro Libro) {

   printf( "Titulo del libro: %s\n", Libro.titulo);
   printf( "Autor del libro: %s\n", Libro.autor);
   printf( "Año de publicacion: %d\n", Libro.anio);
   printf( "Numero del estante: %i\n", Libro.estante_numero);
   printf( "Seccion del estante: %d\n", Libro.estante_seccion);
   printf( "Piso: %d\n", Libro.piso);
   printf( "Edificio: %d\n", Libro.edificio);
   printf( "Sede: %d\n", Libro.sede);
}