#ifndef BUSCARCREARUSUARIO_H
#define BUSCARCREARUSUARIO_H

#include <QDialog>
#include <usuarios/usuarios.h>
#include <database/database.hpp>

namespace Ui {
class BuscarCrearUsuario;
}

class BuscarCrearUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit BuscarCrearUsuario(IA_Clinic::Database &db,QWidget *parent = nullptr);
    ~BuscarCrearUsuario();
    usuarios* buscar_usuario(QString DNI);

private slots:
    void on_pushButton_clicked();

private:
    Ui::BuscarCrearUsuario *ui;
    IA_Clinic::Database &db;
};

#endif // BUSCARCREARUSUARIO_H
