#ifndef VACUNA_H
#define VACUNA_H
#include <QDate>
#include <string>

//Creación de una clase vacuna genérica
class vacuna
{
    int identificador;
    //En el caso de vacunas con varias dosis se considerará que el pack completo de dosis necesarias tiene el mismo identificador
    int num_dosis;
    std::string tipo;
    QDate fecha_1puesta;
    QDate fecha_2puesta;
public:
    vacuna();
};

//Se crean vacunas que sean de una sola dosis o de dos
class monodosis:public vacuna{
public:
    monodosis();
};

class multidosis:public vacuna{
public:
    multidosis();
};

#endif // VACUNA_H
