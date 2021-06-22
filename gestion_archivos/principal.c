
#include "iniciales.h"	
#include "movimientos.c"


// funcion principal
void control (char origen[],char destino1[]){
    lista lista=NULL;

	FILE *arch;

	FILE *destt;

	char linea[TAM];

	arch=fopen(origen,"r+");			// con r+ Abre un archivo para actualización (lectura y escritura).
	destt=fopen(NOMBRE_ARCHIVO,"w+");	// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.

	// permite nombrar al archivo
	printf("\n\t Archivo \t = \t %s \n\n",origen);
	// inicio para listado
	printf("\n\n\t Lista: \n");


	// permite saber si no se ha alcanzado el final del archivo que se pasa como argumento
	// suele devolver un 0
	//while(!feof(arch))
	while(!feof(arch)){
		// fputs without the length param just writes all data up to but not including the first 0 byte it encounters
		// aka fwrite()
		fputs(linea,stdout);

		// Analiza la entrada desde un archivo de acuerdo a un formato
		// Cada llamada a fscanf() lee una línea del archivo
		// se elige linea para poder relacionar mejor el nombre
		fscanf(arch,"%s ",linea);
		
		//fputs(,);
		fputs(linea,destt);
		fputs("\n",destt);

		// coloca n la lista las lineas analizadas en fscanf
		insertar(&lista,linea);
	}

	// encargado de cerrar un puntero a un archivo abierto
	//fclose();
	fclose(arch); 			//se cierra el archivo principal
	fclose(destt); 			//se cierra el archivo destino

	// metodos de movimientos.c
	mostrarlista(lista);
	borrarlista(&lista);

	// printf("\n\n\t\t fin \n\n");
	printf("\n\n\t\t Lista terminada \n\n");

	// se almacenan las palabras
	// se toma en cuenta la longitud y la cantidad dada en iniciales.c
	char palabras[CANTIDAD_PALABRAS][MAXIMA_LONGITUD_CADENA];
	char buferArchivo[MAXIMA_LONGITUD_CADENA];

	// se encarga de abrir un fichero
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "r+");
    
    // si no se encuntra el archivo se manda un mensaje del error
    if (archivo == NULL){
        printf("\n\tEl archivo no se puede abrir\n");   
    }
	    // indice para las lineas
	    int indice = 0;

    // mientras se lea/consiga una linea from archivo
    while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo)){
        // se divide la cadena para quitar saltos
        strtok(buferArchivo, "\n");
        // Copia los valores de num bytes de la ubicación apuntada por la fuente directamente al bloque de memoria apuntado por el destino
        // se coloca el desino - fuente - num
        // se copian las lineas a partir del indice (su ubicacion)
        memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
        indice++;
    }

    // se abre el archivo destino
    FILE *destino = fopen(destino1, "w+");
    // el principal se cierra
	fclose(archivo);

	// la forma de ordenamiento puede ser burbuja, qsort, gnome, cocktail, ...
	// primero se mide la longitud a partir del vector que contiene las lineas
	// ademas de vars para iteracion y determinar cuando se termina el recorrido
	int longitud=sizeof(palabras)/sizeof(palabras[0]);
	int i=0;
	int s=CANTIDAD_PALABRAS-indice;
	// se hace un ordenamiento y una imprsion conforme se vaya haciendo el acomo tras iteracion
	// qsort(void *base, size_t nel, size_t size, int (*compar)(const void *, const void *));
    qsort((void*)palabras,longitud,sizeof(palabras[0]),comparar);    
	    for (i =s-1; i < longitud-1; i++){
			printf("%s\n", palabras[i]);
			fputs(palabras[i],destino);
	        fputs("\n",destino);
	    }
	//se cierra el destino
	fclose(destino);

	// printf("\n\n\t\t Destino \t = \t %s",destino1);
	printf("\n\n\t\t Archivo destino \t = \t %s",destino1);
}
