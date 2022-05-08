#ifndef MOSTRARPRUEBA_H
#define MOSTRARPRUEBA_H

#include <QDialog>

namespace Ui {
class MostrarPrueba;
}

class MostrarPrueba : public QDialog
{
    Q_OBJECT

public:
    explicit MostrarPrueba(QWidget *parent = nullptr);
    ~MostrarPrueba();

private:
    Ui::MostrarPrueba *ui;
};

#endif // MOSTRARPRUEBA_H
