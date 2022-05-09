#pragma once
#include <QDate>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

/**
 * @brief Creación de una clase vacuna genérica
 */
class vacuna
{
public:
    /**
     * @brief Identificador numérico asociado a cada vacuna
     */
    int identificador;
protected:
    /**
     * @brief En el caso de vacunas con varias dosis se considerará que el pack completo de dosis necesarias tiene el mismo identificador
     */
    std::string tipo;
    /**
     * @brief String asociado al DNI de la persona a la que se le asigna la vacuna
     */
    std::string dni_persona;
    /**
     * @brief Fecha de la primera puesta de la vacuna
     */
    QDate fecha_1puesta;
public:
    /**
     * @brief Constructor de la clase vacuna
     * @param id contiene el parámetro identificador
     */
    vacuna(int id);
    /**
     * @brief Función que define la primera puesta de la vacuna en caso de tener 3 enteros
     * @param d corresponde al día
     * @param m corresponde al mes
     * @param y corresponde al año
     */
    void set_1puesta(int d,int m, int y);
    /**
     * @brief Función que define la primera puesta de la vacuna en caso de tener un QDate
     * @param fecha en formato QDate
     */
    void set_1puesta(QDate fecha);
    /**
     * @brief Función que define el tipo a través de un número aleatorio generado
     * @param num corresponde al número aleatorio
     */
    void set_tipo(int num);
    /**
     * @brief Función que agrega el identificador a la vacuna
     * @param id es el identificador numérico
     */
    void set_id(int id);
    /**
     * @brief Función que asocia la vacuna a una persona por su DNI
     * @param dni_per corresponde al DNI de la persona
     */
    void set_dni(std::string dni_per);
    /**
     * @brief Función que devuelve el DNI de la persona a la que está asociada la vacuna
     * @return DNI en formato string
     */
    std::string Get_DNI();
    /**
     * @brief Función que devuelve la fecha o fechas de vacunación
     * @return Vector de fechas de vacunación
     */
    virtual std::vector<QDate> Get_fechas() =0;
    /**
     * @brief Función que devuelve el tipo de la vacuna
     * @return String con el tipo de vacuna
     */
    std::string Get_tipo();
    /**
     * @brief Función que devuelve una serie de datos de la vacuna en formato string
     * @return String con el identificador, el tipo de vacuna y el DNI de la persona asociada a la vacuna
     */
    std::string Get_datos();
};

/**
 * @brief Clase de vacunas que solo contienen una dosis
 */
class monodosis:public vacuna{
public:
    monodosis(int id);
    std::vector<QDate> Get_fechas();
};
/**
 * @brief Clase de vacunas que tienen varias dosis
 */
class multidosis:public vacuna{
public:
    multidosis(int id);
    std::vector<QDate> Get_fechas();
};

vacuna* new_vacuna(int id);
