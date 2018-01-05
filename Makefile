all: exec

exec: as1.o
	gcc as1.o -o exec && ./exec

as1.o: as1.c
	gcc -c as1.c

clean:
	rm -rf *o as1


