#include "pruebadiagnostica.h"

PruebaDiagnostica::PruebaDiagnostica()
{

}

PCR::PCR()
{

}

Antigenos::Antigenos()
{

}

string PruebaDiagnostica::getdni()
{
    return dni;
}

QDate PruebaDiagnostica::getFecha()
{
    return fechaMuestra;
}

void PruebaDiagnostica::setdni(string dni_in)
{
    dni=dni_in;
}

void PruebaDiagnostica::setFecha(int dia, int mes, int anyo)
{
    fechaMuestra=QDate(anyo,mes,dia);
}

string Antigenos::getnombre()
{
    return "Antigenos";
}

string PCR::getnombre()
{
    return "PCR";
}
