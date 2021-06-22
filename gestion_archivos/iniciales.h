#ifndef __ESTRUCTURA__
#define __ESTRUCTURA__

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TAM 25
#define MAXIMA_LONGITUD_CADENA 1000
#define CANTIDAD_PALABRAS 100

#define NOMBRE_ARCHIVO "destt.txt"

typedef struct nodo{
	char valor[TAM];
	struct nodo *siguiente;
}tiponodo;
typedef tiponodo *pnodo;
typedef tiponodo *lista;

// se inicializan los metodos
// metodos de movimientos.c
void insertar(lista *l,char p[TAM]);
void borrar(lista *l,int v);
int listavacia(lista l);
void borrarlista(lista *);
void mostrarlista(lista l);
void burbuja(char arreglo[][MAXIMA_LONGITUD_CADENA],int longitud);
int comparar(const void *a, const void *b);
void control (char origen[],char destino1[]);


#endif
