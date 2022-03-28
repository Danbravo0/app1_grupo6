#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include <stdio.h>
#include "libros.h"

int menu(); //Protipo menu
// void guardado();//Prototipo del algoritmo usado para guardar los libros en arrays

// int main(){


//     printf("el digito es %d",menu());

// }

int main(){
    // Inicializamos el puntero del archivo

    FILE *fp = fopen("inventario.csv","r"); //abrir en write
    if (!fp){
        printf("FP NO EXISTE");
    }

    char buff[2000];
    int contador_fila = 0;
    int contador_campo = 0;

    Libro libros[999]; //creamos una array para guardar los libros

    int i = 0;

    while(fgets(buff,2000,fp)){
        contador_campo = 0;
        contador_fila ++;

        if(contador_fila == 1){
            continue; //No nos importa la primer fila, ya que son los nombres de cada columna
        }
        char *campo = strtok(buff,","); //Separa una string en una serie de "tokens" usando el delimitador coma https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    // printf("wena");
        while (campo){
    // printf("wena\n");
             if(contador_campo == 0){
                 strcpy(libros[i].titulo,campo);
                //  printf("0 = %s \n",libros[i].titulo);
             }
             if(contador_campo == 1){
                 strcpy(libros[i].autor,campo);
                //  printf("1 = %s \n",libros[i].autor);
             }
             if(contador_campo == 2){
                 strcpy(libros[i].anio,campo);
                //  printf("2 = %d \n",libros[i].anio);
             }
             if(contador_campo == 3){
                 strcpy(libros[i].estante_numero,campo);
             }
             if(contador_campo == 4){
                 strcpy(libros[i].estante_seccion,campo);
             }
             if(contador_campo == 5){
                 strcpy(libros[i].piso,campo);
             }
             if(contador_campo == 6){
                 strcpy(libros[i].edificio,campo);
             }
             if(contador_campo == 7){
                 strcpy(libros[i].sede,campo);
             }
             campo = strtok(NULL,","); //actualizar valor del campo
             contador_campo ++;
        }
        i++;
    // printf("wena");
    }
    fclose(fp);
    printf("wenarda 1 \n");
    printValues(libros);
    printf("wenarda 2");
    return 0;
}


void printValues(Libro libros[]){

        // printf("hola si con quien ");
    for (int i=0;i<999;i++){
        // printf("hola si con quien ");
        printf("titulo = %s, autor = %s, anio = %s, estante numero = %s, estante seccion = %s, piso = %s, edificio = %, sede = %s",
        libros[i].titulo,libros[i].autor,libros[i].anio,libros[i].estante_numero,libros[i].estante_seccion,libros[i].piso,libros[i].edificio,libros[i].sede);
        printf("\n");
        printf("\n");
    }
}


int menu(){

    // do{
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
    // }while(true);
}