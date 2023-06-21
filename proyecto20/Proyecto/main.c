#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include <time.h>
#define ESC 27

void muestraArchivo(char nombreArchivo[]);
void muestraArchivoCuenta(char nombreArchivoCuenta[]);
void menuGeneral();
void muestraArchivoMov(char nombreArchivoMov[]);

int main()
{

    menuGeneral();

    return 0;
}

// ESTA FUNCION MANEJA TODO EL PROGRAMA
void menuGeneral(){
    char opSalir;
    int opcion=0;


    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 1:
            darAltaCliente(ARCHI_CLIENTE,ARCHI_CUENTA);
            break;
        case 2:
            do{
            bajaCliente();
            printf("\n Ingrese ESC para volver al menu principal");
            printf("\n O ingrese ENTER para dar de baja otro DNI");
            opSalir=getch();
            }while(opSalir!=ESC);
            break;
        case 3:
            break;
        case 4:
            do{
            buscarCliente();
            printf("\n Ingrese ESC para volver al menu");
            opSalir=getch();
            }while(opSalir!=ESC);
            break;
        case 5:
            do{
            muestraArchivo(ARCHI_CLIENTE);
            muestraArchivoCuenta(ARCHI_CUENTA);
            printf("\n Ingrese ESC para volver al menu");
            opSalir=getch();
            }while(opSalir!=ESC);
            break;
        case 6:
            do{
            muestraArchivoMov(ARCHI_MOVIMIENTOS);
            printf("\n Ingrese ESC para volver al menu");
            opSalir=getch();
            }while(opSalir!=ESC);
            break;
        case 7:
            hacerMovMenu();
            break;
        case 8:
            do{
                movimientoPorFecha();
                printf("\n Ingrese ESC para volver al menu");
                printf("\n O ENTER para buscar otro MOVIMIENTO");
                opSalir=getch();
            }while(opSalir!=ESC);
            break;
        case 9:
            do{
                cargarRandom();
                moviemientoRand();
                printf("\n Ingrese ESC para salir");
                opSalir=getch();
            }while(opSalir!=ESC);
            break;
        }
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
    }while(opSalir!=ESC);
}

// ABAJO SE ENCUENTRAN LAS FUNCION PARA MOSTRAR EL TOTAL DE UN ARCHIVO
void muestraArchivo(char nombreArchivo[]){
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&cliente,sizeof(stCliente),1,archi)>0){
            mostrarCliente(cliente);
        }
        fclose(archi);
    }
}

void muestraArchivoCuenta(char nombreArchivoCuenta[]){
    stCuenta cuenta;
    FILE* archiCuenta=fopen(nombreArchivoCuenta,"rb");
    if(archiCuenta){
        while(fread(&cuenta,sizeof(stCuenta),1,archiCuenta)>0){
            mostrarCuenta(cuenta);
        }
        fclose(archiCuenta);
    }
}

void muestraArchivoMov(char nombreArchivoMov[]){
    stMovimiento movimiento;
    FILE* archiMov=fopen(nombreArchivoMov,"rb");
    if(archiMov){
        while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0){
            mostrarMovimiento(movimiento);
        }
        fclose(archiMov);
    }
}


