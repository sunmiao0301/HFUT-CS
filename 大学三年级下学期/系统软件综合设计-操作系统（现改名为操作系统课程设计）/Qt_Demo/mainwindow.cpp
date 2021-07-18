#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //init(&chart);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_12, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_12_clicked()));
    connect(ui->pushButton_8, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_8_clicked()));//从文件读取
    connect(ui->pushButton_9, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_9_clicked()));//存入到文件
    connect(ui->pushButton_10, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_10_clicked()));//刷新线条
    connect(ui->pushButton_11, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_11_clicked()));//初始化chart
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)//画线进程1到资源1的申请红线
{
    while(true){
        QPainter paint(this);
        paint.setPen(QPen(Qt::red,5));
        paint.drawLine(530, 33,500, 33);
        paint.drawLine(525, 28,530, 33);
        paint.drawLine(525, 38,530, 33);
        paint.setPen(QPen(Qt::blue,5));
        paint.drawLine(530, 63,500, 63);
        paint.drawLine(505, 68,500, 63);
        paint.drawLine(505, 57,500, 63);
        break;

    }
    //在此图形上下文的坐标系中，使用当前颜色在点 (x1, y1) 和 (x2, y2) 之间画一条线。
    /*
     * 640,120是资源1的点
     *
     * 480,480是进程6的点
     * 480, 410是进程5的点
     * 说明上下距离是70
     */

    //学习java多线程的时候，学到的思想，使用外部公共变量来精确控制函数内部的代码块的调用
    //注意 Qt中每次update 都会重新画 之前的线条也就清除了
    //init(&chart);
    //进程向资源的申请用红线
    QPainter paint(this);
    paint.setPen(QPen(Qt::red,5));
        if(loop == draw_flag){
        for(int r_0 = 0; r_0 < 6; r_0++){
            if((&chart)->Process_To_Resource_Request_Edge[0][r_0] == 1){
                paint.drawLine(530,115 + 70 * r_0,370, 115);
                break;//进程只能向一个资源申请
            }
        }
        //画进程2到资源i的线
        for(int r_1 = 0; r_1 < 6; r_1++){
            if((&chart)->Process_To_Resource_Request_Edge[1][r_1] == 1){
                paint.drawLine(530,115 + 70 * r_1,370, 185);
                //QPainter paint(this);
                //paint.setPen(Qt::red);
                break;//进程只能向一个资源申请
            }
        }
        for(int r_2 = 0; r_2 < 6; r_2++){
            if((&chart)->Process_To_Resource_Request_Edge[2][r_2] == 1){
                //QPainter paint(this);
                //paint.setPen(Qt::red);
                paint.drawLine(530,115 + 70 * r_2,370, 255);
                break;//进程只能向一个资源申请
            }
        }
        for(int r_3 = 0; r_3 < 6; r_3++){
            if((&chart)->Process_To_Resource_Request_Edge[3][r_3] == 1){
                //QPainter paint(this);
                //paint.setPen(Qt::red);
                paint.drawLine(530,115 + 70 * r_3,370, 325);
                break;//进程只能向一个资源申请
            }
        }
        for(int r_4 = 0; r_4 < 6; r_4++){
            if((&chart)->Process_To_Resource_Request_Edge[4][r_4] == 1){
                //QPainter paint(this);
                //paint.setPen(Qt::red);
                paint.drawLine(530,115 + 70 * r_4,370, 395);
                break;//进程只能向一个资源申请
            }
        }
        for(int r_5 = 0; r_5 < 6; r_5++){
            if((&chart)->Process_To_Resource_Request_Edge[5][r_5] == 1){
                //QPainter paint(this);
                //paint.setPen(Qt::red);
                paint.drawLine(530,115 + 70 * r_5,370, 465);
                break;//进程只能向一个资源申请
            }
        }

        //画资源->进程的分配线条
        paint.setPen(QPen(Qt::blue,5));
        r_6_sum = 0;//该类资源分配出去的资源数
        for(int r_6 = 0 ; r_6 < 6; r_6++){
            if((&chart)->Resource_To_Process_Allocation_Edge[0][r_6] != 0){
                r_6_sum += (&chart)->Resource_To_Process_Allocation_Edge[0][r_6];
                paint.drawLine(370, 120 + 70 * r_6, 530, 120);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_6 == 5){
                QString qstr_r_6 = QString::number(r_6_sum,10);
                ui->textEdit_29->setText(qstr_r_6);
            }
        }
        r_7_sum = 0;
        for(int r_7 = 0; r_7 < 6; r_7++){
            if((&chart)->Resource_To_Process_Allocation_Edge[1][r_7] != 0){
                r_7_sum += (&chart)->Resource_To_Process_Allocation_Edge[1][r_7];
                paint.drawLine(370, 120 + 70 * r_7, 530, 190);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_7 == 5){
                QString qstr_r_7 = QString::number(r_7_sum,10);
                ui->textEdit_30->setText(qstr_r_7);
            }
        }
        r_8_sum = 0;
        for(int r_8 = 0; r_8 < 6; r_8++){
            if((&chart)->Resource_To_Process_Allocation_Edge[2][r_8] != 0){
                r_8_sum += (&chart)->Resource_To_Process_Allocation_Edge[2][r_8];
                paint.drawLine(370, 120 + 70 * r_8, 530, 260);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_8 == 5){
                QString qstr_r_8 = QString::number(r_8_sum,10);
                ui->textEdit_31->setText(qstr_r_8);
            }
        }

        r_9_sum = 0;
        for(int r_9 = 0; r_9 < 6; r_9++){
            if((&chart)->Resource_To_Process_Allocation_Edge[3][r_9] != 0){
                r_9_sum += (&chart)->Resource_To_Process_Allocation_Edge[3][r_9];
                paint.drawLine(370, 120 + 70 * r_9, 530, 330);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_9 == 5){
                QString qstr_r_9 = QString::number(r_9_sum,10);
                ui->textEdit_32->setText(qstr_r_9);
            }
        }
        r_10_sum = 0;
        for(int r_10 = 0; r_10 < 6; r_10++){
            if((&chart)->Resource_To_Process_Allocation_Edge[4][r_10] != 0){
                r_10_sum += (&chart)->Resource_To_Process_Allocation_Edge[4][r_10];
                paint.drawLine(370, 120 + 70 * r_10, 530, 400);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_10 == 5){
                QString qstr_r_10 = QString::number(r_10_sum,10);
                ui->textEdit_33->setText(qstr_r_10);
            }
        }
        r_11_sum = 0;
        for(int r_11 = 0; r_11 < 6; r_11++){
            if((&chart)->Resource_To_Process_Allocation_Edge[5][r_11] != 0){
                r_11_sum += (&chart)->Resource_To_Process_Allocation_Edge[5][r_11];
                paint.drawLine(370, 120 + 70 * r_11, 530, 470);
                continue;//进程只能向一个资源申请
            }
            //在方框中显示该类资源分配出去的资源数
            if(r_11 == 5){
                QString qstr_r_11 = QString::number(r_11_sum,10);
                ui->textEdit_34->setText(qstr_r_11);
            }
        }
    }
}
void MainWindow::on_pushButton_10_clicked()//刷新线条 按钮
{
    /*
     * 之所以这样 是因为void MainWindow::paintEvent(QPaintEvent *event)好像有记忆功能 用过的flag就不能用了（没有update作用）
     * 即使用0 1 2 1 2 1 2这样的循环也不行
     *
     */

    //进程点的隐藏
    for(int r_0 = 0; r_0 < 6; r_0++){
        if((&chart)->Process_To_Resource_Request_Edge[0][r_0] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_0][0] == 0){
            if(r_0 == 5){
                ui->textEdit->setVisible(0);
            }
            continue;
        }
        ui->textEdit->setVisible(1);
        break;
    }

    for(int r_1 = 0; r_1 < 6; r_1++){
        if((&chart)->Process_To_Resource_Request_Edge[1][r_1] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_1][1] == 0){
            if(r_1 == 5){
                ui->textEdit_2->setVisible(0);
            }
            continue;
        }
        ui->textEdit_2->setVisible(1);
        break;
    }

    for(int r_2 = 0; r_2 < 6; r_2++){
        if((&chart)->Process_To_Resource_Request_Edge[2][r_2] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_2][2] == 0){
            if(r_2 == 5){
                ui->textEdit_3->setVisible(0);
            }
            continue;
        }
        ui->textEdit_3->setVisible(1);
        break;
    }

    for(int r_3 = 0; r_3 < 6; r_3++){
        if((&chart)->Process_To_Resource_Request_Edge[3][r_3] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_3][3] == 0){
            if(r_3 == 5){
                ui->textEdit_4->setVisible(0);
            }
            continue;
        }
        ui->textEdit_4->setVisible(1);
        break;
    }

    for(int r_4 = 0; r_4 < 6; r_4++){
        if((&chart)->Process_To_Resource_Request_Edge[4][r_4] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_4][4] == 0){
            if(r_4 == 5){
                ui->textEdit_5->setVisible(0);
            }
            continue;
        }
        ui->textEdit_5->setVisible(1);
        break;
    }

    for(int r_5 = 0; r_5 < 6; r_5++){
        if((&chart)->Process_To_Resource_Request_Edge[5][r_5] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[r_5][5] == 0){
            if(r_5 == 5){
                ui->textEdit_6->setVisible(0);
            }
            continue;
        }
        ui->textEdit_6->setVisible(1);
        break;
    }

    //资源点的隐藏
    for(int r_0 = 0; r_0 < 6; r_0++){//资源点1
        if((&chart)->Process_To_Resource_Request_Edge[r_0][0] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[0][r_0] == 0){
            if(r_0 == 5){
                ui->textEdit_8->setVisible(0);
            }
            continue;
        }
        ui->textEdit_8->setVisible(1);
        break;
    }

    for(int r_1 = 0; r_1 < 6; r_1++){
        if((&chart)->Process_To_Resource_Request_Edge[r_1][1] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[1][r_1] == 0){
            if(r_1 == 5){
                ui->textEdit_9->setVisible(0);
            }
            continue;
        }
        ui->textEdit_9->setVisible(1);
        break;
    }

    for(int r_2 = 0; r_2 < 6; r_2++){
        if((&chart)->Process_To_Resource_Request_Edge[r_2][2] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[2][r_2] == 0){
            if(r_2 == 5){
                ui->textEdit_10->setVisible(0);
            }
            continue;
        }
        ui->textEdit_10->setVisible(1);
        break;
    }

    for(int r_3 = 0; r_3 < 6; r_3++){
        if((&chart)->Process_To_Resource_Request_Edge[r_3][3] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[3][r_3] == 0){
            if(r_3 == 5){
                ui->textEdit_11->setVisible(0);
            }
            continue;
        }
        ui->textEdit_11->setVisible(1);
        break;
    }

    for(int r_4 = 0; r_4 < 6; r_4++){
        if((&chart)->Process_To_Resource_Request_Edge[r_4][4] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[4][r_4] == 0){
            if(r_4 == 5){
                ui->textEdit_12->setVisible(0);
            }
            continue;
        }
        ui->textEdit_12->setVisible(1);
        break;
    }

    for(int r_5 = 0; r_5 < 6; r_5++){
        if((&chart)->Process_To_Resource_Request_Edge[r_5][5] == 0 && (&chart)->Resource_To_Process_Allocation_Edge[5][r_5] == 0){
            if(r_5 == 5){
                ui->textEdit_7->setVisible(0);
            }
            continue;
        }
        ui->textEdit_7->setVisible(1);
        break;
    }

    if(loop == 0){
        loop++;
        update();
    }
    else{
        draw_flag++;
        loop++;
        update();
    }
}

