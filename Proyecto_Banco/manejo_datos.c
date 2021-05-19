#include "manejo_datos.h"   //Se manda a llamar el archivo .h principal.

//Funcion encargada de realizar la validación de la entrada de numeros enteros.
int Ventero(char Nentero[]);
char Nentero[5];
int Rentero;
int Ventero(char Nentero[]){
    for(int o=0; o<strlen(Nentero); o++){
        if(!(isdigit(Nentero[o]))){
            printf("\n\t Debe ingresar solamente numeros enteros, intentelo de nuevo.\n\n");
            return 0;
        }
    }
    return 1;
}

//Funcion encargada de realizar la validación de la entrada de cadenas de caracteres como el nombre de los paises o los clientes.
int Vpalabra(char Palabra[]);
char Palabra[20];
int Rpalabra;
int Vpalabra(char Palabra[]){
    for(int p=0; p<strlen(Palabra); p++){
        if(!(isalpha(Palabra[p]))){
            printf("\n\t Debe ingresar solamente palabras, intentelo de nuevo.\n\n");
            return 0;
        }
    }
    return 1;
}

//Funcion encargada de dar de alta a los paises y los clientes.
//Se declaran variables que utilizará la funcion y la función misma.
int altapais(int cantidad);
int cantidad,cantidad2;
int altapais(int cantidad){
    int res,pase,limite=5, limite2=5, flag2=0, flagval=0, ival=1, contador = 0;
    char paisval[20];
    do{
        do{
            printf(" Cuantos paises quieres dar de alta:\t");
            scanf("%s",Nentero);
            Rentero=Ventero(Nentero);
        }while(Rentero==0);
        cantidad=atoi(Nentero);
        fflush(stdin);
        //Aqui se hace una validacion de enteros y luego una validacion con el tamaño del vector declarado anteriormente.
        if(cantidad>limite){
            printf("\n Haz rebazado el limite de %d lugares, ingresa otro numero.\n\n", limite);
            pase=0;
        }
        else if(cantidad<=0){
            printf("\n\t Elige un numero mayor a cero.\n\n");
            pase=0;
        }
        else{
            res=0;
            for(res=1;res<=cantidad;res++){
                for(int i=1; i<=5;i++){
                    fflush(stdin);
                    if(banco[i].edo==0){
                        banco[i].id=i;
                        printf("\n ID del banco:\t%d \n",i);
                            do{
                                do{
                                    printf("\n\n Nombre del pais:\t");
                                    scanf("%s",Palabra);
                                    Rpalabra=Vpalabra(Palabra);
                                }while(Rpalabra==0);
                                strcpy( paisval, Palabra );
                                fflush(stdin);
                                //Se hace una validación de strings.
                                for(ival=1; ival<=5; ival++){
                                    if(strcmp(paisval, banco[ival].pais) == 0){//comparacion entre strings y char
                                        printf("\n\t Este nombre ya esta en uso, digita uno distinto\n");
                                        flagval=0;
                                        break;
                                    }
                                    else{
                                        flagval=1;
                                    }
                                }//termino del primer for
                            }while(flagval==0);
                        strcpy( banco[i].pais, paisval );//asignacion de valores de tipo string (destino, origen)
                        banco[i].edo=1;
                        fflush(stdin);
                            do{
                                do{
                                    printf("\n Cuantos clientes quieres dar de alta:\t");
                                    scanf("%s",Nentero);
                                    Rentero=Ventero(Nentero);
                                }while(Rentero==0);
                                cantidad2=atoi(Nentero);
                                fflush(stdin);
                                //validacion de umeros enteros y comparacion con el tamaño del vector.
                                if(cantidad2>limite2){
                                    printf("\n Haz rebazado el limite de %d lugares, ingresa otro numero.\n", limite2);
                                }
                                else if(cantidad2<=0){
                                    printf("\n Elige una cantidad mayor a cero.\n");
                                }
                                else{
                                    for(int i2=1; i2<=cantidad2; i2++){
                                        printf("\n\n\t CLIENTE [ %d ]  DEL BANCO [%d] \n",i2,i);
                                        do{
                                            printf("\n Nombre:\t");
                                            scanf("%s",Palabra);
                                            Rpalabra=Vpalabra(Palabra);
                                        }while(Rpalabra==0);
                                        strcpy( banco[i].cliente[i2].nombre, Palabra );
                                        fflush(stdin);
                                        /*Se leen los datos y se hacen validaciones, los nombres de los clientes se pueden repetir
                                        pero los nombres de los paises no.*/
                                        printf("\n Sexo:\t");
                                        scanf("%c",&banco[i].cliente[i2].sexo);
                                        printf("\n Saldo:\t");
                                        scanf("%f",&banco[i].cliente[i2].saldo);
                                        banco[i].cliente[i2].ocup=true;
                                        banco[i].cliente[i2].edocliente=1;
                                            if(banco[i].cliente[i2].ocup){
                                                printf("\n El cliente esta ocupado por el pais %s \n",banco[i].pais);
                                            }else{
                                                printf("\n El cliente no esta ocupado.\n");
                                            }
                                    }
                                    flag2=1;
                                }
                            }while(flag2==0);
                        limite--;
                        i=6;
                    }
                    else if(banco[5].edo==1){
                        printf("\n\tArray completo\t\n"); //Mensaje en caso de que el vector esté completo.
                        i=6;
                        res=5;
                    }
                    else{}
                }
            }
            pase=1;
        }
    }while(pase==0);
    return 1;
}

