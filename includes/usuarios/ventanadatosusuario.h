#ifndef VENTANADATOSUSUARIO_H
#define VENTANADATOSUSUARIO_H

#include <QDialog>

namespace Ui {
class VentanaDatosUsuario;
}

class VentanaDatosUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaDatosUsuario(QWidget *parent = nullptr);
    ~VentanaDatosUsuario();

private:
    Ui::VentanaDatosUsuario *ui;
};

#endif // VENTANADATOSUSUARIO_H
