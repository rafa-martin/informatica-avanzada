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
    void set_usuario(usuarios*);
    /*Esta función devuelve un puntero de usuario*/
    usuarios* get_usuario();
    bool guardar();
private slots:
    void on_Guardar_bton_clicked();

    void on_Cancelar_bton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::VentanaDatosUsuario *ui;
    usuarios* us=nullptr;
    bool guardado=false;
};

#endif // VENTANADATOSUSUARIO_H
