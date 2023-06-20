#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include <time.h>
#define ESC 27


void cargarArchivoCliente(char nombreArchivo[], int dim);
void muestraArchivo(char nombreArchivo[]);
void muestraArchivoCuenta(char nombreArchivoCuenta[]);
void menu();
void menuGeneral();
void muestraArchivoMov(char nombreArchivoMov[]);

int main()
{
    menuGeneral();

    return 0;
}
void menuGeneral(){
    char opSalir;
    int opcion=0;
    int flag=0;

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
        }
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
    }while(opSalir!=ESC);
}

/*void menu(){
    char opSalir;
    int opcCliente =0;

    do{
        system("cls");
        printf("\n Para REGISTRARSE ingrese:...1");
        printf("\n Para LOGEARSE ingrese:......2\n");
        scanf("%d", &opcCliente);
        switch(opcCliente){
            case 1:
                do{
                    system("cls");
                    //funcion registrar
                    //cargarArchivoCliente(ARCHI_CLIENTE);
                    muestraArchivo(ARCHI_CLIENTE);

                    fflush(stdin);
                    printf("\n Ingrese ESC para salir...");
                    opSalir=getch();
                }while(opSalir!=ESC);
                break;
            case 2:
                do{
                    system("cls");
                    int permiso=0;
                    //funcion logear
                    permiso=logearse(ARCHI_CLIENTE);
                    if(permiso==1){
                        do{
                            //mostrar opciones
                            printf("\n Entraste en el menu papa");

                            fflush(stdin);
                            printf("\n Ingrese ESC para salir...");
                            opSalir=getch();
                        }while(opSalir!=ESC);
                    }
                    fflush(stdin);
                    printf("\n Ingrese ESC para salir o ENTER para volver a intentar");
                    opSalir=getch();
                }while(opSalir!=ESC);
        }
        fflush(stdin);
        printf("\n Ingrese ESC para salir o cualquier otra tecla para volver al inicio");
        opSalir=getch();
    }while(opSalir!=ESC);
}*/


void cargarArchivoCliente(char nombreArchivo[],int dim){
    int i = 0;
    char op=0;
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"ab");
    if(archi){
        while(op!=ESC){
            system("cls");
            cliente=cargarCliente();
            i++;
            fwrite(&cliente,sizeof(stCliente),1,archi);
            printf("\n Ingrese ESC para dejar de cargar...");
            op=getch();
            fclose(archi);
            FILE* archi=fopen(nombreArchivo,"ab");
        }
        fclose(archi);
    }
}

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


