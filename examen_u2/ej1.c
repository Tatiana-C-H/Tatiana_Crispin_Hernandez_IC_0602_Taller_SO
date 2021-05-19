#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>


// vars p1
char x='x';
char* p=&x;
char r;
char y='y';
char* puntero=&y;

// vars p2
char pp[5]={'a','b','c','d','e'};
char arrayChar[5];
char* punteChar=&arrayChar[0];
char* punteroCharDos=&arrayChar[0];
int i=1;



int main()
{
	printf("\n\t EJERCICIO 1 \n\n");
	//printf(" Contenido de p: %s \n", *p);
	printf(" Contenido de p: %c \n", *p);
	//printf(" Direccion de p: %p \n", *puntero);

	*p+=1;
	//printf("\n Contenido de p: %s \n", *p);
	printf("\n Contenido de p: %c \n", *p);

	*p = *p+2;
	//printf("\n Contenido de p: %s \n", *p);
	printf("\n Contenido de p: %c \n", *p);

	//printf("\n Contenido de p: %s \n", *puntero);
	printf("\n Contenido de p: %c \n", *puntero);

	
	printf("\n -----------------------------------------------------");
	printf("\n\n\t EJERCICIO 2 \n\n");

	for (i = 0; i <= 5; i++){
		arrayChar[i]=pp[i];
	}


	printf(" primer elemento del array arrayChar: %c\n", arrayChar[0]);

	printf(" primer elemento del puntero punteChar: %c\n", *punteChar);

	printf(" primer elemento del puntero punteroCharDos: %c\n", *punteroCharDos);
	//paso 7

	printf(" quinto elemento del array arrayChar: %c\n", arrayChar[4]);

	printf(" quinto elemento del puntero punteChar: %c\n", *(punteChar+4));

	// paso 10
	printf(" quinto elemento del puntero punteCharDos: %c\n", *(punteroCharDos+4));

	printf("\n");

	for (i = 0; i < 5; ++i)
	{
		printf("%c \t", *(punteroCharDos+i));
	}
	printf("\n\n");


	for (i = 0; i < 5; ++i)
	{
		printf("%c \t", *(punteroCharDos+i)); 
	}
	printf("\n\n");

	return 0;
}