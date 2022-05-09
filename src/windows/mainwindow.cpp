#include <windows/mainwindow.h>
#include "ui_mainwindow.h"

#include <windows/equipotecnicowindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openEntryPointUsuarios()
{
    qDebug() << "Abriendo ventana de usuarios";
}

void MainWindow::openEntryPointPruebas()
{
    qDebug() << "Abriendo ventana de pruebas";
}

void MainWindow::openEntryPointVacunas()
{
    qDebug() << "Abriendo ventana de vacunas";
}

void MainWindow::openEntryPointEquipoTecnico()
{
    qDebug() << "Abriendo ventana de equipo tecnico";
    EquipoTecnicoWindow equipo_tecnico(this);
    equipo_tecnico.exec();
}
