all:
	gcc -g -c -Wall main.c -pthread -o  main.o
	gcc -g -c -Wall  scheduler.c  -pthread -o   scheduler.o 
	gcc -g -Wall -pthread main.o scheduler.o  -o application

clean:
	rm *.o
	rm application