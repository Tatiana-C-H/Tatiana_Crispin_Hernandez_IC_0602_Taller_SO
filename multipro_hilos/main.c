#include "scheduler.h"
#include <pthread.h>				// Se agrega la cabecera para poder manejar lo hilos poxis

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

int main(int argc, char const *argv[]){
	// Se crean los diferentes hilos (variables)
	pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;

	// Se les añaden los datos wue se pedian en la estructura PROCESS
	struct PROCESS parametro1 = {1, UN_SEGUNDO,   "Proceso_1", abrir_youtube, ACTIVO};
	struct PROCESS parametro2 = {1, DOS_SEGUNDOS, "Proceso_1", reproducir_musica, NO_ACTIVO};
	struct PROCESS parametro3 = {3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO}; 	
	struct PROCESS parametro4 = {4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO};
	struct PROCESS parametro5 = {3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO};
	struct PROCESS parametro6 = {4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO};
	struct PROCESS parametro7 = {0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO};
	struct PROCESS parametro8 = {2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO};
	/*
	Se crean los hilos a partir de pthread_create y contiene:
		el nombre/identificador que se la asigno
		los atributos, cuando se coloca null se dejan los de defualt
		la funcion/rutina, esta es necesaria convirtirla a void ya que la principal si retorna valores
		y el argumento de entrada, en este caso van el parametro correspondiente que contiene los datos como el id, el tiempo, su proceso y su estado
	 */
 	pthread_create( &thread1, NULL, (void*)crear_Proceso, &parametro1 );
 	pthread_create( &thread2, NULL, (void*)crear_Proceso, &parametro2 );
 	pthread_create( &thread3, NULL, (void*)crear_Proceso, &parametro3 );
 	pthread_create( &thread4, NULL, (void*)crear_Proceso, &parametro4 );
 	pthread_create( &thread5, NULL, (void*)crear_Proceso, &parametro5 );
 	pthread_create( &thread6, NULL, (void*)crear_Proceso, &parametro6 );
 	pthread_create( &thread7, NULL, (void*)crear_Proceso, &parametro7 );
 	pthread_create( &thread8, NULL, (void*)crear_Proceso, &parametro8 );

 	// pthread_join permite que los hilos finalizen, este debe contener
 	// identificador del hilo y su valor de retorno
	pthread_join( thread1, NULL );
	pthread_join( thread2, NULL );
	pthread_join( thread3, NULL );
	pthread_join( thread4, NULL );
	pthread_join( thread5, NULL );
	pthread_join( thread6, NULL );
	pthread_join( thread7, NULL );
	pthread_join( thread8, NULL );

 	// Se manda a llamar la funcion para crear los procesos
 	array_procesos *array = crear_ArrayProcesos();
    
    // se manda a llamar agregar_Proceso(array_procesos *_array, process _p)
	// en la primera entrada se coloca el aray y en la segunda el parametro
	agregar_Proceso( array, parametro1 );
	agregar_Proceso( array, parametro2 );
	agregar_Proceso( array, parametro3 );
    agregar_Proceso( array, parametro4 );
    agregar_Proceso( array, parametro5 );
    agregar_Proceso( array, parametro6 );
    agregar_Proceso( array, parametro7 );
    agregar_Proceso( array, parametro8 );

	// Se manda a llamar la funcion para la ejecucion de los procesos
	ejecutar_Procesos(array);

	//Mandamos un mensaje que indique que los hilos han finalizado
	printf(" Se han finalizado los threads.\n");
}

// Se colocan las acciones de los procesos

void reproducir_musica(void){
	printf(" Reproduciendo Música\n");
}

void abrir_youtube(void){
	printf(" Usando Youtube\n");
}

void escribir_texto_word(void){
	printf(" Escribiendo Texto en Word\n");
}

void descargar_archivo(void){
	printf(" Descargando Archivo\n");
}

void subiendo_archivo(void){
	printf(" Subiendo Archivo\n");
}

void compilando_programa(void){
	printf(" Compilando programa\n");
}

void ejecutando_programa(void){
	printf(" Ejecutando programa\n");
}

void usando_terminal(void){
	printf(" Usando la terminal\n");
}
