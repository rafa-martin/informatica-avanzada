#include "mainwindow.h"
#include <vacuna.h>
#include <getinfo.h>
#include <regvacunas.h>
#include <vector>
#include <QApplication>
#include <database/database.hpp>
//main
int main(int argc, char *argv[])
{

    QApplication a(argc,argv);
    //MainWindow w;
    //w.show();
    //return a.exec();

    IA_Clinic::Database db;
    std::vector<vacuna*>& vacunas = db.getDataVector<vacuna*>();
   // vacuna& v1=vacunas.emplace_back();
    vacuna* v2=new_vacuna(5);
    vacunas.push_back(v2);
    v2->set_dni("02546C");
    RegVacunas r(db);
    r.exec();

    //cout<<v2->Get_datos();

    //getinfo c(*v2);
    //c.exec();


    return 0;
}
