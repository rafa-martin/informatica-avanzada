#include <pruebas/pruebadiagnostica.h>

std::string PruebaDiagnostica::getdni()
{
    return dni;
}

QDate PruebaDiagnostica::getFecha()
{
    return fechaMuestra;
}

void PruebaDiagnostica::setdni(std::string dni_in)
{
    dni=dni_in;
}

void PruebaDiagnostica::setFecha(int dia, int mes, int anyo)
{
    fechaMuestra=QDate(anyo,mes,dia);
}

std::string Antigenos::getnombre()
{
    return "Antigenos";
}

std::string PCR::getnombre()
{
    return "PCR";
}
