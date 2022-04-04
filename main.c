#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "quitar.h"
#include "libros.h" 
#include "archivo.h" //leer y escribir
#include "admin.h"



Libro libros[1500]; //HACEMOS LA ARRAY GLOBAL PARA PODER EDITARLA DENTRO DE TODAS LAS FUNCIONES
int contador_libro; //Cantidad de libros
int contador_sede;
int contador_seccion;
int contador_piso;
char sedes[1500][100];
char pisos[1500][30];
char estantes_secciones[1500][100];

enum OPTIONS {BUSCAR = 1, NUEVO = 2, QUITAR = 3, ADD_SEDE, QUITAR_SEDE, EDIT_LIBRO, CAMBIAR_SEDE, CAMBIAR_SECCION, CAMBIAR_PISO, AGREGAR_SECCIONES, 
              ELIMINAR_SECCIONES, AGREGAR_PISOS, QUITAR_PISOS,  SALIR = 14};


void menu(); //Protipo menu


int main(int argc, char *argv[]){

  int option = 0;
  leer(argc,argv); //en archivo.c
  contador_piso=contador_seccion=contador_sede=contador_libro;
  llenar();
  int salir = 0;
  while (salir == 0){
  
    menu();
    scanf("%d", &option);
    switch (option)
    {
    case BUSCAR: //Buscar libro
      printf("Ingrese el nombre del libro a buscar\n");
      char nombre[50];
      scanf("%[^\n]",nombre);
      infoLibro(buscar(nombre));
      printf("Presione enter para volver al menu");
      getchar();
      getchar(); //Dos veces porque el switch hace que el primer getchar se "ignore"
      option = 0;
      break;
    
    case NUEVO:
      nuevo(contador_libro);
      printf("Libro creado, presione enter para volver al menu");
      getchar();
      getchar(); //Dos veces porque el switch hace que el primer getchar se "ignora"
      break;

    case QUITAR:
      printf("Ingrese el nombre del libro a quitar\n");
      char nombre_q[50];
      scanf(" %[^\n]",nombre_q);
      borrar_libro(nombre_q);
      printf("Libro quitado, presione enter para volver al menu");
      getchar();
      getchar(); //Dos veces porque el switch hace que el primer getchar se "ignora"
      break;

    case ADD_SEDE:
        printf("Ingrese el nombre de la sede a añadir: \n");
        char nombre_s[50];
        scanf(" %[^\n]",nombre_s);
        sede_add(nombre_s);
        printf("Sede añadida,presione enter para volver al menu");
        getchar();
        getchar();
        option = 0;
      break;

    case QUITAR_SEDE:
        printf("Introduzca el nombre de la sede que desea quitar:\n ");
            char sede[50];
            scanf(" %[^\n]",sede);
            if (buscar_sede(sede)== -1) {
                borrar_sedelista(sede);
                printf("Se ha borrado la sede exitosamente");
            }
            else {
                printf("Introduzca SI si desea elimar todos los libros asociados a la sede: \n  ");
                char ans[10];
                scanf("%s", ans);
                if (strcmp(ans, "SI")==0){
                    borrar_sede(sede);
                    printf("Gracias");}
                else {
                printf("Haz decidido no quitar la sede"); }
                }
            getchar();
            getchar();
            break;

    case EDIT_LIBRO:
      printf("Ingresa el nombre del libro a editar\n");
      char nombre_a_editar[50];
      scanf(" %[^\n]",nombre_a_editar);
      editar_libro(nombre_a_editar);
  
      break;

    case CAMBIAR_SEDE:

      break;

    case CAMBIAR_SECCION:

      break;

    case CAMBIAR_PISO:

      break;

    case AGREGAR_SECCIONES:
        printf("Ingrese la seccion a añadir: \n");
        char nombre_e[50];
        scanf(" %[^\n]",nombre_e);
        seccion_add(nombre_e);
        printf("Seccion añadida, presione enter para volver al menu");
        getchar();
        getchar();
        option = 0;
      break;

    case ELIMINAR_SECCIONES:
        printf("Introduzca la seccion que desea quitar:\n ");
            char seccion_borrar[50];
            scanf(" %[^\n]",seccion_borrar);
            if (buscar_seccion(seccion_borrar)== -1) {
                borrar_seccionlista(seccion_borrar);
                printf("Se ha borrado la seccion exitosamente");
            }
            else {
                printf("Introduzca SI si desea elimar todos los libros asociados a la seccion: \n  ");
                char ans[10];
                scanf("%s", ans);
                if (strcmp(ans, "SI")==0){
                    borrar_seccion(seccion_borrar);
                    printf("Gracias");}
                else {
                    printf("Haz decidido no quitar la seccion"); }
            }
            getchar();
            getchar();


      break;

    case AGREGAR_PISOS:
        printf("Ingrese el numero de piso a añadir: \n");
        char nombre_p[50];
        scanf(" %[^\n]",nombre_p);
        piso_add(nombre_p);
        printf("Piso añadido, presione enter para volver al menu");
        getchar();
        getchar();
        option = 0;
      break;

    case QUITAR_PISOS:
        printf("Introduzca el piso que desea quitar:\n ");
            char piso_borrar[50];
            scanf(" %[^\n]",piso_borrar);
            if (buscar_piso(piso_borrar)== -1) {
                borrar_pisolista(piso_borrar);
                printf("Se ha borrado el piso exitosamente");
            }
            else {
                printf("Introduzca SI si desea elimar todos los libros asociados al piso: \n  ");
                char ans[10];
                scanf("%s", ans);
                if (strcmp(ans, "SI")==0){
                    borrar_piso(piso_borrar);
                    printf("Gracias");}
                else {
                    printf("Haz decidido no quitar el piso"); }
            }
            getchar();
            getchar();

      break;
      
    case SALIR:
      guardar(argc,argv);
      salir = 1;
    
    default:
      break;
    }
  }

    return 0;
}




void menu(){
        printf("\n**************************************\n");
        printf("\nBienvenido al inventario de libros UAI\n");
        printf("Ingrese uno de los siguientes numeros para hacer la accion a su derecha\n");
        printf("1.  Buscar un libro\n");
        printf("2.  Agregar un libro nuevo\n");
        printf("3.  Quitar un libro existente\n");
        printf("4.  Agregar una sede\n");
        printf("5.  Quitar una sede\n"); //Solo si no tiene libros asociados
        printf("6.  Editar un libro\n");
        printf("7.  Cambiar un libro de sede\n");
        printf("8.  Cambiar un libro de seccion\n");
        printf("9.  Cambiar un libro de piso \n");
        printf("10. Agregar secciones\n");
        printf("11. Eliminar secciones\n"); //Solo si no tiene libros asociados
        printf("12. Agregar pisos\n");
        printf("13. Quitar pisos\n"); //Solo si no tiene libros asociados
        printf("14. Salir y guardad\n");
        printf("\n**************************************\n");
 }
