#include <stdio.h>
#include <unistd.h>
#include "consumidor.h"
#include "defs.h"
#include "semaforos.h"

int main(int argc, char *argv[]) {
    consumir();
    return 0;
}

int consumir(void) {
    char cadena[LARGO]; /* Un array lo suficientemente grande como para guardar la l�nea m�s larga del fichero */
    int cant_producto=0;
    FILE *consumidor;

    int id_semaforo;
    id_semaforo = crear_semaforo(CLAVE_IPC, RUTA_IPC);

    while(1)
    {
        esperar_semaforo(id_semaforo);

        consumidor = fopen("producto.txt", "r");
        if (consumidor!=NULL)
        {
            printf("\nCONSUMIMOS\n");
            while (!feof(consumidor))
            {
                fscanf(consumidor,"%s",cadena);
                printf("%s\n", cadena);
                sleep(INTERVALO_PRODUCTO);
                cant_producto++;
            }
            fclose(consumidor);
            if(cant_producto>0)
            {
                printf("\nBORRAMOS\n");
                remove("producto.txt");
                cant_producto=0;
            }
        }
        else
            perror ("Error al abrir producto.txt");
        printf("\nESPERAMOS\n");

        levantar_semaforo(id_semaforo);
        usleep(INTERVALO_PARTIDA);
    };
    return 0;
}