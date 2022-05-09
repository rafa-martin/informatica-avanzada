#ifndef USUARIOS_H
#define USUARIOS_H
#include <QString>
#include <iostream>


class usuarios
{
public:
    usuarios();
    QString Nombre;
    QString Apellidos;
    QString DNI;
    double Edad=0;
    /*Al poner igual a 0, obligamos a las funciones hijo a que se implemente esta función*/
    virtual QString obtener_tipo()=0;

};

class administrador:public usuarios
{
public:
    administrador();
    double Sueldo=0;
    QString dpto;
    virtual QString obtener_tipo();
};

class enfermero:public usuarios
{
public:
    enfermero();
    double Sueldo=0;
    virtual QString obtener_tipo();
};

class tecnico:public usuarios
{
public:
    tecnico();
    double Sueldo=0;
    double num_laboratorio=0;
    virtual QString obtener_tipo();
};

class paciente:public usuarios
{
public:
    paciente();
    bool infectado=false;
    double habitacion=0;
    virtual QString obtener_tipo();
};

#endif // USUARIOS_H
