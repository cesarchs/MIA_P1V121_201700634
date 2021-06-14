#ifndef MKDISK_H
#define MKDISK_H
#include <QString>
#include "string"
using namespace std;


class mkdisk
{
public:
    mkdisk();
    //ACA VAN LAS DEFINICIONES ATRIBUTOS Y METODOS

    int size;
    string unit;
    string path;
    string ajuste;


    void mostrardatos (mkdisk *disco);// se le pasa un puntero, se trabaja por referencia, es decir la direccion del objeto
    void ejecutar (mkdisk *disco);// este para que aca haga todos los procesos de creacion de lo que pidan para este metodo
    void crearFichero(mkdisk * disco);//declaramos el metodo para crear ficheros

};

#endif // MKDISK_H
