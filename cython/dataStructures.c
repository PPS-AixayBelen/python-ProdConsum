#include "dataStructures.h"


int alloc_vector(o_vector *p_vector);
void free_vector(o_vector *p_vector);
void print(o_vector p_vector);
int copy(o_vector dst, o_vector src);
void cargar_vector(o_vector* vector, char *v);


struct vector_methods v_methods = {
    .alloc_vector = alloc_vector,
    .free_vector = free_vector,
    .print = print,
    .copy = copy,
    .cargar_vector=cargar_vector};

/**
 * @brief Aloca memoria para un vector cuyo tamaño esta especificado en la variable size de p_vector.
 * 
 * @param p_vector Puntero a una estructura de tipo o_vector
 * @return int -1 si ocurrio un error en la alocacion, 0 si la alocacion fue correcta.
 */
int alloc_vector(o_vector *p_vector)
{

    int *p_v = (int *)malloc(sizeof(int) * p_vector->size);

    if (p_vector == NULL)
    {
        return ALLOC_ERROR;
    }

    p_vector->vector = p_v;
    return ALLOC_OK;
}

/**
 * @brief Imprime por pantalla el vector, en el formato {1 2 3 4}
 * 
 * @param p_vector Puntero a la estructura con el vector a imprimir
 */
void print(o_vector p_vector)
{
    printf("{ ");
    for (int i = 0; i < p_vector.size; i++)
    {
        printf("%d ", p_vector.vector[i]);
    }
    printf("}\n");
}

/**
 * @brief Libera la variable vector de p_vector alocada con alloc_vector.
 * 
 * @param p_vector Estructura que contiene el vector a liberar.
 */
void free_vector(o_vector *p_vector)
{
    free(p_vector->vector);
}

/**
 * @brief Carga el vector cuyos valores se encuentran en el vector v separados
 *  por un espacio en el vector.
 * 
 * @param size Tamaño del vector a cargar.
 * @param vector Vector donde deben guardarse los valores leidos
 * @param v Cadena de caracteres que contiene los valores del array separados por un espacio.
 */
void cargar_vector(o_vector* vector, char *v)
{

    char *token;

    token = strtok(v, " ");
    vector->vector[0] = atoi(token);

    for (int i = 1; i < vector->size; i++)
    {
        token = strtok(NULL, " ");
        vector->vector[i] = atoi(token);
    }
}


/**
 * @brief Copia los valores de la variable vector de la estructura src en la variable vector de dst
 * 
 * @param dst Estructura destino
 * @param src Estructura desde donde se copia el vector
 * @return int -1 si el campo size de los vectores no es igual, 0 si se logro copiar exitosamente.
 */
int copy(o_vector dst, o_vector src)
{
    if (src.size != dst.size)
    {
        return -1;
    }

    for (int i = 0; i < dst.size; i++)
    {
        dst.vector[i] = src.vector[i];
    }

    return 0;
}



/**
 * @brief Inicializa los valores de la estructura p_v, alocando la memoria necesaria.
 * 
 * @param p_v Puntero a la estructura o_vector
 * @param v_size Tamaño del vector 
 * @return int -1 si ocurre un error al alocar la memoria, 0 si se aloca correctamente
 */
int new_vector(void *p_v, int v_size)
{
    o_vector *vector_pointer = (o_vector *)p_v;
    vector_pointer->size = v_size;
    vector_pointer->v_methods = &v_methods;
    int p_v_alloc = vector_pointer->v_methods->alloc_vector(p_v);
    if (p_v_alloc == ALLOC_ERROR)
    {
        return ALLOC_ERROR;
    }

    return ALLOC_OK;
}

