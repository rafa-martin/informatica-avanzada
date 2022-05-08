#include "mostrarprueba.h"
#include "ui_mostrarprueba.h"

MostrarPrueba::MostrarPrueba(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MostrarPrueba)
{
    ui->setupUi(this);
}

MostrarPrueba::~MostrarPrueba()
{
    delete ui;
}
