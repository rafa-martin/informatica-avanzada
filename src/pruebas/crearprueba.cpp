#include <pruebas/crearprueba.h>
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

void CrearPrueba::on_guardar_clicked()
{
    guardar=true;
    close();
}

PruebaDiagnostica* CrearPrueba::getprueba()
{
    QString prueba=ui->tipoprueba->currentText();
    PruebaDiagnostica* P=nullptr;
    if (prueba=="PCR")
    {
        P=new PCR();
    }
    else if (prueba=="Antigenos")
    {
        P=new Antigenos();
    }
    QString dni=ui->dni->text();
    P->setdni(dni.toStdString());

    QDate fecha=ui->dateEdit->date();
    P->setFecha(fecha.day(),fecha.month(),fecha.year());

    return P;
}

void CrearPrueba::on_pushButton_clicked()
{
    close();
}

bool CrearPrueba::getguardar()
{
    return guardar;
}

