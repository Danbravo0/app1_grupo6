#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include <stdio.h>
#include <libros.h>

int menu(); //Protipo menu
// void guardado();//Prototipo del algoritmo usado para guardar los libros en arrays

// int main(){


//     printf("el digito es %d",menu());

// }

void printValues(Libro libros[]){

    // printf("hola si con quien ");
    for (int i=0;i<15;i++){
        // printf("hola si con quien ");
        printf("titulo = %s, " ,libros[i].titulo );
        printf("autor = %s, " ,libros[i].autor  );
        printf("anio = %s, " ,libros[i].anio );
        printf("estante_numero = %s, " ,libros[i].estante_numero );
        printf("estante_seccion = %s, " ,libros[i].estante_seccion );
        printf("piso = %s, " ,libros[i].piso );
        printf("edificio = %s, " ,libros[i].edificio );
        printf("sede = %s, " ,libros[i].sede );





        printf("\n");
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    // Inicializamos el puntero del archivo

    char archivo[30];

    strcpy(archivo,argv[1]);

    FILE *fp = fopen(archivo,"r"); //abrir en write
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
             switch(contador_campo){
                 case 0:
                 strcpy(libros[i].titulo,campo);
                 break;
                //  printf("0 = %s \n",libros[i].titulo);

                 case 1:
                 strcpy(libros[i].autor,campo);
                 break;
                 //  printf("1 = %s \n",libros[i].autor);

                 case 2:
                 strcpy(libros[i].anio,campo);
                 break;
                //  printf("2 = %d \n",libros[i].anio);
                case 3:
                 strcpy(libros[i].estante_numero,campo);
                 break;

                 case 4:
                 strcpy(libros[i].estante_seccion,campo);
                 break;

                 case 5:
                 strcpy(libros[i].piso,campo);
                 break;

                 case 6:
                 strcpy(libros[i].edificio,campo);
                 break;

                 case 7:
                 strcpy(libros[i].sede,campo);
                 break;
             }
             campo = strtok(NULL,","); //actualizar valor del campo
             contador_campo ++;
        }
        i++;
    // printf("wena");
    }
    fclose(fp);

    printValues(libros);
    printf("wenarda 2");
    return 0;
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