void MainWindow::on_pushButton_9_clicked()//存入到文件 按钮
{
    Chart_Write_To_File(&chart);
}

void MainWindow::on_pushButton_8_clicked()//从文件读取 按钮
{
    Chart_Read_From_File(&chart);
}

void MainWindow::on_pushButton_11_clicked()//初始化按钮
{
        init(&chart);

}

void MainWindow::on_pushButton_2_clicked()//删除进程
{
    QString qstr_delete_P = ui->textEdit_20->toPlainText();
    int temp = qstr_delete_P.toInt();
    Delete_Process_Node(&chart, temp);
}

void MainWindow::on_pushButton_3_clicked()//删除资源
{
    QString qstr_delete_R = ui->textEdit_21->toPlainText();
    int temp = qstr_delete_R.toInt();
    Delete_Resource_Node(&chart, temp);
}

void MainWindow::on_pushButton_4_clicked()//删除进程对资源的请求
{
    QString qstr_P = ui->textEdit_19->toPlainText();
    int temp_P = qstr_P.toInt();

    QString qstr_R = ui->textEdit_25->toPlainText();
    int temp_R = qstr_R.toInt();

    Delete_Request_Edge(&chart, temp_P, temp_R);
}

void MainWindow::on_pushButton_5_clicked()//删除资源到进程的分配(一次只删一个资源而不是一个类）
{
    QString qstr_P = ui->textEdit_26->toPlainText();
    int temp_P = qstr_P.toInt();

    QString qstr_R = ui->textEdit_22->toPlainText();
    int temp_R = qstr_R.toInt();

    Delete_Allocation_Edge(&chart, temp_R, temp_P);
}

