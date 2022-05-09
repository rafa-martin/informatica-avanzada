#include <usuarios/buscarcrearusuario.h>
#include "ui_buscarcrearusuario.h"
#include <usuarios/ventanadatosusuario.h>
#include <database/database.hpp>

BuscarCrearUsuario::BuscarCrearUsuario(IA_Clinic::Database &db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuscarCrearUsuario),
    db(db)
{
    ui->setupUi(this);
}

BuscarCrearUsuario::~BuscarCrearUsuario()
{
    delete ui;
}

void BuscarCrearUsuario::on_pushButton_clicked()
{
    usuarios* us_dni= buscar_usuario(ui->lineEdit->text());
    VentanaDatosUsuario mi_ventana;
    mi_ventana.set_dni(ui->lineEdit->text());
    if(us_dni!=nullptr){
        mi_ventana.set_usuario(us_dni);
    }
    mi_ventana.exec();
    if(mi_ventana.guardar()&&us_dni==nullptr){
        usuarios* n_usuario=mi_ventana.get_usuario();
        std::vector<usuarios*> &db_usuarios=db.getDataVector<usuarios*>();
        db_usuarios.push_back(n_usuario);
    }
}
usuarios* BuscarCrearUsuario::buscar_usuario(QString DNI)
{
    std::vector<usuarios*> &db_usuarios=db.getDataVector<usuarios*>();
    for(auto it : db_usuarios){
        if(it->DNI==DNI){
            return it;
        }
    }
    return nullptr;
}


void BuscarCrearUsuario::on_lineEdit_textEdited(const QString &arg1)
{
    usuarios* us_dni= buscar_usuario(arg1);
    std::cout << arg1.toStdString() << std::endl;
    if(us_dni==nullptr){
        ui->textEdit->clear();
        ui->pushButton->setText("Crear usuario");
        ui->textEdit->append("No se ha encontrado el usuario a buscar\n");
    }else {
        ui->textEdit->clear();
        ui->pushButton->setText("Actualizar usuario");
        ui->textEdit->append("Se ha encontrado el usuario a buscar\n");
    }
}

