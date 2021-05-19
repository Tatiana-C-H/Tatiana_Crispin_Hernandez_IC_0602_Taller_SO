#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

char x='x';
char* p=&x;

char r;

char y='y';
char* puntero=&y;


int main()
{
	//printf(" Contenido de p: %s \n", *p);
	printf(" Contenido de p: %d \n", *p);
	//printf(" Direccion de p: %p \n", *puntero);

	*p+=1;
	//printf("\n Contenido de p: %s \n", *p);
	printf("\n Contenido de p: %d \n", *p);

	r = *p+2;
	//printf("\n Contenido de p: %s \n", *p);
	printf("\n Contenido de p: %d \n", r);

	//printf("\n Contenido de p: %s \n", *puntero);
	printf("\n Contenido de p: %d \n", *puntero);

	return 0;
}