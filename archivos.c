#include <stdio.h>
#include "archivos.h"

FILE *abrir_archivo(char *nombreArchivo, char *modo) {
    FILE *archivo = fopen(nombreArchivo, modo);
    return archivo;
}

void cerrar_archivo(FILE *fd) {
    fclose((FILE *)fd);
}

int leer_archivo(FILE *fd, void *buffer, int cantidad) {
    return fread(buffer, 1, cantidad, (FILE *)fd);
}

int escribir_archivo(FILE *fd, void *buffer, int cantidad){
    return fwrite(buffer, 1, cantidad, (FILE *)fd);
}

int leer_linea(FILE *fd, char *buffer, int cantidad) {
    return (int)fgets(buffer, cantidad, (FILE *)fd);
}

int escribir_linea(FILE *fd, char *buffer) {
    return (int)fputs(buffer, (FILE *)fd);
}
