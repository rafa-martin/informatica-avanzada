#include "getinfo.h"
#include "ui_getinfo.h"

getinfo::getinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getinfo)
{
    ui->setupUi(this);
}

getinfo::~getinfo()
{
    delete ui;
}
