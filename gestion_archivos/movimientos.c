// encargado de insertar en lista lo que se va leyendo
// se utiliza puntero porque en principal se toma como objeto
void insertar(lista *lista,char p[TAM]){
	//estructura
	pnodo nuevo,anterior;
	// se reserva un espacio en memoria a partir de nodo
	nuevo=(pnodo)malloc(sizeof(tiponodo));
	//se copia la valor
	strcpy(nuevo->valor,p);
	// si la lista esta vacia (se devuelve null) pero por el puntero
	// se manda a sigueinte tomado en cuenta el punter
	if(listavacia(*lista)){
		nuevo->siguiente=*lista;
		*lista=nuevo;
	}
	// si no se hace un ajuste para cambiar las posiciones
	else{
		anterior=*lista;
		while(anterior->siguiente)
	    	anterior=anterior->siguiente;
		nuevo->siguiente=anterior->siguiente;
		anterior->siguiente=nuevo;
	}
}

// se encarga de estar limpiando lista
void borrarlista(lista *lista){
	pnodo nodo;
	// se hace un recorrido como al insertar
	while(*lista){
	    nodo=*lista;
	    *lista=nodo->siguiente;
	    free(nodo);
	}
}

// se usa en la comparacion para insertar y mostrar
int listavacia(lista lista){
   return(lista==NULL);
}


// si se obtiene un null en el contenido
void mostrarlista(lista lista){
	pnodo nodo=lista;
	if(listavacia(lista))
		// printf("\n\t Null \n");
	    printf("\n\t La lista esta vacia \n");
	else{
		//printf("\n\n\n\t\t Error \n" );
	    printf("\n\n\n\t\t La lista no se ordeno \n" );
	    // recorrido para mostrar añadiendo un salto
	    while(nodo){
	    	printf("%s \n",nodo->valor);
	    	nodo=nodo->siguiente;
	    	int a=0;
	    }
	}
}


// es de
// compara
int comparar(const void *a, const void *b){
	const char *cp1 = a, *cp2 = b;
    for (; toupper(*cp1) == toupper(*cp2); cp1++, cp2++)
        if (*cp1 == '\0')
            return 0;
    return ((toupper(*cp1) < toupper(*cp2)) ? -1 : +1);
}
