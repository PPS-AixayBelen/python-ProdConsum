# distutils: sources = rdp.c 
# distutils: include_dirs = .

cimport crdp

cdef class rdp_o:
    cdef crdp.rdp_o* _c_rdp