//Pertenece a la opcion 13 y se encarga de actualizar los datos de un cliente especifico.
int bajacliente(int bc);
int bc=13;
int bajacliente(int bc){
    char paisleer[20], nombreleer[20];
    int flagb=0, flagb2=0;
    bc=13;
    do{
        do{
            printf("\n Nombre del pais al que quieres acceder:\t");
            scanf("%s",Palabra);
            Rpalabra=Vpalabra(Palabra);
        }while(Rpalabra==0);
        strcpy( paisleer, Palabra );
        fflush(stdin);
        //Validación de enteros
        for(int ib=1; ib<=5; ib++){
            if(strcmp(paisleer, banco[ib].pais) == 0){
                do{
                    do{
                        printf("\n Nombre de la persona:\t");
                        scanf("%s",Palabra);
                        Rpalabra=Vpalabra(Palabra);
                    }while(Rpalabra==0);
                    strcpy( nombreleer, Palabra );
                    fflush(stdin);
                    //Validacion de strings y asignaciones con strcpy.
                        for(int ib2=1; ib2<=5; ib2++){
                            if(strcmp(nombreleer, banco[ib].cliente[ib2].nombre) == 0){
                                do{
                                    printf("\n Nombre de la persona:\t");
                                    scanf("%s",Palabra);
                                    Rpalabra=Vpalabra(Palabra);
                                }while(Rpalabra==0);
                                strcpy( banco[ib].cliente[ib2].nombre, Palabra );
                                fflush(stdin);
                                //Validacion de strings
                                printf("\n Nuevo sexo:\t");
                                    scanf("%c",&banco[ib].cliente[ib2].sexo);
                                printf("\n Nuevo saldo:\t");
                                    scanf("%f",&banco[ib].cliente[ib2].saldo);
                                printf("\n El cliente  %s  ha sido actualizado a  %s\n",nombreleer,banco[ib].cliente[ib2].nombre);
                                flagb=1;        ib2=6;
                            }
                            else{    }
                        }
                        flagb2=1;
                    }while(flagb2==0);
            }
            else{
                flagb=0;
            }
        }
    }while(flagb==0);
    return 1;
}

//Funcion encargada de eliminar los clientes, este al encontrar al cliente requeriso lo que hace es que modifica el booleano
//de ocupado a desocupado (false) ademas de que cambia su estado a 0
int eliminarcliente(ec);
int ec=2, nuevoI=2;
int eliminarcliente(int ec){
    char paisleer[20], nombreleer[20];
    int flagb=0, flagb2=0;
    ec=2;
    do{
        do{
            printf("\n Nombre del pais al que quieres acceder:\t");
            scanf("%s",Palabra);
            Rpalabra=Vpalabra(Palabra);
        }while(Rpalabra==0);
        strcpy( paisleer, Palabra );
        fflush(stdin);
        //Validacion de string
        for(int ib=1; ib<=5; ib++){
            if(strcmp(paisleer, banco[ib].pais) == 0){
                do{
                    do{
                        printf("\n Nombre de la persona:\t");
                        scanf("%s",Palabra);
                        Rpalabra=Vpalabra(Palabra);
                    }while(Rpalabra==0);
                    strcpy( nombreleer, Palabra );
                    fflush(stdin);
                    //Validacion de string
                        for(int ib2=1; ib2<=5; ib2++){
                            if(strcmp(nombreleer, banco[ib].cliente[ib2].nombre) == 0){
                                banco[ib].cliente[ib2].ocup = false;
                                banco[ib].cliente[ib2].edocliente = nuevoI;
                                printf("\n Cliente dado de baja con exito.\n");
                                flagb=1;        ib2=6;
                            }
                            else{
                                printf("\n Este nombre no existe\n");
                                flagb2=0;        ib2=6;
                            }
                        }
                        flagb2=1;
                    }while(flagb2==0);
                flagb=1;        ib=6;
            }
            else{
                printf("\n Este nombre no existe\n");
                flagb=0;
            }
        }
        flagb=1;
    }while(flagb==0);
    return 1;
}

