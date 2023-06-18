#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define ARCHI_CLIENTE "cliente.dat"
#define ARCHI_CUENTA "cuenta.dat"

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

typedef struct{
    int id;
    int idCliente;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual;
    int eliminado;
}stCuenta;

//MENU GENERAL
int mostrarOpciones();
void darAltaCliente(char nombreArchivo[],char nombreCuentaArchi[]);
int buscarDni(char nombreArchivo[], char dni[10]);

//CLIENTE.C
int nroClienteB();
int nroClienteA();
stCliente cargarCliente();
void mostrarCliente(stCliente cliente);
int logearse(char nombreArchivo[]);
int idautoincremental ();
int idAuto();

//CUENTA.C
int mostrarOpcionDeCuenta();
int nroCuentaA();
int nroCuentaB();
stCuenta cargarCuenta(int id, int nroCcliente, int opcion);
void mostrarCuenta();
#endif // CLIENTE_H_INCLUDED
