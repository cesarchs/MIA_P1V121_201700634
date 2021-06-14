#include "mkdisk.h"
//#include "estructuras.h"
#include <stdio.h>
#include <string.h>
#include "estructuras.h"
using namespace std;

mkdisk::mkdisk()
{
//implementaciones

}
void mkdisk::mostrardatos(mkdisk *disco){
    printf("\n\n-------------DATOS-------------\n\n");

    printf("EL tamanio es %d \n",disco->size);

}

void mkdisk::crearFichero(mkdisk *disco){
    mbr prueba;
    FILE *arch;
    arch=fopen(disco->path.c_str(),"wb");
    if (arch==NULL)
        exit(1);
    //simulo un KB
    char buffer[1024];

    //si son Kb
    if (disco->unit=="k"){
        //-------ASIGNO TAMAÑO A MBR, RECORDAR QUE ESTE LO PIDE EN BYTES POR LO que multiplico el size por 1024
        prueba.mbr_tamano=disco->size*1024;

        for(int i = 0 ; i < 1024 ; i++)
            buffer[i]='\0';

        for(int i = 0 ; i < (disco->size) ; i++)
            fwrite(&buffer,1024,1,arch);


        fclose(arch);
    }

    //Si son megas
    else if(disco->unit=="m" || disco->unit.empty()==1){
        prueba.mbr_tamano=disco->size*1024*1024;//LO DOY EN BYTES
        for(int i = 0 ; i < 1024 ; i++)
            buffer[i]='\0';
        for(int i = 0 ; i < (disco->size*1024) ; i++)//para mb multiplicar por 1024
            fwrite(&buffer,1024,1,arch);
        fclose(arch);
    }



}
