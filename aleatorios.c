#include "aleatorios.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void inicializar_semilla_random() {
    srand(time(0));
}

int random_int() {
    return rand();
}

int random_int_acotado(int from, int to) {
    return (rand() % (to - from + 1)) + from;
}

int verificar_numero_en_vector(s_numero *vector, int numero) {
    int i;

    for (i = 0; i < sizeof(vector); i++) {
        if (vector[i].numero == numero) {
            return 1;
        }
    }

    return 0;
}

s_numero *generar_vector_aleatorio(int cantidad) {
    int i, nuevo_numero;
    s_numero *vector = (s_numero *)malloc(cantidad * sizeof(s_numero));
    memset(vector, 0, cantidad * sizeof(s_numero));
    for (i = 0; i < cantidad; i++) {
        do {
            nuevo_numero = random_int();
        } while (verificar_numero_en_vector(vector, nuevo_numero));
        vector[i].numero = nuevo_numero;
    }
    return vector;
}

s_numero *generar_vector_aleatorio_acotado(int cantidad, int from, int to) {
    int i, nuevo_numero;
    s_numero *vector = (s_numero *)malloc(cantidad * sizeof(s_numero));
    memset(vector, 0, cantidad * sizeof(s_numero));
    for (i = 0; i < cantidad; i++) {
        do {
            nuevo_numero = random_int_acotado(from, to);
        } while (verificar_numero_en_vector(vector, nuevo_numero));
        vector[i].numero = nuevo_numero;
    }
    return vector;
}
