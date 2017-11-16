SS*=

all:calc


calc: calc.o add.o sub.o mul.o div.o task2.o fact.o
	$(SS) -o calc calc.o add.o sub.o mul.o div.o task2.o fact.o

calc.o:calc.c
	$(SS) -c -o calc.o calc.c

add.o: add.c
	$(SS) -c -o add.o add.c

sub.o: sub.c
	$(SS) -c -o sub.o sub.c

mul.o: mul.c
	$(SS) -c -o mul.o mul.c


div.o: div.c
	$(SS) -c -o div.o div.c


fact.o: fact.c
	$(SS) -c -o fact.o fact.c



task2.o:task2.c
	$(SS) -c -o task2.o task2.c

clean:
	rm -rf *.o
	rm -rf calc


new:
	gedit task2.c

