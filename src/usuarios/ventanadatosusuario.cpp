#include <usuarios/ventanadatosusuario.h>
#include "ui_ventanadatosusuario.h"
#include <iostream>

VentanaDatosUsuario::VentanaDatosUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaDatosUsuario)
{
    ui->setupUi(this);
    on_comboBox_currentIndexChanged(0);
}

VentanaDatosUsuario::~VentanaDatosUsuario()
{
    delete ui;
}

usuarios* VentanaDatosUsuario::get_usuario()
{
    if(us==nullptr){
        QString TipoUsuario=ui->comboBox->currentText();
        if(TipoUsuario=="Administrador"){
            administrador* n_admin=new administrador;
            n_admin->Nombre=ui->Nombre->text();
            n_admin->Apellidos=ui->Apellidos->text();
            n_admin->DNI=ui->DNI->text();
            n_admin->Edad=ui->Edad->text().toInt();
            n_admin->Sueldo=ui->Sueldo->text().toDouble();
            n_admin->dpto=ui->Departamento->text();
            return n_admin;
        }else if(TipoUsuario=="Enfermero"){
            enfermero* n_enfer=new enfermero;
            n_enfer->Nombre=ui->Nombre->text();
            n_enfer->Apellidos=ui->Apellidos->text();
            n_enfer->DNI=ui->DNI->text();
            n_enfer->Edad=ui->Edad->text().toInt();
            n_enfer->Sueldo=ui->Sueldo->text().toDouble();
            return n_enfer;
        }else if(TipoUsuario=="Tecnico"){
            tecnico* n_tec=new tecnico;
            n_tec->Nombre=ui->Nombre->text();
            n_tec->Apellidos=ui->Apellidos->text();
            n_tec->DNI=ui->DNI->text();
            n_tec->Edad=ui->Edad->text().toInt();
            n_tec->Sueldo=ui->Sueldo->text().toDouble();
            n_tec->num_laboratorio=ui->NLab->text().toInt();
            return n_tec;
        }else if(TipoUsuario=="Paciente"){
            paciente* n_pac = new paciente;
            n_pac->Nombre=ui->Nombre->text();
            n_pac->Apellidos=ui->Apellidos->text();
            n_pac->DNI=ui->DNI->text();
            n_pac->Edad=ui->Edad->text().toInt();
            n_pac->habitacion=ui->NHab->text().toInt();
            n_pac->infectado=ui->checkBox->checkState();
            return n_pac;
        };
    }
    return us;
}

bool VentanaDatosUsuario::guardar()
{
    return guardado;
}

void VentanaDatosUsuario::on_Guardar_bton_clicked()
{
    guardado=true;
    close();
}


void VentanaDatosUsuario::on_Cancelar_bton_clicked()
{
     close();
}




void VentanaDatosUsuario::on_comboBox_currentIndexChanged(int index)
{
    ui->Sueldo->setEnabled(false);
    ui->Departamento->setEnabled(false);
    ui->NHab->setEnabled(false);
    ui->NLab->setEnabled(false);
    ui->checkBox->setEnabled(false);
    if(index==0){
        ui->Sueldo->setEnabled(true);
        ui->Departamento->setEnabled(true);
    }else if(index==1){
        ui->Sueldo->setEnabled(true);
    }else if(index==2){
        ui->Sueldo->setEnabled(true);
        ui->NLab->setEnabled(true);
    }else if(index==3){
        ui->NHab->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }

}

