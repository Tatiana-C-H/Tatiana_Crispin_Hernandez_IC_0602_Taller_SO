#include<stdio.h>
#include<conio.h>
#include<string.h>

int validar_numero(char numero[]);
char numero[5];
int N;

int validar_numero(char numero[]){
    int o;
    for(o=0; o<strlen(numero); o++){
        if(!(isdigit(numero[o]))){
            printf("\n\t Debe ingresar solamente numeros enteros, intentelo de nuevo\n\n");
            return 0;
        }
    }
    return 1;
}

int main(){
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
    float average_wait_time, average_turnaround_time;

    do{
        printf("\nDigite el numero de procesos:\t");
        scanf("%s",numero);
        N=validar_numero(numero);
    }while(N==0);
    limit=atoi(numero);
    x = limit;

    for(i = 0; i < limit; i++){
        printf("\n\n\t PROCESO  [%d]\n\n", i + 1);
        do{
            printf("\nDigite el tiempo de arrivo:\t");
            scanf("%s",numero);
            N=validar_numero(numero);
        }while(N==0);
        arrival_time[i]=atoi(numero);
        do{
            printf("\nDigite el tiempo de ejecucion:\t");
            scanf("%s",numero);
            N=validar_numero(numero);
        }while(N==0);
        burst_time[i]=atoi(numero);
        temp[i] = burst_time[i];
    }

    do{
        printf("\n\nDigite el tamaño del Quantum:\t");
        scanf("%s",numero);
        N=validar_numero(numero);
    }while(N==0);
    time_quantum=atoi(numero);

    printf("\n\n\nProceso   \t\tT. de Ejecucion\tT. Turnaround\tT. de Espera\n");

    for(total = 0, i = 0; x != 0;){
        if(temp[i] <= time_quantum && temp[i] > 0){
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0){
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1){
            x--;
            printf("\n\nProceso[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            counter = 0;
        }
        if(i == limit - 1){
            i = 0;
        }
        else if(arrival_time[i + 1] <= total){
            i++;
        }
        else{
            i = 0;
        }
    }

    average_wait_time = wait_time * 1.0 / limit;
    average_turnaround_time = turnaround_time * 1.0 / limit;
    printf("\n\n\nPromedio del tiempo de espera:\t%f", average_wait_time);
    printf("\n\nPromedio de tiempo de Turnaround (retorno):\t%f\n", average_turnaround_time);
    return 0;
}
