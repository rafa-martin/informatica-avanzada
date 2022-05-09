#pragma once

#include <QDialog>
#include <pruebas/pruebadiagnostica.h>

namespace Ui {
class CrearPrueba;
}
/**
 * @brief Clase que representa la ventana de creación de pruebas diagnósticas
 */
class CrearPrueba : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase CrearPrueba
     * @param parent puntero a la clase que abre esta ventana
     */
    explicit CrearPrueba(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase CrearPrueba
     */
    ~CrearPrueba();

    /**
     * @brief devuelve si el usuario quiere guardar
     * @return true, si el usuario quiere guardar. false, si no
     */
    bool getguardar();

    /**
     * @brief devuelve un puntero a la prueba que ha creado el usuario
     * @return puntero a una prueba diagnóstica
     */
    PruebaDiagnostica* getprueba();

private slots:
    /**
     * @brief método al que se llama cuando pulsa guardar
     */
    void on_guardar_clicked();

    /**
     * @brief método al que se llama cuando se pulsa cancelar
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief variable que almacena si se ha pulsado guardar o no
     */
    bool guardar=false;

    /**
     * @brief puntero que almacena los elementos de la ventana
     */
    Ui::CrearPrueba *ui;
};
