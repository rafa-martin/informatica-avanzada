#pragma once
#include <string>
#include <QDate>

/**
 * @brief Clase que representa una prueba diagnóstica genérica
 */
class PruebaDiagnostica
{
    /**
     * @brief variable que almacena el dni de la persona a la que se le toma la prueba
     */
    std::string dni;
    /**
     * @brief variable que almacena la fecha en la que se toma la prueba
     */
    QDate fechaMuestra;
public:
    /**
     * @brief Constructor de la prueba diagnóstica
     */
    PruebaDiagnostica() = default;
    /**
     * @brief devuelve el dni de la persona a la que se le toma la prueba
     * @return
     */
    std::string getdni();
    /**
     * @brief establece el dni de la persona a la que se le toma la prueba
     */
    void setdni(std::string);
    /**
     * @brief establce la fecha en la que se toma la prueba
     * @param dia dia de la fecha en la que se toma la prueba
     * @param mes mes de la fecha en la que se toma la prueba
     * @param anyo año de la fecha en la que se toma la prueba
     */
    void setFecha(int dia,int mes, int anyo);
    /**
     * @brief devuelve el nombre de la prueba diagnóstica. Deben reimplementar este método
     * las clases que hereden.
     * @return el nombre de la prueba diagnóstica
     */
    virtual std::string getnombre()=0;
    /**
     * @brief devuelve la fecha en la que se toma la prueba
     * @return la fecha
     */
    QDate getFecha();
};

/**
 * @brief Clase que representa una prueba de antígenos
 */
class Antigenos:public PruebaDiagnostica
{
public:
    /**
     * @brief Constructor de antígenos
     */
    Antigenos() = default;
    /**
     * @brief implementación del método abstracto
     * @return devuelve el tipo de la prueba
     */
    virtual std::string getnombre();
};

/**
 * @brief Clase que representa una prueba PCR
 */
class PCR:public PruebaDiagnostica
{
public:
    /**
     * @brief Constructor de PCR
     */
    PCR() = default;
    /**
     * @brief implementación del método abstracto
     * @return devuelve el tipo de la prueba
     */
    std::string getnombre();
};
