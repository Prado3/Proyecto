#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

#define ESC 27
#define DIM_CLIENTE 1000
#define ARCHI_CLIENTE "cliente.dat"

void cargarArchivoCliente(char nombreArchivo[], int dim);
void muestraArchivo(char nombreArchivo[]);
int idautoincremental();
int algo();

int main()
{
    cargarArchivoCliente(ARCHI_CLIENTE,DIM_CLIENTE);
    muestraArchivo(ARCHI_CLIENTE);


    return 0;
}

int idautoincremental (){
    stCliente cliente;
    int id=algo();
    FILE *archi = fopen(ARCHI_CLIENTE, "rb");
    if(archi){
        fseek(archi, sizeof(stCliente)*(-1),SEEK_END);
        if(fread(&cliente ,sizeof(stCliente),1,archi) > 0){
            id = cliente.id;
        }
        fclose(archi);
    }
return id+1;
}

int algo(){
    static int i = 0;
    return i;
}

void cargarArchivoCliente(char nombreArchivo[],int dim){
    int i = 0;
    char op=0;
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"ab");
    if(archi){
        while(i<dim && op!=ESC){
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
