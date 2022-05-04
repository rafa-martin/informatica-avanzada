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

private:
    Ui::RegVacunas *ui;
};

#endif // REGVACUNAS_H
