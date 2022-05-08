#include <usuarios/ventanadatosusuario.h>
#include "ui_ventanadatosusuario.h"

VentanaDatosUsuario::VentanaDatosUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaDatosUsuario)
{
    ui->setupUi(this);
}

VentanaDatosUsuario::~VentanaDatosUsuario()
{
    delete ui;
}
