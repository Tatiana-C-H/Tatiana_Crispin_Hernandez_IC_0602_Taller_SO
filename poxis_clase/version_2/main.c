#include "scheduler.h"

void *proceso_general(void *params);

int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1::reproducir_musica", proceso_general, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1::abrir_youtube", proceso_general, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2::escribir_texto_word", proceso_general, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3::descargar_archivo", proceso_general, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4::subiendo_archivo", proceso_general, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5::compilando_programa", proceso_general, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6::ejecutando_programa", proceso_general, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7::usando_terminal", proceso_general, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8::usando_terminal", proceso_general, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

void *proceso_general(void *params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}
