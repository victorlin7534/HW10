default: main.o rand.o
	gcc -o test main.o rand.o
main.o: main.c rand.h
	gcc -c main.c
rand.o: rand.c rand.h
	gcc -c rand.c
run:
	./test
clean:
	rm -f *.o test *.exe *.out file.txt