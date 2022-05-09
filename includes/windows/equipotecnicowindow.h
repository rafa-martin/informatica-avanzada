#pragma once
#include <QDialog>

namespace Ui
    { class EquipoTecnicoWindow; }

class EquipoTecnicoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EquipoTecnicoWindow(QWidget *parent = nullptr);
    ~EquipoTecnicoWindow();

private:
    Ui::EquipoTecnicoWindow *ui;
};
