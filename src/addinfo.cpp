#include "addinfo.h"
#include "ui_addinfo.h"

addinfo::addinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addinfo)
{
    ui->setupUi(this);
}

addinfo::~addinfo()
{
    delete ui;
}
