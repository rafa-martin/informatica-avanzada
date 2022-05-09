#ifndef BUSCARCREARUSUARIO_H
#define BUSCARCREARUSUARIO_H

#include <QDialog>
#include <usuarios/usuarios.h>
#include <database/database.hpp>

namespace Ui {
class BuscarCrearUsuario;
}
/**
 * @brief Esta clase permite crear la ventana de busqueda o creación del usuario introduciendo su DNI
 */
class BuscarCrearUsuario : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase
     * @param db:base de datos donde estan almacenados los usuarios y el resto de sus datos
     * @param parent: puntero de la ventana que abre la nueva ventana.
     */
    explicit BuscarCrearUsuario(IA_Clinic::Database &db,QWidget *parent = nullptr);
    ~BuscarCrearUsuario();
    /**
     * @brief buscar_usuario
     * @param DNI: dni introducido por pantalla
     * @return Devuelve la direccion de memoria del usuario buscado en el vector (en caso de no encontrar el usuario devuelve un puntero nulo)
     */
    usuarios* buscar_usuario(QString DNI);

private slots:
    /**
     * @brief on_pushButton_clicked: permite acceder a la ventana de datos del usuario, con la modificación de cada uno de los campos que sea
     * necesario (dependiendo del tipo de usuario). Una vez cerrada dicha ventana, guarda los valores en el vector si se ha pulsado el boton `guardar`,
     * y crea un nuevo elemento en el vector de usuarios en caso de que sea un nuevo usuario (puntero usuario recibido es nulo).
     */
    void on_pushButton_clicked();
    /**
     * @brief on_lineEdit_textEdited: indica cada vez que se escribe una letra si el dni escrito coincide con alguno del vector de usuarios
     * @param arg1: valor escrito por pantalla
     */
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::BuscarCrearUsuario *ui;
    IA_Clinic::Database &db;
};

#endif // BUSCARCREARUSUARIO_H
