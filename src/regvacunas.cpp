#include "regvacunas.h"
#include "ui_regvacunas.h"
#include "vacuna.h"
#include <getinfo.h>
#include <addinfo.h>
#include <vector>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
using namespace std;

RegVacunas::RegVacunas(IA_Clinic::Database &db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegVacunas),
    db(db)
{
    ui->setupUi(this);
}

RegVacunas::~RegVacunas()
{
    delete ui;
}


void RegVacunas::set_data(string i){

}

vacuna* RegVacunas::get_vacuna(int id){
    std::vector<vacuna*>& vacunas = db.getDataVector<vacuna*>();
    for (auto e : vacunas){
        if (e->identificador==id){
            return e;
        }
    }
    return nullptr;
}

void RegVacunas::on_commandLinkButton_clicked()
{
    close();
}


void RegVacunas::on_obtener_clicked()
{
    int id= ui->lineEdit->text().toInt();
    vacuna* v1=get_vacuna(id);
    if (v1==nullptr){
        QMessageBox box;
        box.setText("No se ha encontrado una vacuna con ese identificador");
        box.exec();
        return;
    }

    getinfo c(*v1);
    c.exec();
}


void RegVacunas::on_insertar_clicked()
{
    int id= ui->lineEdit->text().toInt();
    if (ui->lineEdit->text()==nullptr){
        QMessageBox box;
        box.setText("Debe agregar un identificador");
        box.exec();
        return;
    }else{
        vacuna* v1=get_vacuna(id);
        if (v1!=nullptr){
            QMessageBox box;
            box.setText("Ese identificador ya está asignado");
            box.exec();
            return;
        }else{

            std::vector<vacuna*>& vacunas = db.getDataVector<vacuna*>();
            vacuna* v2=new_vacuna(id);
            vacunas.push_back(v2);
            addinfo add(*v2);
            add.exec();
        }
    }

}


void RegVacunas::on_registro_clicked()
{
    std::vector<vacuna*>& vacunas = db.getDataVector<vacuna*>();
    ui->listWidget->clear();
    for (auto e : vacunas){
        ui->listWidget->addItem(QString::fromStdString(e->Get_datos()));
    }
}

