#pragma once

#include <QDialog>
#include <database/database.hpp>
#include <vacunas/vacuna.h>

namespace Ui {
class RegVacunas;
}

class RegVacunas : public QDialog
{
    Q_OBJECT

public:
    explicit RegVacunas(IA_Clinic::Database& db,QWidget *parent = nullptr);
    ~RegVacunas();

private slots:
    /**
     * @brief Botón que cierra la ventana
     */
    void on_commandLinkButton_clicked();
    /**
     * @brief Botón que abre el cuadro de diálogo para obtener la información de una vacuna si hay un identificador válido escrito en el menú
     */
    void on_obtener_clicked();
    /**
     * @brief Botón que abre el cuadro de diálogo para agregar una nueva vacuna si hay un identificador válido escrito en el menú
     */
    void on_insertar_clicked();
    /**
     * @brief Botón que muestra un registro de datos de las vacunas existentes
     */
    void on_registro_clicked();
    /**
     * @brief Función que busca en el registro la vacuna con el identificador aportado
     * @param id es el identificador de la vacuna a buscar
     * @return Puntero a la vacuna encontrada o nullptr si no se encuentra
     */
    vacuna* get_vacuna(int id);

private:
    Ui::RegVacunas *ui;
    IA_Clinic::Database &db;
};
