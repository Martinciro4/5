#ifndef _ARCHIVOS_H
#define _ARCHIVOS_H

/**
 * Abre un archivo
 * @param nombreArchivo nombre del archivo
 * @param modo modo de apertura del archivo
 * @return file descriptor
 */
FILE *abrir_archivo(char *nombreArchivo, char *modo);

/**
 * Cierra un archivo
 * @param fd file descriptor
 */
void cerrar_archivo(FILE *fd);

/**
 * Lee un archivo
 * @param fd file descriptor
 * @param buffer buffer a guardar la informacion que se lee
 * @param cantidad cantidad de bytes a leer
 * @return cantidad de bytes que se leyeron
 */
int leer_archivo(FILE *fd, void *buffer, int cantidad);

/**
 * Escribe un archivo
 * @param fd file descriptor
 * @param buffer buffer a escribir en el archivo
 * @param cantidad cantidad de bytes a escribir
 * @return cantidad de bytes que se escribieron
 */
int escribir_archivo(FILE *fd, void *buffer, int cantidad);

int leer_linea(FILE *fd, char *buffer, int cantidad);

int escribir_linea(FILE *fd, char *buffer);

#endif