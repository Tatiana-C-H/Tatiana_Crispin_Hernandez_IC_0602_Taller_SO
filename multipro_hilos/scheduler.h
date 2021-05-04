#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>			// Se agrega la cabecera para poder manejar hilos poxis

#define MAX_STRING				100
#define MAX_PROCESOS			100

#define UN_SEGUNDO				1
#define DOS_SEGUNDOS			2
#define TRES_SEGUNDOS			3
#define CUATRO_SEGUNDOS			4
	
#define ACTIVO 					1
#define NO_ACTIVO				0

int cont_procesos;				// Se sigue manteniendo el contador de procesos

typedef struct PROCESS process;					// Se mantiene la estructura
typedef struct ARRAY_PROCESS array_procesos;	// y el array

/* Puntero a función que no retorna y no recibe nada. */
typedef void (*FN_ACCION)(void); 

// Definición de la estructura PROCESS
struct PROCESS{
	int id;
	int delay;
	char nombrePROCESO[MAX_STRING];
	FN_ACCION proceso_realizar;
	int estado;
};

struct ARRAY_PROCESS{
	process proceso;
	int empty;
};

void crear_Proceso(struct PROCESS *_p);			//en lugar de llamar cada parte de la estructura se llama completa
void agregar_Proceso(array_procesos *_array, process _p);
void ejecutar_Procesos(array_procesos *_array);

array_procesos *crear_ArrayProcesos(void);

#endif