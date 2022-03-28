struct Libros {
   char  titulo[50];
   char  autor[50];
   char   anio[4];
   char   estante_numero[2];
   char  estante_seccion[50];
   char   piso[2];
   char  edificio[1];
   char  sede[50];
} ;

typedef struct Libros Libro;

void infoLibro(Libro Libro);