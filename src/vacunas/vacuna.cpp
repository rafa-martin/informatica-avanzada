#include "vacunas/vacuna.h"

vacuna::vacuna(int id)
{
    set_id(id);
}

monodosis::monodosis(int id):vacuna(id){}

multidosis::multidosis(int id):vacuna(id){}

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

void vacuna::set_1puesta(QDate fecha){
    fecha_1puesta=fecha;
}

void vacuna::set_id(int id){
    identificador=id;
}

std::string vacuna::Get_datos(){
    std::string data= "Vacuna con identificador ";
    data.append(std::to_string(identificador));
    data.append(" de tipo ");
    data.append(tipo);
    data.append(" asignada al DNI ");
    data.append(dni_persona);
    return data;
}

void vacuna::set_dni(std::string dni_per){
    dni_persona=dni_per;
}

//La asignación de cada tipo de vacuna es aleatoria
vacuna* new_vacuna(int id){
    srand(time(NULL));
    int num=0+rand()%3;
    if (num==0){
        vacuna * vac= new monodosis(id);
        vac->set_tipo(num);
        return vac;
    }
    else{
        vacuna * vac= new multidosis(id);
        vac->set_tipo(num);
        return vac;
    }
}

std::vector<QDate> monodosis::Get_fechas(){
    std::vector<QDate> fecha;
    fecha.push_back(fecha_1puesta);
    return fecha;
}

std::string vacuna::Get_DNI(){
    return dni_persona;
};

std::string vacuna::Get_tipo(){
    return tipo;
}

std::vector<QDate> multidosis::Get_fechas(){
    std::vector<QDate> fecha;
    fecha.push_back(fecha_1puesta);
    fecha.push_back(fecha_1puesta.addDays(21));
    return fecha;
}
