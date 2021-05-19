#ifndef __MANEJO_DATOS_H
#define __MANEJO_DATOS_H

//Se agregan las cabeceras que se utilizarán de manera general en el programa.

#include<stdio.h>
#include<string.h>
#include<stdbool.h>


/*Creación de las estructuras cliente y banco, donde se muestran los atributos de cada uno,
    tambien se crean sus variables con el tamaño del vector correspondiente*/

struct cliente{
    char nombre[20];
    char sexo;
    float saldo;
    bool ocup;
    int edocliente;
}cliente[5];

struct banco{
    int id;
    char pais[20];
    struct cliente cliente[5];
    int edo;
}banco[5];


#endif
