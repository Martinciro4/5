#ifndef SEMAFOROS_H
#define SEMAFOROS_H

#include <sys/ipc.h>
#include "defs.h"

/**
 * Crea uan clave de un archivo y un numero
 * @param ruta Ruta al archivo
 * @param id Identificador
 * @return Clave IPC
 */
key_t crear_clave_ipc(char *ruta, int id);

/**
 * Crea un semaforo
 * 
 * @param clave_base clave base para crear el semaforo
 * @param ruta ruta al archivo para crear la clave
 * @return
 */
int crear_semaforo(int clave_base, char *ruta);

/**
 * Inicializa un semaforo
 *
 * @param id_semaforo
 * @param valor 
 */
void inicializar_semaforo(int id_semaforo, int valor);

/**
 * Levanta un semaforo
 *
 * @param id_semaforo 
 */
void levantar_semaforo(int id_semaforo);

/**
 * Espera un semaforo
 *
 * @param id_semaforo
 */
void esperar_semaforo(int id_semaforo);

#endif
