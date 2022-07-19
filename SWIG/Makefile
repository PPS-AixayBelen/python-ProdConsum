PROJECT=pps
PYTHON_VER=3.8

all:
	swig -python $(PROJECT).i
	gcc -c -fpic $(PROJECT)_wrap.c ./src/cpuProcess.c ./src/monitor.c ./src/rdp.c ./src/politica.c ./src/dataStructures.c -I/usr/include/python$(PYTHON_VER)
	gcc -shared rdp.o cpuProcess.o monitor.o politica.o dataStructures.o $(PROJECT)_wrap.o -o _$(PROJECT).so  	

clean:
	rm -r *.o *_wrap.c $(PROJECT).py *.so __pycache__