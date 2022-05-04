#ifndef REGVACUNAS_H
#define REGVACUNAS_H

#include <QDialog>

namespace Ui {
class RegVacunas;
}

class RegVacunas : public QDialog
{
    Q_OBJECT

public:
    explicit RegVacunas(QWidget *parent = nullptr);
    ~RegVacunas();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::RegVacunas *ui;
};

#endif // REGVACUNAS_H
