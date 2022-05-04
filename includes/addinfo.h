#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>

namespace Ui {
class addinfo;
}

class addinfo : public QDialog
{
    Q_OBJECT

public:
    explicit addinfo(QWidget *parent = nullptr);
    ~addinfo();

private:
    Ui::addinfo *ui;
};

#endif // ADDINFO_H
