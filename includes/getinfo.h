#ifndef GETINFO_H
#define GETINFO_H

#include <QDialog>
#include <vacuna.h>

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
    void on_commandLinkButton_clicked();

private:
    Ui::getinfo *ui;
    vacuna& v;
};

#endif // GETINFO_H
