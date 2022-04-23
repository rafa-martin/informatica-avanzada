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
    QDate fecha_1puesta;
public:
    vacuna();
    void set_1puesta(int d,int m, int y);
    void set_tipo(int num);
    void set_id(int id);
    virtual std::vector<QDate> Get_fechas();
    std::string Get_datos();
};

//Se crean vacunas que sean de una sola dosis o de dos
class monodosis:public vacuna{
public:
    monodosis();
    std::vector<QDate> Get_fechas(){
        std::vector<QDate> fecha;
        fecha.push_back(fecha_1puesta);
        return fecha;
    }
};

class multidosis:public vacuna{
public:
    multidosis();
    std::vector<QDate> Get_fechas(){
        std::vector<QDate> fecha;
        fecha.push_back(fecha_1puesta);
        fecha.push_back(fecha_1puesta.addDays(21));
        return fecha;
    }
};

void vacuna::set_tipo(int num){
    if (num==0){
        tipo="Johnson";
    }
    else if(num==1){
        tipo="Pfizer";
    }
    else{
        tipo="Moderna";
    }

}

void vacuna::set_1puesta(int d,int m, int y){
    fecha_1puesta=QDate(y,m,d);
}

void vacuna::set_id(int id){
    identificador=id;
}

std::string vacuna::Get_datos(){
    string data= "Vacuna ";
    data.append(to_string(identificador));
    data.append(" de tipo");
    data.append(tipo);
    return data;
}

//La asignación de cada tipo de vacuna es aleatoria
vacuna* new_vacuna(){
    srand(time(NULL));
    int num=0+rand()%3;
    if (num==0){
        vacuna * vac=new monodosis();
        vac->set_tipo(num);
        return vac;
    }
    else{
        vacuna * vac=new multidosis();
        vac->set_tipo(num);
        return vac;
    }
}
#endif // VACUNA_H
