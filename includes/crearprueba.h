#ifndef CREARPRUEBA_H
#define CREARPRUEBA_H

#include <QDialog>
#include <pruebadiagnostica.h>

namespace Ui {
class CrearPrueba;
}

class CrearPrueba : public QDialog
{
    Q_OBJECT

public:
    explicit CrearPrueba(QWidget *parent = nullptr);
    ~CrearPrueba();

    bool getguardar();
    void test();
    PruebaDiagnostica* getprueba();


private slots:
    void on_guardar_clicked();

    void on_pushButton_clicked();

private:
    bool guardar=false;
    Ui::CrearPrueba *ui;
};

#endif // CREARPRUEBA_H
