PROJECT=pps
PYTHON_VER=3.8

all:
	swig -python $(PROJECT).i
	gcc -c -fpic $(PROJECT)_wrap.c $(PROJECT).c -I/usr/include/python$(PYTHON_VER)
	gcc -shared $(PROJECT).o $(PROJECT)_wrap.o -o _$(PROJECT).so  	

clean:
	rm -r *.o *_wrap.c $(PROJECT).py *.so __pycache__