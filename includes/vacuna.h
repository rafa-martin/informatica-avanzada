#ifndef VACUNA_H
#define VACUNA_H
#include <QDate>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;


//Creación de una clase vacuna genérica
class vacuna
{
protected:
    int identificador;
    //En el caso de vacunas con varias dosis se considerará que el pack completo de dosis necesarias tiene el mismo identificador
    std::string tipo;
    string dni_persona;
    QDate fecha_1puesta;
public:
    vacuna(int id);
    void set_1puesta(int d,int m, int y);
    void set_tipo(int num);
    void set_id(int id);
    void set_dni(string dni_per);
    virtual std::vector<QDate> Get_fechas() =0;
    std::string Get_datos();
};

//Se crean vacunas que sean de una sola dosis o de dos
class monodosis:public vacuna{
public:
    monodosis(int id);
    std::vector<QDate> Get_fechas();
};

class multidosis:public vacuna{
public:
    multidosis(int id);
    std::vector<QDate> Get_fechas();
};

vacuna* new_vacuna(int id);

#endif // VACUNA_H
