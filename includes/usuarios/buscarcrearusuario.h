#ifndef BUSCARCREARUSUARIO_H
#define BUSCARCREARUSUARIO_H

#include <QDialog>

namespace Ui {
class BuscarCrearUsuario;
}

class BuscarCrearUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit BuscarCrearUsuario(QWidget *parent = nullptr);
    ~BuscarCrearUsuario();

private:
    Ui::BuscarCrearUsuario *ui;
};

#endif // BUSCARCREARUSUARIO_H
