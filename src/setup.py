from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    ext_modules = cythonize([Extension("cdataStructures", ["cDataStructures.pyx"])], compiler_directives={'language_level': 3})
)
