#include <usuarios/buscarcrearusuario.h>
#include "ui_buscarcrearusuario.h"

BuscarCrearUsuario::BuscarCrearUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuscarCrearUsuario)
{
    ui->setupUi(this);
}

BuscarCrearUsuario::~BuscarCrearUsuario()
{
    delete ui;
}
