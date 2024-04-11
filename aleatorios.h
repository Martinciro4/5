#ifndef ALEATORIOS_H
#define ALEATORIOS_H

/**
 * Estructura para contener un numero enterio
 */
typedef struct {
    int numero;
} s_numero;

/**
 * Inicializa la semilla de numeros aleatorios
 */
void inicializar_semilla_random();

/**
 * Obtiene un numero aleatorio
 * @return Numero aleatorio
 */
int random_int();

/**
 * Obtiene un numero aleatorio acotado
 * @param from a partir de que numero obtiene el numero aleatorio
 * @param to hasta donde obtiene el numero aleatorio
 * @return numero aleatorio
 */
int random_int_acotado(int from, int to);

/**
 * Verifica si un numero se encuentra en el vector de s_numero
 * @param vector vector a verificar
 * @param numero numero a buscar
 * @return 1 si se encuentra el numero, 0 si no se encuentra
 */
int verificar_numero_en_vector(s_numero *vector, int numero);

/**
 * Genera un vector de numeros aleatorios
 * @param cantidad Cantidad de elementos a generar
 * @return vector de s_numero aleatorios
 */
s_numero *generar_vector_aleatorio(int cantidad);

/**
 * Genera un vector de numeros aleatorios acotados
 * @param cantidad cantidad de elementos para el vector
 * @param from desde
 * @param to hasta
 * @return vector de s_numero aleatorios
 */
s_numero *generar_vector_aleatorio_acotado(int cantidad, int from, int to);

#endif
