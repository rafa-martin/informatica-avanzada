#ifndef PRUEBADIAGNOSTICA_H
#define PRUEBADIAGNOSTICA_H
#include <string>
#include <QDate>

using namespace std;


class PruebaDiagnostica
{
    string dni;
    QDate fechaMuestra;
public:
    PruebaDiagnostica();
    string getdni();
    void setdni(string);
    void setFecha(int dia,int mes, int anyo);
    virtual string getnombre()=0;

};


class Antigenos:public PruebaDiagnostica
{

public:
    Antigenos();
    virtual string getnombre();
};

class PCR:public PruebaDiagnostica
{
public:
    PCR();
    string getnombre();
};


#endif // PRUEBADIAGNOSTICA_H

