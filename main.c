#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "libros.h" 
#include "archivo.h" //leer y escribir


Libro libros[999]; //HACEMOS LA ARRAY GLOBAL PARA PODER EDITARLA DENTRO DE TODAS LAS FUNCIONES


int menu(); //Protipo menu

int main(int argc, char *argv[]){
    
    leer(argc,argv); //en archivo.c
    infoLibro(1); //en libro.c
    printf("*************\n");
    cambiar_sede(1,"hola si con quien");
    infoLibro(1);
    printf("*************\n");
    getchar();
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
