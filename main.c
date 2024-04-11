#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "defs.h"
#include "semaforos.h"

int main(void) {
    int id_semaforo;

    id_semaforo = crear_semaforo(CLAVE_IPC, "/bin/ls");
    inicializar_semaforo(id_semaforo, VERDE);

    while(1) {
        esperar_semaforo(id_semaforo);
        printf("Seccion critica\n");
        sleep(1);
        levantar_semaforo(id_semaforo);
        sleep (1);
    }

    return 0;
}
