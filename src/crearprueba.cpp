#include "crearprueba.h"
#include "ui_crearprueba.h"

CrearPrueba::CrearPrueba(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrearPrueba)
{
    ui->setupUi(this);
}

CrearPrueba::~CrearPrueba()
{
    delete ui;
}
