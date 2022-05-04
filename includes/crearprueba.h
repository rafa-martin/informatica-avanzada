#ifndef CREARPRUEBA_H
#define CREARPRUEBA_H

#include <QDialog>

namespace Ui {
class CrearPrueba;
}

class CrearPrueba : public QDialog
{
    Q_OBJECT

public:
    explicit CrearPrueba(QWidget *parent = nullptr);
    ~CrearPrueba();

private:
    Ui::CrearPrueba *ui;
};

#endif // CREARPRUEBA_H
