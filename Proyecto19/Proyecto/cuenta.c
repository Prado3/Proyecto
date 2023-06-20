#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

#define ESC 27

int mostrarOpcionDeCuenta(){
    int i=0;
    printf("\n ================================================");
    printf("\n 1 = Caja de ahorro en Pesos - Costo: $1000/mes");
    printf("\n 2 = Caja de ahorro en Dolares - Costo: $1000/mes");
    printf("\n 3 = Cuenta Corriente en Pesos - Costo: $1000/mes");
    printf("\n =================================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

stCuenta cargarCuenta(int id, int nroCliente, int opcion){
    stCuenta cuenta;

    cuenta.id=id;

    cuenta.idCliente=nroCliente;

    cuenta.nroCuenta=nroCuentaA();

    cuenta.tipoDeCuenta=opcion;

    cuenta.costoMensual=1000;

    cuenta.eliminado=0;

    return cuenta;
}

void mostrarCuenta(stCuenta cuenta){
    printf("\n ====================");
    printf("\n id:............ %d",cuenta.id);
    printf("\n idCuenta:...... %d",cuenta.idCliente);
    printf("\n NroCuenta:..... %d",cuenta.nroCuenta);
    printf("\n Tipo de Cuenta: %d",cuenta.tipoDeCuenta);
    printf("\n Costo mensual:. %.2f",cuenta.costoMensual);
    printf("\n Eliminado:..... %d",cuenta.eliminado);
    printf("\n ====================");
}

int nroCuentaA(){
    stCuenta cuenta;
    int id=nroCuentaB();
    FILE *archi = fopen(ARCHI_CUENTA, "rb");
    if(archi){
        fseek(archi, sizeof(stCuenta)*(-1),SEEK_END);
        if(fread(&cuenta ,sizeof(stCuenta),1,archi) > 0){
            id = cuenta.nroCuenta;
        }
        fclose(archi);
    }
return id+2;
}

int nroCuentaB(){
    static int i = 100000;
    return i;
}



