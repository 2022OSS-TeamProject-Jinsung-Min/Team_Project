vm: main.o system.o
	gcc main.o system.o -o vm
system.o: system.c
	gcc system.c -c -o system.o
main.o: main.c
	gcc main.c -c -o main.o
clean:
	rm *.o vm