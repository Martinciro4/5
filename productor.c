#include <stdio.h>
#include <unistd.h>
#include "productor.h"
#include "semaforos.h"
#include "defs.h"

int main(int argc, char *argv[]) {
    producir();
    return 0;
}

int producir()
{
    char cadena[LARGO]; /* Un array lo suficientemente grande como para guardar la l�nea m�s larga del fichero */
    int nro_producto=0, nro_partida=0;
    FILE *productor;


    int id_semaforo;

    id_semaforo = crear_semaforo(CLAVE_IPC, RUTA_IPC);
    inicializar_semaforo(id_semaforo, VERDE);

    while(1)
    {
        esperar_semaforo(id_semaforo);

        printf("\nPRODUCIMOS-PARTIDA-%04d\n",nro_partida);
        productor = fopen("producto.txt", "a");
        if (productor!=NULL)
        {
            for (nro_producto=0; nro_producto<CANTIDAD_PARTIDA; nro_producto++)
            {
                sprintf(cadena, "PRODUCTO-%04d-%04d\n", nro_partida, nro_producto);
                printf("%s", cadena);
                fprintf(productor,"%s",cadena);
                sleep(INTERVALO_PRODUCTO);
            }
            fclose(productor);
            nro_partida++;
            printf("\nESPERAMOS\n");
        }
        else
        {
            perror ("Error al abrir producto.txt");
        }

        levantar_semaforo(id_semaforo);
        sleep(INTERVALO_PARTIDA);
    };
    return 0;
}
