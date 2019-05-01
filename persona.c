#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../librerias/persona.h"


void alta( ePersona pers[],eSector sector[], int cantidad ,int cantidadSector){
    int i=0,legajoAux,flag,j,sectorAux,flagSector;
    char rta;
    char* mensaje="Ingrese legajo\n";

        do{
            do{
                legajoAux=getInt(mensaje);
                flag=0;
                for (j=0;j<cantidad;j++){
                    if (pers[j].legajo==legajoAux&&pers[j].isEmpty==0){

                        printf("Es un legajo existente\n");
                        flag=1;
                        break;
                    }
                }
            }while(flag==1);

            pers[i].legajo=legajoAux;

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Edad:\n");
            scanf("%d", &pers[i].edad);

            do{
                printf("sector:\n");
                scanf("%d",&sectorAux);
                flagSector=0;

                for (j=0;j<cantidadSector;j++)
                {
                    if (sectorAux==sector[j].id)
                    {
                        pers[i].sector=sector[j];
                        flagSector=1;
                        break;
                    }
                }
            }while(flagSector==0);

            pers[i].isEmpty = 0;

            i++;

            if (i<cantidad) {
                printf("Desea seguir?[S/N]");
                fflush(stdin);
                scanf("%c",&rta);
                rta=toupper(rta);
            }
        }while(rta=='S'&&i<cantidad);

}

void altaMenu( eMenu menu[], int cantidad ){
    int i;

    for (i=0;i<cantidad;i++){

            menu[i].codigo=i;

            printf("Descripcion:\n");
            fflush(stdin);
            scanf("%s", menu[i].descripcion);

            printf("Importe:\n");
            scanf("%f", &menu[i].importe);

            menu[i].isEmptyMenu=0;

    }

}

void altaSector( eSector sector[], int cantidad ){
    int i;

    for (i=0;i<cantidad;i++){

            sector[i].id=i;

            printf("Descripcion:\n");
            fflush(stdin);
            scanf("%s", sector[i].descripcion);

    }

}

void altaAlmuerzo( eAlmuerzo almuerzo[],eMenu menu[],ePersona pers[], int cantidadAlmuerzo,int cantidadMenu,int cantidadPersona ){
    int i,legajoAux,codigoAux,flagLegajo,flagCodigo,j;

    for (i=0;i<cantidadAlmuerzo;i++){

            almuerzo[i].codigo=i;
            do{
                flagLegajo=1;
                printf("Ingrese legajo:\n");
                scanf("%d",&legajoAux);
                for(j=0;j<cantidadPersona;j++){
                    if(legajoAux==pers[j].legajo){
                        almuerzo[i].persona=pers[j];
                        flagLegajo=0;
                        break;
                    }
                }

                if(flagLegajo==1){
                    printf("Error:Legajo inexistente\n");
                }
            }while(flagLegajo==1);

            do{
                flagCodigo=1;

                printf("Ingrese codigo de menu:\n");
                scanf("%d",&codigoAux);
                for(j=0;j<cantidadMenu;j++){
                    if(codigoAux==menu[j].codigo){
                        almuerzo[i].menu=menu[j];
                        flagCodigo=0;
                        break;
                    }
                }

                if(flagCodigo==1){
                    printf("Error:Codigo inexistente\n");
                }
            }while(flagCodigo==1);


            almuerzo[i].fecha=altaFecha();


    }

}

eFecha altaFecha (){
    int dia,mes, anio;
    eFecha fecha;

    printf("Ingrese dia:\n");
    scanf("%d",&dia);

    printf("Ingrese mes:\n");
    scanf("%d",&mes);

    printf("Ingrese anio:\n");
    scanf("%d",&anio);

    fecha.dia=dia;
    fecha.mes=mes;
    fecha.anio=anio;

    return fecha;
}

void mostrarTodos( ePersona pers[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        if (pers[i].isEmpty==0){
            mostrarUno(pers[i]);
        }

    }

}

