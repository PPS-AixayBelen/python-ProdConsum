from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    ext_modules = cythonize([Extension("rdp2", ["rdp2.pyx"]), Extension("dataStruct", ["dataStruct.pyx"])], compiler_directives={'language_level': 3})
)
