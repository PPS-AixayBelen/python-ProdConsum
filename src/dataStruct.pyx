# distutils: sources = dataStructures.c 
# distutils: include_dirs = .

cimport cDataStructures

cdef extern int new_vector(o_vector *p_v, int v_size);
cdef extern int new_matriz(o_matriz *p_m, int columnas, int filas);

cdef class o_vector:
    cdef cDataStructures.o_vector* _c_vector

cdef class o_matriz:
    cdef cDataStructures.o_matriz* _c_matriz

