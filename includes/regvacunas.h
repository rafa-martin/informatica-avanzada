#ifndef REGVACUNAS_H
#define REGVACUNAS_H

#include <QDialog>
#include <database/database.hpp>
#include <vacuna.h>


namespace Ui {
class RegVacunas;
}

class RegVacunas : public QDialog
{
    Q_OBJECT

public:
    explicit RegVacunas(IA_Clinic::Database& db,QWidget *parent = nullptr);
    ~RegVacunas();

private slots:

    void on_commandLinkButton_clicked();

    void on_obtener_clicked();

    void on_insertar_clicked();

    void on_registro_clicked();

    void set_data(std::string i);

    vacuna* get_vacuna(int id);

private:
    Ui::RegVacunas *ui;
    IA_Clinic::Database &db;
};

#endif // REGVACUNAS_H
