struct Libros {
   char  titulo[50];
   char  autor[50];
   char  anio[15];
   char  estante_numero[15];
   char  estante_seccion[50];
   char  piso[15];
   char  edificio[20];
   char  sede[50];
   int to_delete;
} ;

typedef struct Libros Libro;

void infoLibro(Libro Libro);
