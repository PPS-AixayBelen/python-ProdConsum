cdef extern from "dataStructures.h":
    int new_vector(void *p_v, int v_size)

cdef int nuevo_vector(void *p_v, int v_size):
    new_vector(p_v, v_size)

