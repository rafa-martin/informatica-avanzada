#include <windows/equipotecnicowindow.h>
#include "ui_equipotecnicowindow.h"

EquipoTecnicoWindow::EquipoTecnicoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EquipoTecnicoWindow)
{
    ui->setupUi(this);
    setWindowTitle("Equipo de trabajo");
}

EquipoTecnicoWindow::~EquipoTecnicoWindow()
    { delete ui; }
