SS*=

all:calc


calc: calc.o add.o sub.o mul.o 
	$(SS) -o calc calc.o add.o sub.o mul.o 

calc.o:calc.c
	$(SS) -c -o calc.o calc.c

add.o: add.c
	$(SS) -c -o add.o add.c

sub.o: sub.c
	$(SS) -c -o sub.o sub.c

mul.o: mul.c
	$(SS) -c -o mul.o mul.c


clean:
	rm -rf *.o
	rm -rf calc



