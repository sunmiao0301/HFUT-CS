#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    //Resourece_Allocation_Chart chart;
    //init(&chart);
    //Chart_Read_From_File(&chart);
    //Add_Edge_Resource_To_Process(&chart, 1, 1);
    //Add_Edge_Process_To_Resource(&chart, 6, 1);
    //Delete_Resource_Node(&chart, 2);
    //Delete_Process_Node(&chart, 1);
    //Delete_Allocation_Edge(&chart, 2, 2);
    //Delete_Request_Edge(&chart, 2, 2);
    //Chart_Write_To_File(&chart);

    w.show();
    return a.exec();
}


