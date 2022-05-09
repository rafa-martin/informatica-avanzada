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
            n_admin->Sueldo=ui->Sueldo->text().toDouble();
            n_admin->dpto=ui->Departamento->text();
            us=n_admin;
        }else if(TipoUsuario=="Enfermero"){
            enfermero* n_enfer=new enfermero;
            n_enfer->Sueldo=ui->Sueldo->text().toDouble();
            us=n_enfer;
        }else if(TipoUsuario=="Tecnico"){
            tecnico* n_tec=new tecnico;
            n_tec->Sueldo=ui->Sueldo->text().toDouble();
            n_tec->num_laboratorio=ui->NLab->text().toInt();
            us=n_tec;
        }else if(TipoUsuario=="Paciente"){
            paciente* n_pac = new paciente;
            n_pac->habitacion=ui->NHab->text().toInt();
            n_pac->infectado=ui->checkBox->checkState();
            us=n_pac;
        }

    }else{
        QString tipo=us->obtener_tipo();
        if ("administrador"==tipo){
            /*cambiamos el valor de us de usuario a administrador, lo ponemos con referencia parq eu realice las modificaciones de los campos*/
            administrador& admin=static_cast<administrador&> (*us);
            admin.Sueldo=ui->Sueldo->text().toDouble();
            admin.dpto=ui->Departamento->text();
        }else if("enfermero"==tipo){
            enfermero& enfer=static_cast<enfermero&> (*us);
            enfer.Sueldo=ui->Sueldo->text().toDouble();
        }else if("tecnico"==tipo){
            tecnico& tec=static_cast<tecnico&> (*us);
            tec.Sueldo=ui->Sueldo->text().toDouble();
            tec.num_laboratorio=ui->NLab->text().toInt();
        }else if("paciente"==tipo){
            paciente& pac=static_cast<paciente&> (*us);
            pac.habitacion=ui->NHab->text().toInt();
            pac.infectado=ui->checkBox->checkState();
        }
    }
    if (us==nullptr){
        std::cout << "Error totalmente inesperado" << std::endl;
        return us;
    }
    us->Nombre=ui->Nombre->text();
    us->Apellidos=ui->Apellidos->text();
    us->DNI=ui->DNI->text();
    us->Edad=ui->Edad->text().toInt();
    return us;
}

void VentanaDatosUsuario::set_usuario(usuarios* usuario)
{
    us=usuario;
    ui->Nombre->setText(us->Nombre);
    ui->Apellidos->setText(us->Apellidos);
    ui->DNI->setText(us->DNI);
    ui->Edad->setText(QString::number(us->Edad));
    QString tipo=us->obtener_tipo();
    ui->comboBox->setEnabled(false);
    ui->DNI->setEnabled(false);
    if ("administrador"==tipo){
        ui->comboBox->setCurrentIndex(0);
        administrador& admin=static_cast<administrador&> (*us);
        ui->Sueldo->setText(QString::number(admin.Sueldo));
        ui->Departamento->setText(admin.dpto);
    }else if("enfermero"==tipo){
        ui->comboBox->setCurrentIndex(1);
        enfermero& enfer=static_cast<enfermero&> (*us);
        ui->Sueldo->setText(QString::number(enfer.Sueldo));
    }else if("tecnico"==tipo){
        ui->comboBox->setCurrentIndex(2);
        tecnico& tec=static_cast<tecnico&> (*us);
        ui->Sueldo->setText(QString::number(tec.Sueldo));
        ui->NLab->setText(QString::number(tec.num_laboratorio));
    }else if("paciente"==tipo){
        ui->comboBox->setCurrentIndex(3);
        paciente& pac=static_cast<paciente&> (*us);
        ui->NHab->setText(QString::number(pac.habitacion));
        ui->checkBox->setChecked(pac.infectado);
    }
}

void VentanaDatosUsuario::set_dni(QString DNI)
{
    ui->DNI->setText(DNI);
    ui->DNI->setEnabled(false);
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

