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
    double Edad;

};

class administrador:public usuarios
{
public:
    administrador();
    double Sueldo;
    QString dpto;

};

class enfermero:public usuarios
{
public:
    enfermero();
    double Sueldo;
};

class tecnico:public usuarios
{
public:
    tecnico();
    double Sueldo;
    double num_laboratorio;
};

class paciente:public usuarios
{
public:
    paciente();
    bool infectado;
    double habitacion;
};

#endif // USUARIOS_H
