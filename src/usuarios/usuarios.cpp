#include <usuarios/usuarios.h>


usuarios::usuarios()
{

}

administrador::administrador()
{

}

enfermero::enfermero()
{

}

tecnico::tecnico()
{

}

paciente::paciente()
{

}

QString administrador::obtener_tipo()
{
    return "administrador";
}

QString enfermero::obtener_tipo()
{
    return "enfermero";
}

QString tecnico::obtener_tipo()
{
    return "tecnico";
}

QString paciente::obtener_tipo()
{
    return "paciente";
}
