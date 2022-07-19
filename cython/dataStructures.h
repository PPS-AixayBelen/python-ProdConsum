#ifndef _dataStructures_
#define _dataStructures_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALLOC_ERROR -1
#define ALLOC_OK 0
#define READ_FILE_OK 0
#define READ_FILE_ERROR -1

typedef struct vector o_vector;

struct vector_methods
{
    int (*alloc_vector)(o_vector *);
    void (*free_vector)(o_vector *);
    void (*print)(o_vector);
    int (*copy)(o_vector dst, o_vector src);
    void (*cargar_vector)(o_vector* vector, char *v);
};

struct vector
{
    int *vector;
    int size;
    const struct vector_methods *v_methods;
};

int new_vector(void *p_v, int v_size);

#endif