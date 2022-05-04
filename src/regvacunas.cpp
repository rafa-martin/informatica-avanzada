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