void mostrarUno( ePersona per ){
        printf("%d\t%s\t%s\t%d\t%d\n",per.legajo, per.apellido, per.nombre, per.edad, per.isEmpty);
}

void baja( ePersona pers[], int cantidad){

    int legajoAux,i;

    printf("Ingrese legajo a dar de baja:\n");
    scanf("%d",&legajoAux);

    for (i=0;i<cantidad;i++){

            if (legajoAux==pers[i].legajo){

                pers[i].isEmpty=1;
                break;
            }


    }
}

void modificacion (ePersona pers[],int cantidad){

    int legajoAux,i,flag=0;

    printf("Ingrese el legajo a modificar:\n");
    scanf("%d",&legajoAux);

    for(i=0;i<cantidad;i++){

        if (legajoAux==pers[i].legajo&&pers[i].isEmpty==0){

            mostrarUno(pers[i]);

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Edad:\n");
            scanf("%d", &pers[i].edad);

            flag=1;
        }
    }
    if (flag==0){

        printf("No se encontro el legajo\n");
        system("pause");
    }
}

char getChar(char mensaje[]){

    char letra;

    printf("%s",mensaje);
    scanf("%c",&letra);

    return letra;
}

int getInt(char mensaje[]){

    int entero;

    printf("%s",mensaje);
    scanf("%d",&entero);

    return entero;
}

float getFloat(char mensaje[]){

    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}

char* getString(char mensaje[]){

    char texto[101];

    printf("%s",mensaje);
    fgets(texto,sizeof(texto)-2,stdin);

    return texto[101];
}

void bajaMenu(eMenu menu[], int cantidad){

    int codigoAux,i;

    printf("Ingrese menu a dar de baja\n");
    scanf("%d",&codigoAux);

    for (i=0;i<cantidad;i++){

        if (codigoAux==menu[i].codigo){

            menu[i].isEmptyMenu=1;
            break;

        }
    }
}

void modificacionMenu(eMenu menu[], int cantidad){

    int codigoAux,i,flag=0;

    printf("Ingrese el codigo de menu a modificar:\n");
    scanf("%d",&codigoAux);

    for(i=0;i<cantidad;i++){

        if (codigoAux==menu[i].codigo&&menu[i].isEmptyMenu==0){

            printf("%d\t%s\t%f\t%d\t\n",menu[i].codigo,menu[i].descripcion,menu[i].importe,menu[i].isEmptyMenu);

            printf("codigo:\n");
            fflush(stdin);
            scanf("%d", &menu[i].codigo);

            printf("descripcion:\n");
            fflush(stdin);
            scanf("%s", menu[i].descripcion);

            printf("importe:\n");
            scanf("%f", &menu[i].importe);

            flag=1;
        }
    }
    if (flag==0){

        printf("No se encontro el codigo de menu\n");
        system("pause");
    }
}

void listarMenu(eMenu menu[], int cantidad){
    int i;

    for(i=0;i<cantidad;i++){

        if (menu[i].isEmptyMenu==0){

            printf("%d\t%s\t%f\t%d\t\n",menu[i].codigo,menu[i].descripcion,menu[i].importe,menu[i].isEmptyMenu);
        }
    }
}

void listarSector(eSector sector[],int cantidad){

    int i;

    for(i=0;i<cantidad;i++){

        printf("%d\t%s\t\n",sector[i].id,sector[i].descripcion);
    }
}

void listarAlmuerzo(eAlmuerzo almuerzo[],int cantidad){

    int i;

    for(i=0;i<cantidad;i++){

            printf("%d\t%d/%d/%d\t%.2f\t%s\t%d\t%d\t%s\t\n",almuerzo[i].codigo,almuerzo[i].fecha.dia,almuerzo[i].fecha.mes,almuerzo[i].fecha.anio,
                   almuerzo[i].menu.importe,almuerzo[i].menu.descripcion,almuerzo[i].persona.legajo,almuerzo[i].persona.sector.id,
                   almuerzo[i].persona.sector.descripcion);
    }
}
