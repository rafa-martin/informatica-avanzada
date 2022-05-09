#include <windows/mainwindow.h>
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

#include <windows/equipotecnicowindow.h>
#include <usuarios/buscarcrearusuario.h>
#include <pruebas/mostrarprueba.h>
#include <vacunas/regvacunas.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Clinica COVID-19");
    setWindowIcon(QIcon(":/images/uclm-logo.png"));

    // CONNECT USER WINDOW
    //
    QObject::connect(ui->pushUsuarios, &QPushButton::clicked,
                     this, &MainWindow::openEntryPointUsuarios);
    QObject::connect(ui->actionUsuarios, &QAction::triggered,
                     this, &MainWindow::openEntryPointUsuarios);

    // CONNECT TEST WINDOW
    //
    QObject::connect(ui->pushPruebas, &QPushButton::clicked,
                     this, &MainWindow::openEntryPointPruebas);
    QObject::connect(ui->actionPruebas_Diagnosticas, &QAction::triggered,
                     this, &MainWindow::openEntryPointPruebas);

    // CONNECT VACCINE WINDOW
    //
    QObject::connect(ui->pushVacunas, &QPushButton::clicked,
                     this, &MainWindow::openEntryPointVacunas);
    QObject::connect(ui->actionVacunacion, &QAction::triggered,
                     this, &MainWindow::openEntryPointVacunas);

    // CONNECT GROUP WINDOW
    //
    QObject::connect(ui->actionEquipo_tecnico, &QAction::triggered,
                     this, &MainWindow::openEntryPointEquipoTecnico);
    QObject::connect(ui->actionUCLM, &QAction::triggered,
                     this, &MainWindow::openUCLM);
    QObject::connect(ui->actionETSII_CR, &QAction::triggered,
                     this, &MainWindow::openETSII);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openEntryPointUsuarios()
{
    qDebug() << "Abriendo ventana de usuarios";
    BuscarCrearUsuario w(db, this);
    w.exec();
}

void MainWindow::openEntryPointPruebas()
{
    qDebug() << "Abriendo ventana de pruebas";
    MostrarPrueba w(db, this);
    w.exec();
}

void MainWindow::openEntryPointVacunas()
{
    qDebug() << "Abriendo ventana de vacunas";
    RegVacunas w(db, this);
    w.exec();
}

void MainWindow::openEntryPointEquipoTecnico()
{
    qDebug() << "Abriendo ventana de equipo tecnico";
    EquipoTecnicoWindow equipo_tecnico(this);
    equipo_tecnico.exec();
}

void MainWindow::openUCLM()
{
    qDebug() << "Abriendo web UCLM";
    QDesktopServices::openUrl(QUrl("https://www.uclm.es/"));
}

void MainWindow::openETSII()
{
    qDebug() << "Abriendo web ETSII-CR";
    QDesktopServices::openUrl(QUrl("https://www.uclm.es/ciudad-real/etsii"));
}
