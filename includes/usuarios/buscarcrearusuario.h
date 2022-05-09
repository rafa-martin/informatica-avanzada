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
    /**
     * @brief Constructor de la clase
     * @param db:base de datos donde estan almacenados los usuarios y el resto de sus datos
     * @param parent: puntero de la ventana que abre la nueva ventana.
     */
    explicit BuscarCrearUsuario(IA_Clinic::Database &db,QWidget *parent = nullptr);
    ~BuscarCrearUsuario();
    usuarios* buscar_usuario(QString DNI);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::BuscarCrearUsuario *ui;
    IA_Clinic::Database &db;
};

#endif // BUSCARCREARUSUARIO_H