//Este muestra todos los clientes, esten dados de bja o sigan activos,
//tambien muestra aquellos lugares vacios que pertenecerian a clientes dados de alta
int mostrartodos(mt);
int mt=3;
int mostrartodos(int mt){
    mt=3;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            printf("\n\n\t\t Pais  %d  %s\n", ib, banco[ib].pais);
            for(int ib2=1; ib2<=5; ib2++){
                printf("\n\n\t Nombre del cliente [ %i ] :\t %s", ib2, banco[ib].cliente[ib2].nombre);
                printf("\n\t sexo:\t %c", banco[ib].cliente[ib2].sexo);
                printf("\n\t Saldo:\t %.2f", banco[ib].cliente[ib2].saldo);
                    if(banco[ib].cliente[ib2].ocup){
                        printf("\n\t El estado del cliente es ocupado. \n");
                    }else{
                        printf("\n\t El cliente no esta ocupado y esta dado de baja\n");
                    }
            }

        }
        else{
            ib=6;
        }
    }
    if(banco[1].edo == 0){
        printf("\n\t Aun no hay datos.\n");
    }
    return 1;
}

//Despues de ingresar a un pais especifico el usuario digita el nombre del cliente especifico y muetsra datos generales
//y tambien si esta ocupado o no
int mostrarespecifico(me);
int me=4;
int mostrarespecifico(int me){
    char paisleer[20], nombreleer[20];
    int flagb = 0, flagb2 = 0;
    me = 4;
    do{
        do{
            printf("\n Nombre del pais al que quieres acceder:\t");
            scanf("%s",Palabra);
            Rpalabra=Vpalabra(Palabra);
        }while(Rpalabra==0);
        strcpy( paisleer, Palabra );
        fflush(stdin);
        for(int ib=1; ib<=5; ib++){
            if(strcmp(paisleer, banco[ib].pais) == 0){
                do{
                    do{
                        printf("\n Nombre de la persona:\t");
                        scanf("%s",Palabra);
                        Rpalabra=Vpalabra(Palabra);
                    }while(Rpalabra==0);
                    strcpy( nombreleer, Palabra );
                    fflush(stdin);
                        for(int ib2=1; ib2<=5; ib2++){
                            if(strcmp(nombreleer, banco[ib].cliente[ib2].nombre) == 0){
                                printf("\n\n\t Este cliente pertenece al pais de  %s", banco[ib].pais);
                                printf("\n\t Nombre:\t %s", banco[ib].cliente[ib2].nombre);
                                printf("\n\t sexo:\t %c", banco[ib].cliente[ib2].sexo);
                                printf("\n\t Saldo:\t %.2f", banco[ib].cliente[ib2].saldo);
                                    if(banco[ib].cliente[ib2].ocup){
                                        printf("\n\t El estado del cliente es ocupado. %s \n");
                                    }else{
                                        printf("\n El cliente no esta ocupado y esta dado de baja\n");
                                    }
                                flagb=1;        ib2=6;
                            }
                            else{
                                printf("\n Este nombre no existe\n");
                                flagb2=0;        ib2=6;
                            }
                        }
                        flagb2=1;
                    }while(flagb2==0);
                flagb=1;        ib=6;
            }
            else{
                printf("\n Este nombre no existe\n");
                flagb=0;
            }
        }
        flagb=1;
    }while(flagb==0);
    return 1;
}

//Funcion que solo muetsra aquellos clientes ocupados
int mostraralta(ma);
int ma=5;
int mostraralta(int ma){
    ma=5;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            printf("\n\n\t\t Pais  %d  %s\n", ib, banco[ib].pais);
            for(int ib2=1; ib2<=5; ib2++){
                if(banco[ib].cliente[ib2].edocliente == 1){
                    printf("\n\n\t Nombre del cliente [ %i ] :\t %s", ib2, banco[ib].cliente[ib2].nombre);
                    printf("\n\t sexo:\t %c", banco[ib].cliente[ib2].sexo);
                    printf("\n\t Saldo:\t %.2f", banco[ib].cliente[ib2].saldo);
                        if(banco[ib].cliente[ib2].ocup){
                            printf("\n\t El estado del cliente es ocupado. \n");
                        }else{
                            printf("\n\t El cliente no esta ocupado y esta dado de baja\n");
                        }

                }
                else{}
            }
        }
        else{
            ib=6;
        }
    }
    return 1;
}

