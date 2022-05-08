#ifndef MOSTRARPRUEBA_H
#define MOSTRARPRUEBA_H
#include <database/database.hpp>
#include <QDialog>

namespace Ui {
class MostrarPrueba;
}

class MostrarPrueba : public QDialog
{
    Q_OBJECT

public:
    explicit MostrarPrueba(IA_Clinic::Database &db,QWidget *parent = nullptr);
    ~MostrarPrueba();
    void actualizar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MostrarPrueba *ui;
    IA_Clinic::Database &db;
};

#endif // MOSTRARPRUEBA_H
