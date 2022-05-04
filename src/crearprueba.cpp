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

void CrearPrueba::test()
{
    QString dni=ui->dni->text();
    QDate fecha=ui->dateEdit->date();
    QString prueba=ui->tipoprueba->currentText();

}

void CrearPrueba::on_guardar_clicked()
{
    guardar=true;
    close();
}


void CrearPrueba::on_pushButton_clicked()
{
    close();
}

bool CrearPrueba::getguardar()
{
    return guardar;
}