//Permite abonar saldo a un cliente especifico y actualiza su saldo
//mostrando antes el saldo anterios, el abono y el saldo final
int abonarsaldo(as);
int as=6;
int abonarsaldo(int as){
    char paisleer[20], nombreleer[20];
    int flagb=0, flagb2=0;
    float saldoleer=0, operacion=0;
    as=6;
    do{
        do{
            printf("\n Nombre del pais al que quieres acceder:\t");
            scanf("%s",Palabra);
            Rpalabra=Vpalabra(Palabra);
        }while(Rpalabra==0);
        strcpy( paisleer, Palabra );
        fflush(stdin);
        for(int ib=1; ib<=5; ib++){
            if(strcmp(paisleer, banco[ib].pais) == 0){
                do{
                    do{
                        printf("\n Nombre de la persona:\t");
                        scanf("%s",Palabra);
                        Rpalabra=Vpalabra(Palabra);
                    }while(Rpalabra==0);
                    strcpy( nombreleer, Palabra );
                    fflush(stdin);
                        for(int ib2=1; ib2<=5; ib2++){
                            if(strcmp(nombreleer, banco[ib].cliente[ib2].nombre) == 0){
                                printf("\n Digita la cantidad de saldo que quieres agregar:\t");
                                    scanf("%f",&saldoleer);
                                    operacion = saldoleer + banco[ib].cliente[ib2].saldo;
                                printf("\n El cliente  %s  ha sido actualizado:",nombreleer);
                                printf("\n El saldo  %.2f  con un abono de  %.2f  se actualizo a  %.2f", banco[ib].cliente[ib2].saldo, saldoleer, operacion);
                                banco[ib].cliente[ib2].saldo = operacion;
                                flagb=1;        ib2=6;
                            }
                            else{
                                printf("\n Este nombre no existe\n");
                                flagb2=0;        ib2=6;
                            }
                        }
                        flagb2=1;
                    }while(flagb2==0);
                flagb=1;        ib=6;
            }
            else{
                printf("\n Este nombre no existe\n");
                flagb=0;
            }
        }
        flagb=1;
    }while(flagb==0);
    return 1;
}

//Permite retirar saldo a un cliente especifico y actualiza su saldo
//mostrando antes el saldo anterior, el retiro y el saldo final
//y tambien valida que el retiro no sea 0 o mas de lo que se tiene de saldo actual
int retirarsaldo(rs);
int rs=7;
int retirarsaldo(int rs){
    char paisleer[20], nombreleer[20];
    int flagb=0, flagb2=0, flagM=0;
    float saldoleer=0, operacion=0;
    rs=7;
    do{
        do{
            printf("\n Nombre del pais al que quieres acceder:\t");
            scanf("%s",Palabra);
            Rpalabra=Vpalabra(Palabra);
        }while(Rpalabra==0);
        strcpy( paisleer, Palabra );
        fflush(stdin);
        for(int ib=1; ib<=5; ib++){
            if(strcmp(paisleer, banco[ib].pais) == 0){
                do{
                    do{
                        printf("\n Nombre de la persona:\t");
                        scanf("%s",Palabra);
                        Rpalabra=Vpalabra(Palabra);
                    }while(Rpalabra==0);
                    strcpy( nombreleer, Palabra );
                    fflush(stdin);
                        for(int ib2=1; ib2<=5; ib2++){
                            if(strcmp(nombreleer, banco[ib].cliente[ib2].nombre) == 0){
                                do{
                                    printf("\n Digita la cantidad de saldo que quieres agregar:\t");
                                    scanf("%f",&saldoleer);
                                    if(saldoleer<=banco[ib].cliente[ib2].saldo){
                                        operacion = banco[ib].cliente[ib2].saldo - saldoleer;
                                        printf("\n El cliente  %s  ha sido actualizado:",nombreleer);
                                        printf("\n El saldo  %.2f  con un retiro de  %.2f  se actualizo a  %.2f", banco[ib].cliente[ib2].saldo, saldoleer, operacion);
                                        banco[ib].cliente[ib2].saldo = operacion;
                                        flagM=1;
                                    }
                                    else{
                                        printf("\n Digita una cantidad valida.\n");
                                        flagM=0;
                                    }

                                }while(flagM==0);
                                flagb=1;        ib2=6;
                            }
                            else{
                                printf("\n Este nombre no existe\n");
                                flagb2=0;        ib2=6;
                            }
                        }
                        flagb2=1;
                    }while(flagb2==0);
                flagb=1;        ib=6;
            }
            else{
                printf("\n Este nombre no existe\n");
                flagb=0;
            }
        }
        flagb=1;
    }while(flagb==0);
    return 1;
}

