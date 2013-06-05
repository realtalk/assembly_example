all: outofline inline

outofline:
	gcc -c outofline.S -o outofline_asm.o
	gcc -c outofline.c -o outofline_c.o -Wall
	gcc outofline_asm.o outofline_c.o -o outofline

inline:
	gcc inline.c -o inline -Wall

clean:
	rm -f inline outofline *.o

