#include "getinfo.h"
#include "ui_getinfo.h"
#include <regvacunas.h>
#include <QString>

getinfo::getinfo(vacuna& v,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getinfo),
    v(v)
{
    ui->setupUi(this);
    ui->dni->setText(QString::fromStdString(v.Get_DNI()));
    ui->tipo->setText(QString::fromStdString(v.Get_tipo()));
    ui->tipo->setEnabled(false);
    string Tipo=v.Get_tipo();
    //Si es de una sola puesta no aparece la opcion de la segunda
    if (Tipo=="Johnson"){
        ui->dateEdit_2->setVisible(false);
        ui->label_3->setVisible(false);
    }
    else{
        ui->dateEdit_2->setVisible(true);
        ui->label_3->setVisible(true);
    }
    ui->dateEdit->setDate(v.Get_fechas()[0]);
    ui->dateEdit_2->setDate(v.Get_fechas()[1]);
}

getinfo::~getinfo()
{
    delete ui;
}

void getinfo::on_commandLinkButton_clicked()
{
    v.set_dni(ui->dni->text().toStdString());
    v.set_1puesta(ui->dateEdit->date());
    close();
}

