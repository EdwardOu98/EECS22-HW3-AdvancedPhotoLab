# Makefile: PhotoLab_v2

# Variable Declaration
D = -g -DDEBUG
C = -Wall -ansi -std=c99 -c
LA = -Wall -ansi -std=c99
LK = -L. -lFilter -lm

all: PhotoLab

test: PhotoLabTest

clean: 
	rm -r *.o
	rm -r *.a
	rm -r PhotoLab PhotoLabTest
	rm -r bw.ppm edge.ppm shuffle.ppm brightness.ppm hmirror.ppm hue.ppm

PhotoLabTest: FileIO.o libFilter.a DPhotoLab.o 
	gcc $(LA) DPhotoLab.o FileIO.o $(LK) -o PhotoLabTest

DPhotoLab.o: PhotoLab.c Constants.h DIPs.h FileIO.h
	gcc $(C) PhotoLab.c -o DPhotoLab.o $(D) 

FileIO.o: FileIO.c FileIO.h Constants.h
	gcc $(C) FileIO.c -o FileIO.o

libFilter.a: DIPs.o Advanced.o
	ar rc libFilter.a DIPs.o Advanced.o
	ranlib libFilter.a

DIPs.o: DIPs.c DIPs.h Constants.h
	gcc $(C) DIPs.c -o DIPs.o

Advanced.o: Advanced.c Advanced.h Constants.h
	gcc $(C) Advanced.c -o Advanced.o

PhotoLab.o: PhotoLab.c Constants.h DIPs.h FileIO.h
	gcc $(C) PhotoLab.c -o PhotoLab.o

PhotoLab: FileIO.o libFilter.a PhotoLab.o
	gcc $(LA) PhotoLab.o FileIO.o $(LK) -o PhotoLab
