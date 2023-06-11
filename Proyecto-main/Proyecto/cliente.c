#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

#define ESC 27

stCliente cargarCliente(){
    stCliente cliente;

    cliente.id=idautoincremental();

    printf("\n Ingrese su nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    printf("\n Ingrese su apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

    printf("\n Ingrese su dni: ");
    fflush(stdin);
    gets(cliente.dni);

    printf("\n Ingrese su email: ");
    fflush(stdin);
    gets(cliente.email);

    printf("\n Ingrese su contrasena: ");
    fflush(stdin);
    gets(cliente.contrasena);

    printf("\n Ingrese su domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

    printf("\n Ingrese su telefono: ");
    fflush(stdin);
    gets(cliente.telefono);

    return cliente;
}

void mostrarCliente(stCliente cliente){
    printf("\n Nombre y Apellido:..: %s %s", cliente.nombre,cliente.apellido);
    printf("\n Dni:................: %s", cliente.dni);
    printf("\n Email:..............: %s", cliente.email);
    printf("\n Domicilio:..........: %s", cliente.domicilio);
    printf("\n Telecono:...........: %s", cliente.telefono);
    printf("\n ID:.................: %d", cliente.id);
    printf("\n==================================");
}

int logearse(char nombreArchivo[]){
    char opSalir;
    char usuario[30];
    char contrasena[30];
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"rb");
    int flag=0;

    do{
        system("cls");
        printf("\n Usuario: ");
        fflush(stdin);
        gets(usuario);
        printf("\n Contrasena: ");
        fflush(stdin);
        gets(contrasena);

        if(archi){
            while(fread(&cliente,sizeof(stCliente),1,archi)>0){
                if(usuario==cliente.email && contrasena==cliente.contrasena){
                    flag=1;
                }
            }
            if(flag==0){
                printf("\n Ingrese un usuario valido...");
            }
        }
        printf("\n O ingrese ESC para registrarse.");
        opSalir=getch();
    }while(flag!=1 || opSalir!=ESC);
    fclose(archi);
    return flag;
}

