#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];


extern int contador_libro;


int buscar(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].titulo, nombre) == 0) {
            return i;
        }
    }
}

void borrar_libro(char *nombre) {

     int index=buscar(nombre);

     for (int i = 0; i < contador_libro; ++i) {
         if (strcmp(libros[i].titulo,nombre)==0){
             libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
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


void nuevo(int c_libros){

   printf("Nombre del libro a ingresar:");
   char nombre[300];
   scanf("%s",nombre);

   printf("Autor de libro a ingresar:");
   char autor[300];
   scanf("%s",autor);

   printf("Anio del libro a ingresar:");
   char anio[300];
   scanf("%s",anio);

   printf("Numero del estante de libro a ingresar:");
   char nest[300];
   scanf("%s",nest);

   printf("Seccion del libro a ingresar:");
   char seccion[300];
   scanf("%s",seccion);

   printf("Piso del libro a ingresar:");
   char piso[300];
   scanf("%s",piso);

   printf("Edificio del libro a ingresar:");
   char edificio[300];
   scanf("%s",edificio);

   printf("Sede del libro a ingresar:");
   char sede[300];
   scanf("%s",sede);

   strcpy(libros[c_libros+1].titulo,nombre);

   strcpy(libros[c_libros+1].autor,autor);

   strcpy(libros[c_libros+1].anio,anio);

   strcpy(libros[c_libros+1].estante_numero,nest);

   strcpy(libros[c_libros+1].estante_seccion,seccion);

   strcpy(libros[c_libros+1].piso,piso);

   strcpy(libros[c_libros+1].edificio,edificio);

   strcpy(libros[c_libros+1].sede,sede);


}

void nuevo(int c_libros){

   printf("Nombre del libro a ingresar:");
   char nombre[300];
   scanf("%s",nombre);

   printf("Autor de libro a ingresar:");
   char autor[300];
   scanf("%s",autor);

   printf("Anio del libro a ingresar:");
   char anio[300];
   scanf("%s",anio);

   printf("Numero del estante de libro a ingresar:");
   char nest[300];
   scanf("%s",nest);

   printf("Seccion del libro a ingresar:");
   char seccion[300];
   scanf("%s",seccion);

   printf("Piso del libro a ingresar:");
   char piso[300];
   scanf("%s",piso);

   printf("Edificio del libro a ingresar:");
   char edificio[300];
   scanf("%s",edificio);

   printf("Sede del libro a ingresar:");
   char sede[300];
   scanf("%s",sede);

   strcpy(libros[c_libros+1].titulo,nombre);

   strcpy(libros[c_libros+1].autor,autor);

   strcpy(libros[c_libros+1].anio,anio);

   strcpy(libros[c_libros+1].estante_numero,nest);

   strcpy(libros[c_libros+1].estante_seccion,seccion);

   strcpy(libros[c_libros+1].piso,piso);

   strcpy(libros[c_libros+1].edificio,edificio);

   strcpy(libros[c_libros+1].sede,sede);

   libros[c_libros+1].to_delete = 0;