//Realiza un recorrido de los vectores y a partir de contabilizar los lugares vacios los enlista
//y muestra a qué pais dado de alta pertencen o a que indice de paises y clientes pertenece
//los clientes dados de baja aun son conservados y no cuentan como un indice vacio
int indicevacio(iv);
int iv=8;
int indicevacio(int iv){
    iv=8;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            printf("\n\n\t El pais  %d  que corresponde a  %s  tiene los siguientes datos:\n", ib, banco[ib].pais);
            for(int ib2=1; ib2<=5; ib2++){
                if(banco[ib].cliente[ib2].edocliente == 0){
                    printf("\n\t Indice  %d  vacio. \n", ib2);
                }else{   }
            }

        }
        else{
            printf("\n\n\t El pais  %d  esta vacio y tiene los siguientes datos:\n", ib);
            for(int ib3=1; ib3<=5; ib3++){
                if(banco[ib].cliente[ib3].edocliente == 0){
                    printf("\n\t Indice  %d  vacio. \n", ib3);
                }else{   }
            }
        }
    }
    return 1;
}

//Realiza un recorrido de los vectores y a partir de contabilizar los lugares llenos
//manda un mensaje de si es que todo el vector esta lleno o esta incompleto
int estructurallena(el);
int el=9;
int estructurallena(int el){
    el=9;   int contador = 0;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            for(int ib2=1; ib2<=5; ib2++){
                if(banco[ib].cliente[ib2].edocliente != 0){
                    contador = contador+1;
                }else{   }
            }
        }
        else{
            printf("\n\t La estructura no esta completamente llena.\n");
            ib = 6;
        }
    }
    if(contador>=5){
        printf("\n\t La estructura esta completamente llena.\n");
    }
    else{}
    return 1;
}

//Realiza un recorrido de los vectores y a partir de contabilizar los lugares llenos
//manda un mensaje de si es que todo el vector esta vacio o esta incompleto
int estructuravacia(ev);
int ev=10;
int estructuravacia(int ev){
    el=10;   int contador = 0;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 0){
            for(int ib2=1; ib2<=5; ib2++){
                if(banco[ib].cliente[ib2].edocliente == 0){
                    contador = contador+1;
                }else{   }
            }
        }
        else{
            printf("\n\t La estructura no esta completamente vacia.\n");
            ib = 6;
        }
    }
    if(contador>=5){
        printf("\n\t La estructura esta completamente vacia.\n");
    }
    else{}
    return 1;
}

//Realiza un recorrido de los vectores y a partir de contabilizar los lugares llenos en los paises
//manda un mensaje enlistando los nombres de estos
int nombrepaises(np);
int np=11;
int nombrepaises(int np){
    np=11;     int contador = 0;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            printf("\n\t El pais  %d  corresponde a  %s. \n", ib, banco[ib].pais);
        }
        else{
            contador = contador + 1;
        }
    }
    if(contador >= 5){
        printf("\n\t Aun no hay paises dados de alta.\n");
    }
    else{   }
    return 1;
}

//Realiza un recorrido de los vectores y a partir de contabilizar los lugares llenos en los paises y clientes
//manda un mensaje enlistando los nombres de estos y cuantos clientes tiene cada unos
int longitudes(ls);
int ls=12;
int longitudes(int ls){
    ls=12;   int contador = 0;
    for(int ib=1; ib<=5; ib++){
        if(banco[ib].edo == 1){
            for(int ib2=1; ib2<=5; ib2++){
                if(banco[ib].cliente[ib2].edocliente != 0){
                    contador = contador+1;
                }else{   }
            }
            printf("\n\t El pais  %s  tiene  %d  clientes.\n", banco[ib].pais, contador);
            contador = 0;
        }
        else{        }
    }
    if(banco[1].edo == 0){
        printf("\n\t Aun no se dan de alta clientes.\n");
    }
    else{}
    return 1;
}
