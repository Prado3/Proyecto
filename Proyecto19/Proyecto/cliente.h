#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define ARCHI_CLIENTE "cliente.dat"
#define ARCHI_CUENTA "cuenta.dat"
#define ARCHI_MOVIMIENTOS "movimientos.dat"

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

typedef struct{
    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
}stMovimiento;

typedef struct{
    int dia;
    int mes;
    int anio;
}stTiempo;



//MENU GENERAL
int mostrarOpciones();
void darAltaCliente(char nombreArchivo[],char nombreCuentaArchi[]);
int buscarDni(char nombreArchivo[], char dni[10]);
void hacerMovMenu();
void bajaCliente();
void buscarCliente();
void movimientoPorFecha();

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

//MOVIMIENTO.C
stMovimiento cargarUnMovimiento(int id, int idCuenta, char detalle[100],float importe);
void mostrarMovimiento(stMovimiento movimiento);
stTiempo tiempo();
#endif // CLIENTE_H_INCLUDED
