all:calc

calc: calc.o add.o sub.o mul.o div.o
	gcc -o calc calc.o add.o sub.o mul.o div.o

calc.o:calc.c
	gcc -c -o calc.o calc.c

add.o: add.c
	gcc -c -o add.o add.c

sub.o: sub.c
	gcc -c -o sub.o sub.c

mul.o: mul.c
	gcc -c -o mul.o mul.c


div.o: div.c
	gcc -c -o div.o div.c



clean:
	rm -rf *.o
	rm -rf calc



