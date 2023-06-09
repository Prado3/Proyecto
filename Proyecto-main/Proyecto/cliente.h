#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char contrasena[30];
    char domicilio[45];
    char telefono[12];
    int eliminado;
} stCliente;

stCliente cargarCliente();
void mostrarCliente(stCliente cliente);
int logearse(char nombreArchivo[]);

#endif // CLIENTE_H_INCLUDED
