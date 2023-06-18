#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

#define ESC 27

int mostrarOpciones(){
    int i=0;
    printf("\n ==========================================");
    printf("\n 1 = Para dar de ALTA cliente");
    printf("\n 2 = Para dar de BAJA cliente");
    printf("\n 3 = Para MODIFICAR un cliente");
    printf("\n 4 = Para MOSTRAR un cliente");
    printf("\n 5 = Para MOSTRAR TODOS los cliente");
    printf("\n 6 = Para mostrar MOVIMIENTO de un cliente");
    printf("\n ==========================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

void darAltaCliente(char nombreArchivo[],char nombreCuentaArchi[]){
    stCliente cliente;
    stCuenta cuenta;
    char op;
    char dni[12];
    int opcion=0;
    int flag=0;
    FILE* archi=fopen(nombreArchivo,"a+b");
    FILE* archiCuenta=fopen(nombreCuentaArchi,"a+b");
    if(archi && archiCuenta){
        while(op!=ESC){
            system("cls");
            printf("\n Ingrese el DNI a cargar: ");
            fflush(stdin);
            gets(dni);
            flag=buscarDni(archi,dni);
            if(flag==0){
                cliente=cargarCliente();
                fseek(archi,sizeof(stCliente)*(-1),SEEK_END);
                fwrite(&cliente,sizeof(stCliente),1,archi);
                opcion=mostrarOpcionDeCuenta();
                switch(opcion){
                case 1:
                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
                    break;
                case 2:
                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
                    break;
                case 3:
                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
                    break;
                }
            }else{
                printf("\n El DNI ingresado ya se encuentra en la base de datos");
            }
            printf("\n Ingresa ESC para volver al menu principal");
            printf("\n Ingresa ENTER para intentar con otro DNI");
            op=getch();
            fclose(archi);
            fclose(archiCuenta);
            FILE* archi=fopen(nombreArchivo,"a+b");
            FILE* archiCuenta=fopen(nombreCuentaArchi,"a+b");
        }
        fclose(archi);
        fclose(archiCuenta);
    }
}

int buscarDni(char nombreArchivo[], char dni[10]){
    int flag=0;
    stCliente cliente;

    while(flag==0 && fread(&cliente,sizeof(stCliente),1,nombreArchivo)>0){
                if(strcmp(cliente.dni,dni)==0){
                    flag=1;
                }
            }
    return flag;
}
int validarPorDni(){
    int flag=0;



    return flag;
}
