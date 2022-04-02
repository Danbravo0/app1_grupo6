#include "libros.h"
#include <stdio.h>

extern Libro libros[];

int buscar() {
    char nombre[50];
    printf("Escriba el nombre del libro que desea\n");
    scanf("%s", nombre);

    for (int i = 0; i < 6; ++i) {
        if (strcmp(libros[i].titulo, nombre) == 0) {
            return i;
        }
    }
}

void borrar_libro() {
   //  char nombre[50];
   //  printf("Escriba el nombre del libro a eliminar\n");
   //  scanf("%s",nombre);

   //  for (int i = 0; i < 6; ++i) {
   //      if (strcmp(libros[i].titulo,nombre)==0){
   //          libros[i].to_delete=1;
   //      }
   //  }
   //  printf("Accion realizada\n");    
}



void infoLibro(int index) {
   printf( "Titulo del libro: %s\n", libros[index].titulo);
   printf( "Autor del libro: %s\n", libros[index].autor);
   printf( "Anio de publicacion: %s\n", libros[index].anio);
   printf( "Numero del estante: %s\n", libros[index].estante_numero);
   printf( "Seccion del estante: %s\n", libros[index].estante_seccion);
   printf( "Piso: %s\n", libros[index].piso);
   printf( "Edificio: %s\n", libros[index].edificio);
   printf( "Sede: %s\n", libros[index].sede);
}

void cambiar_sede(int index,char sede[90]){

    strcpy(libros[index].sede,sede);

}