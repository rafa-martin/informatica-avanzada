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

class administrador:usuarios
{
public:
    administrador();
    double Sueldo;
    QString dpto;

};

class enfermero:usuarios
{
public:
    enfermero();
    double Sueldo;
};

class tecnico:usuarios
{
public:
    tecnico();
    double Sueldo;
    double num_laboratorio;
};

class paciente:usuarios
{
public:
    paciente();
    bool infectado;
    double habitacion;
};

#endif // USUARIOS_H
