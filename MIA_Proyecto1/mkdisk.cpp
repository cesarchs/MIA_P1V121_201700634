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

void mkdisk::crearFichero(mkdisk *disco)
{
    mbr prueba;
    FILE *arch;
             arch=fopen(disco->path.c_str(),"wb");
             if (arch==NULL)
        exit(1);
    //simulo un KB
    char buffer[1024];

    //si son Kb
    if (disco->unit=="k"){
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
        for(int i = 0 ; i < (disco->size*1024) ; i++)
            fwrite(&buffer,1024,1,arch);
        fclose(arch);
    }



              string fecha="11/02/2020 11:10"; //fecha quemanda con fines de ejemplo


    disco->fechacreacion=fecha;




    prueba.mbr_disk_signature=(rand() % 100);//numero random para darle etiqueta al disco
                strcpy ( prueba.mbr_fecha_creacion, fecha.c_str()); //aqui copio el string de fecha y lo vuelvo char *


    //----SI EL FIT VIENE VACIO SE ASIGNA POR DEFECTO PRIMER AJUSTE
    if(disco->ajuste.empty()==true){
        strcpy( prueba.disk_fit,"F"); //aqui convierto a char * para guardarlo en MBR
    }else{
        strcpy( prueba.disk_fit,disco->ajuste.c_str()); //aqui convierto a char * para guardarlo en MBR

    }

    printf("\nFECHA DE CREACION : %s\n" ,prueba.mbr_fecha_creacion);

    particion vacia;
    vacia.part_status='0';//status inactivo
    vacia.part_type='-';
    vacia.part_fit='-';
    vacia.part_start=-1;
    vacia.part_size=-1;
    vacia.part_name[0] = '\0';
    for(int i = 0 ; i < 4 ; i ++)
        prueba.mbr_partitions[i] = vacia;

    //AHORA AGREGO EL MBR AL DISCO
    arch = fopen(disco->path.c_str(), "rb+"); //modo de escritura mixto permite actualizar un fichero sin borrar el contenido anterior
    if(arch != NULL){
        fseek(arch,0,SEEK_SET);
        fwrite(&prueba, sizeof(mbr), 1, arch);
        fclose(arch);
        printf("DISCO CREADO CORRECTAMENTE \nSE AGREGO EL MBR DE MANERA CORRECTA\n");
    }else{
        printf("Error!\n No se puede acceder al disco, MBR no creado\n");
    }
}
