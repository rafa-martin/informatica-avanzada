#ifndef GETINFO_H
#define GETINFO_H

#include <QDialog>

namespace Ui {
class getinfo;
}

class getinfo : public QDialog
{
    Q_OBJECT

public:
    explicit getinfo(QWidget *parent = nullptr);
    ~getinfo();

private:
    Ui::getinfo *ui;
};

#endif // GETINFO_H
