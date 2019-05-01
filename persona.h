typedef struct{
    int id;
    char descripcion[51];
}eSector;

typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
    int legajo;
    eSector sector;
}ePersona;

typedef struct{
    int codigo;
    float importe;
    char descripcion[51];
    int isEmptyMenu;
}eMenu;

typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct {
    ePersona persona;
    eMenu menu;
    int codigo;
    eFecha fecha;
}eAlmuerzo;


void alta( ePersona pers[],eSector sector[], int cantidad ,int cantidadSector);

void mostrarUno( ePersona per );

void mostrarTodos( ePersona pers[], int cantidad );

void baja(ePersona pers[], int cantidad);

void modificacion (ePersona pers[], int cantidad);

char getChar(char mensaje[]);

int getInt(char mensaje[]);

float getFloat(char mensaje[]);

char* getString(char mensaje[]);

void altaMenu(eMenu menu[], int cantidad);

void bajaMenu(eMenu menu[],int cantidad);

void modificacionMenu(eMenu menu[], int cantidad);

void listarMenu(eMenu menu[], int cantidad);

void listarSector(eSector sector[],int cantidad);

void listarAlmuerzo(eAlmuerzo almuerzo[],int cantidad);


void altaSector(eSector sector[], int cantidad);

eFecha altaFecha();

void altaAlmuerzo(eAlmuerzo almuerzo[],eMenu menu[],ePersona pers[], int cantidadAlmuerzo, int cantidadMenu,int cantidadPersona);
