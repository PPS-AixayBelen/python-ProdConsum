cdef extern from "dataStructures.h":

    ctypedef struct o_vector:
        pass
    ctypedef struct o_matriz:
        pass

    extern int new_vector(o_vector *p_v, int v_size);
    extern int new_matriz(o_matriz *p_m, int columnas, int filas);




