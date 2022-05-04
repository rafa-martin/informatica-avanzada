#include "regvacunas.h"
#include "ui_regvacunas.h"

RegVacunas::RegVacunas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegVacunas)
{
    ui->setupUi(this);
}

RegVacunas::~RegVacunas()
{
    delete ui;
}

void RegVacunas::on_pushButton_clicked()
{

}


void RegVacunas::on_pushButton_2_clicked()
{

}


void RegVacunas::on_pushButton_3_clicked()
{

}


void RegVacunas::on_commandLinkButton_clicked()
{
    close();
}

