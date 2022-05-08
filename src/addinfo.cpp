#include "addinfo.h"
#include "ui_addinfo.h"
#include <QMessageBox>
#include <regvacunas.h>

addinfo::addinfo(vacuna& v,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addinfo),
    v(v)
{
    ui->setupUi(this);
}

addinfo::~addinfo()
{
    delete ui;
}

void addinfo::on_commandLinkButton_clicked()
{
    if (ui->lineEdit->text()==nullptr){
        QMessageBox box;
        box.setText("Debe agregar un DNI válido");
        box.exec();
        return;
    }
    v.set_dni(ui->lineEdit->text().toStdString());
    v.set_1puesta(ui->dateEdit->date());
    close();
}