void MainWindow::on_pushButton_6_clicked()//增加进程对资源的请求（前提是该进程对其他资源没有请求才可以）
{
    QString qstr_P = ui->textEdit_23->toPlainText();
    int temp_P = qstr_P.toInt();

    QString qstr_R = ui->textEdit_27->toPlainText();
    int temp_R = qstr_R.toInt();

    Add_Edge_Process_To_Resource(&chart, temp_P, temp_R);
}

void MainWindow::on_pushButton_7_clicked()//增加资源对进程的分配
{
    QString qstr_P = ui->textEdit_28->toPlainText();
    int temp_P = qstr_P.toInt();

    QString qstr_R = ui->textEdit_24->toPlainText();
    int temp_R = qstr_R.toInt();

    Add_Edge_Resource_To_Process(&chart, temp_R, temp_P);
}

void MainWindow::on_pushButton_clicked()//显示资源数按钮
{
    //每个资源类内的资源个数为qstr 从13开始
    QString qstr_13 = QString::number((&chart)->Resource_Node_Array[0],10);//Resource_Node_Array[]
    ui->textEdit_13->setText(qstr_13);
    QString qstr_14 = QString::number((&chart)->Resource_Node_Array[1],10);//Resource_Node_Array[]
    ui->textEdit_14->setText(qstr_14);
    QString qstr_15 = QString::number((&chart)->Resource_Node_Array[2],10);//Resource_Node_Array[]
    ui->textEdit_15->setText(qstr_15);
    QString qstr_16 = QString::number((&chart)->Resource_Node_Array[3],10);//Resource_Node_Array[]
    ui->textEdit_16->setText(qstr_16);
    QString qstr_17 = QString::number((&chart)->Resource_Node_Array[4],10);//Resource_Node_Array[]
    ui->textEdit_17->setText(qstr_17);
    QString qstr_18 = QString::number((&chart)->Resource_Node_Array[5],10);//Resource_Node_Array[]
    ui->textEdit_18->setText(qstr_18);
}


