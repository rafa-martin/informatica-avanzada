#pragma once

#include <QMainWindow>
#include <database/database.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openEntryPointUsuarios();
    void openEntryPointPruebas();
    void openEntryPointVacunas();

    void openEntryPointEquipoTecnico();

private:
    Ui::MainWindow *ui;
    IA_Clinic::Database db;
};
