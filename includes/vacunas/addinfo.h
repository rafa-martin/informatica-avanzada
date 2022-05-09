#pragma once

#include <QDialog>
#include <vacunas/vacuna.h>

namespace Ui {
class addinfo;
}

class addinfo : public QDialog
{
    Q_OBJECT

public:
    explicit addinfo(vacuna& v,QWidget *parent = nullptr);
    ~addinfo();

private slots:
    /**
     * @brief Botón que cierra la ventana y guarda los cambios realizados
     */
    void on_commandLinkButton_clicked();

private:
    Ui::addinfo *ui;
    vacuna& v;
};
