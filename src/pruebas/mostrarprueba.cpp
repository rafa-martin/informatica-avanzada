#include <pruebas/mostrarprueba.h>
#include "ui_mostrarprueba.h"
#include <pruebas/crearprueba.h>

MostrarPrueba::MostrarPrueba(IA_Clinic::Database &db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MostrarPrueba),
    db(db)
{
    ui->setupUi(this);
    actualizar();
}

MostrarPrueba::~MostrarPrueba()
{
    delete ui;
}

void MostrarPrueba::actualizar()
{

    std::vector<PruebaDiagnostica*>& db_pruebas = db.getDataVector<PruebaDiagnostica*>();
    int cont=0;
    ui->tableWidget->setRowCount(db_pruebas.size());
    for (auto prueba:db_pruebas)
    {
        QString dni = QString::fromStdString(prueba->getdni());
        QString nombre = QString::fromStdString(prueba->getnombre());
        QString fecha = prueba->getFecha().toString();

        //se crea una celda:
        QTableWidgetItem* n_item = new QTableWidgetItem(dni);
        ui->tableWidget->setItem(cont,0, n_item);

        n_item = new QTableWidgetItem(nombre);
        ui->tableWidget->setItem(cont,1, n_item);

        n_item = new QTableWidgetItem(fecha);
        ui->tableWidget->setItem(cont,2, n_item);

        cont=cont+1;
    }
}

void MostrarPrueba::on_pushButton_clicked()
{
    CrearPrueba temp;
    temp.exec();
    temp.getguardar();
    std::vector<PruebaDiagnostica*>& db_pruebas = db.getDataVector<PruebaDiagnostica*>();

    if (temp.getguardar()==true)
    {
        PruebaDiagnostica* nuevaprueba = temp.getprueba();
        db_pruebas.push_back(nuevaprueba); //meter en base de datos pruebas
        actualizar();
    }

}
