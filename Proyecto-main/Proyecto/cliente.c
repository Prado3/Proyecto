#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

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