void MainWindow::on_pushButton_12_clicked()
{
    QString qstr_19 = QString::number(r_6_sum,10);
    ui->textEdit_29->setText(qstr_19);

    QString qstr_20 = QString::number(r_7_sum,10);
    ui->textEdit_30->setText(qstr_20);

    QString qstr_21 = QString::number(r_8_sum,10);
    ui->textEdit_31->setText(qstr_21);

    QString qstr_22 = QString::number(r_9_sum,10);
    ui->textEdit_32->setText(qstr_22);

    QString qstr_23 = QString::number(r_10_sum,10);
    ui->textEdit_33->setText(qstr_23);

    QString qstr_24 = QString::number(r_11_sum,10);
    ui->textEdit_34->setText(qstr_24);
}



void MainWindow::on_pushButton_13_clicked()
{
    int sum = 0;
    Judge_DeadLock(&chart);
    for(int i = 0; i < Resource_Node_Num; i++){
        for(int j = 0; j < Process_Node_Num; j++){
            sum += (&chart)->Resource_To_Process_Allocation_Edge[i][j];
        }
    }
    for(int i = 0; i < Process_Node_Num; i++){
        for(int j = 0; j < Resource_Node_Num; j++){
            sum += (&chart)->Process_To_Resource_Request_Edge[i][j];
        }
    }
    if(sum == 0){
        ui->textEdit_35->clear();//先清空显示窗口再显示，可以达到实时刷新显示的目的
        ui->textEdit_35->setText(QString::fromStdString("N"));
        //ui->textEdit_35->insertPlainText("无");//这里别用append()是添加一个新行显示
    }
    else{
        ui->textEdit_35->clear();
        ui->textEdit_35->setText(QString::fromStdString("Y"));
    }
}
