#pragma once

#include <QDialog>
#include <vacunas/vacuna.h>

namespace Ui {
class getinfo;
}

class getinfo : public QDialog
{
    Q_OBJECT

public:
    explicit getinfo(vacuna& v,QWidget *parent = nullptr);
    ~getinfo();

private slots:
    /**
     * @brief Botón que cierra la ventana y guarda los cambios realizados
     */
    void on_commandLinkButton_clicked();

private:
    Ui::getinfo *ui;
    vacuna& v;
};
