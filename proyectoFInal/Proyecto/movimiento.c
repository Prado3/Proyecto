#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include <time.h>
#define ESC 27

// ACA SE ENCUENTRAN LAS FUNCIONES DEL ARCHIVO MOVIMIENTO
stMovimiento cargarUnMovimiento(int id, int idCuenta, char detalle[100],float importe){
    stMovimiento movimiento;
    time_t t;
    time(&t);
    struct tm *fecha=localtime(&t);


    movimiento.id=id;

    movimiento.idCuenta=idCuenta;

    movimiento.anio=fecha->tm_year+1900;

    movimiento.mes=fecha->tm_mon+1;

    movimiento.dia=fecha->tm_mday;

    strcpy(movimiento.detalle,detalle);

    movimiento.importe=importe;

    movimiento.eliminado=0;

    return movimiento;
}


void mostrarMovimiento(stMovimiento movimiento){
    printf("\n ==============================");
    printf("\n id:...................%d",movimiento.id);
    printf("\n idCuenta:.............%d",movimiento.idCuenta);
    printf("\n Anio:.................%d",movimiento.anio);
    printf("\n Mes:..................%d",movimiento.mes);
    printf("\n Dia:..................%d",movimiento.dia);
    printf("\n Detalle:..............%s",movimiento.detalle);
    printf("\n Importe:..............%.2f",movimiento.importe);
    printf("\n Eliminado:............%d",movimiento.eliminado);
    printf("\n ==============================");
}

