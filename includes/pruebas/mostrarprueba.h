#pragma once
#include <database/database.hpp>
#include <QDialog>

namespace Ui {
class MostrarPrueba;
}

/**
 * @brief Clase que representa la ventana de MostrarPrueba
 */
class MostrarPrueba : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase MostrarPrueba
     * @param db referencia a la base de datos compartida
     * @param parent puntero a la ventana que crea esta clase
     */
    explicit MostrarPrueba(IA_Clinic::Database &db,QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase MostrarPrueba
     */
    ~MostrarPrueba();

    /**
     * @brief Método que actualiza la tabla de las pruebas registradas en la db
     */
    void actualizar();

private slots:
    /**
     * @brief abre la ventana para editar una prueba
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief puntero que almacena los elementos de la ventana
     */
    Ui::MostrarPrueba *ui;
    /**
     * @brief referencia a la base de datos compartida db
     */
    IA_Clinic::Database &db;
};
