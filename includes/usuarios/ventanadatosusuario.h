#ifndef VENTANADATOSUSUARIO_H
#define VENTANADATOSUSUARIO_H

#include <QDialog>
#include <usuarios/usuarios.h>

namespace Ui {
class VentanaDatosUsuario;
}

class VentanaDatosUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaDatosUsuario(QWidget *parent = nullptr);
    ~VentanaDatosUsuario();
    /*recibe el puntero de get usuario (si existe el usuario) y deshabilita el como box y los line edit pertinentes*/
    /**
     * @brief set_usuario: recibe el tipo de usuario que se va a actualizar para bloquear los campos necesarios y escribir en los restantes los
     * datos encontrados en el vector que guarda todos los campos del usuario
     */
    void set_usuario(usuarios*);
    /*Esta función devuelve un puntero de usuario*/
    /**
     * @brief get_usuario: se encarga de guardar los datos introducidos en la ventana de datos de usuario.Si el puntero a usuario es nulo, permite
     * crear uno nuevo y elegir el tipo de usuario que es, si no, bloquea los campos necesarios y permite actualizar los disponibles.
     * @return devuelve el puntero al usuario (previamente creado o no)
     */
    usuarios* get_usuario();
    /**
     * @brief guardar: funcion que se encarga de devolver un valor booleano true en caso de que se haya pulsado el boton 'guardar'
     * @return
     */
    bool guardar();
    /**
     * @brief set_dni: guarda el valor de dni escrito en la ventana BuscarCrearUsuario para su creación/actualización y lo muestra en la ventana de datos
     * solo como lectura.
     * @param DNI
     */
    void set_dni(QString DNI);
private slots:
    /**
     * @brief on_Guardar_bton_clicked: actualiza el valor booleano en caso de que se pulse el botón 'guardar'
     */
    void on_Guardar_bton_clicked();
    /**
     * @brief on_Cancelar_bton_clicked:cierra la ventana
     */
    void on_Cancelar_bton_clicked();
    /**
     * @brief on_comboBox_currentIndexChanged: permite bloquear y desbloquear los campos que pertenecen a cada usuario en funcion de la pestaña
     * puesta en la comboBox (este caso solo ocurre cuando se crea un usuario)
     * @param index
     */
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::VentanaDatosUsuario *ui;
    usuarios* us=nullptr;
    bool guardado=false;
};

#endif // VENTANADATOSUSUARIO_H
