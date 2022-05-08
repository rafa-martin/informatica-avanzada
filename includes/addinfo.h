#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <vacuna.h>


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
    void on_commandLinkButton_clicked();

private:
    Ui::addinfo *ui;
    vacuna& v;
};

#endif // ADDINFO_H
