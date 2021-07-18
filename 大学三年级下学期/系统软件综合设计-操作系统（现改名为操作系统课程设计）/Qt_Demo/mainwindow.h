#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Qlabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QImage>
#include <QFileInfo>
#include <QFileDialog>
#include <QVariant>

/*
我们都知道C++语言兼容C语言，那么C++调用C语言库，为什么为什么需要 extern "C"的帮助？
答案就是C++语言为了支持重构（重构的特征﻿：相同的范围、相同的名字、不同的参数），在编译时对函数的命名方式进行了改变，编译后的名字包括一些参数的信息，这样才能在调用函数的时候对号入座。
那么extern "C"的作用，就是“提示”（为什么说提示，而不是“命令”呢，下面会分析）编译器，下面的文件和函数，要用C语言的命名规则进行。
所以加入要在A.cpp中使用C语言的B.lib库文件中的在xx.h中定义的导出函数CFun()，需要这么做。
*/

//#ifdef __cplusplus
//extern "C" {

//#include "Resource_Allocation_Chart.h"

//#endif
//#ifdef __cplusplus
//}
//#endif

#include "D:/OS_EXPL/Os_Kernal/Os_Kernal/Resource_Allocation_Chart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //画图标志位
        int draw_flag = 1;
        int loop = 0;
    int r_6_sum = 0;
    int r_7_sum = 0;
    int r_8_sum = 0;
    int r_9_sum = 0;
    int r_10_sum = 0;
    int r_11_sum = 0;

//结构体声明
    struct Resourece_Allocation_Chart chart;

private slots:
    void on_pushButton_clicked();

    void paintEvent(QPaintEvent *event);//画线函数

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
