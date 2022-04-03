#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "libros.h" 
#include "archivo.h" //leer y escribir



Libro libros[1500]; //HACEMOS LA ARRAY GLOBAL PARA PODER EDITARLA DENTRO DE TODAS LAS FUNCIONES
int contador_libro; //Cantidad de libros


int menu(); //Protipo menu

int main(int argc, char *argv[]){
/*
    char nombre[50];
    leer(argc,argv); //en archivo.c
    printf("1.-%d\n",contador_libro);
    infoLibro(1); //en libro.c
    printf("*************\n");
    printf("escriba nombre\n");
    scanf("%[^\n]", nombre);
    borrar_libro(nombre);
    guardar(argc,argv);

  */
    leer(argc,argv); //en archivo.c

    printf("c_libros = %d",contador_libro);

    nuevo(contador_libro);

    
    printf("*************\n");
    printf("*************\n");

    infoLibro(contador_libro); //en libro.c
    printf("%d\n",contador_libro);
    guardar(argc,argv);
    printf("******WENA*******\n");
    // printf("*************\n");
    // cambiar_sede(1,"hola si con quien");
    // infoLibro(1);
    // printf("*************\n");


    //char nombre[50]= scanf()
    //borrar_libro();

    return 0;
}




int menu(){

        int x;
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
        printf("\n**************************************\n");
        scanf("%d", &x);
        return(x);
}
