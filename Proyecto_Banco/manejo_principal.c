#include "manejo_datos.c"       //se manda a llamar el archivo que contiene las funciones principales


//Se crea una funcion vacia que contiene el menu principal del programa
//este está hecho a partir de una estructura switch-case

void iniciar_banco(void){
    int flag=1,opcion;
    do{
        printf("\n\n********************************************************************************\n");
        printf("\tEste es un simulador basico de un banco.\n");
        printf("\n 1.- Dar de alta clientes.");
        printf("\n 2.- Dar de baja clientes.");
        printf("\n 3.- Mostrar todos los clientes.");
        printf("\n 4.- Mostrar cliente en especifico.");
        printf("\n 5.- Mostrar solo clientes dados de alta.");
        printf("\n 6.- Abonar saldo a cliente.");
        printf("\n 7.- Retirar saldo de cliente.");
        printf("\n 8.- Buscar indice vacio en toda la estructura.");
        printf("\n 9.- Mostrar si esta toda llena la estructura.");
        printf("\n 10.- Mostrar si esta toda vacia la estructura.");
        printf("\n 11.- Mostrar nombre de paises.");
        printf("\n 12.- Mostrar longitudes.");
        printf("\n 13.- Actualizar datos de cliente especifico.");
        printf("\n 14.- Salir.");
        do{
            printf("\n\n Elija una opcion del menu:\t");
            scanf("%s",Nentero);
            Rentero=Ventero(Nentero);
        }while(Rentero==0);
        opcion=atoi(Nentero);
        fflush(stdin);
        printf("\n********************************************************************************\n");
        switch(opcion){
            case 1:
                altapais(cantidad);
            break;
            case 2:
                eliminarcliente(ec);
            break;
            case 3:
                mostrartodos(mt);
            break;
            case 4:
                mostrarespecifico(me);
            break;
            case 5:
                mostraralta(ma);
            break;
            case 6:
                abonarsaldo(as);
            break;
            case 7:
                retirarsaldo(rs);
            break;
            case 8:
                indicevacio(iv);
            break;
            case 9:
                estructurallena(el);
            break;
            case 10:
                estructuravacia(ev);
            break;
            case 11:
                nombrepaises(np);
            break;
            case 12:
                longitudes(ls);
            break;
            case 13:
                bajacliente(bc);//13.- Actualizar datos de cliente especifico.
            break;
            case 14:
                printf("\t Gracias por interactuar, hasta pronto.\n");        flag=0;
                printf("\n********************************************************************************\n");
            break;
            default:
                printf("\t No eligio una opcion valida, intentelo de nuevo");
            break;
        }
    }while(flag==1);
}

//
