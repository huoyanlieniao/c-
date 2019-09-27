#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include<shujuchuli.h>
#include<suijishu.h>
#include<paixumin.h>
#include<paixumax.h>
#include<yhshuru.h>
#include<string>
#include<QTextBlock>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //connect(this->ui->btn_sToB,SIGNAL(clicked(bool)),this,SLOT(login()));
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_btn_random_clicked()
{

    suiji::qMain();
    ui->plainTextEdit_2->setPlainText("随机数完成");
}

void MainWindow::on_pushButton_clicked()
{

    chuli::qMain();
    ui->plainTextEdit_2->setPlainText("数据处理完成");
}

void MainWindow::on_btn_sToB_clicked()
{
    paixumin::qMain();
    ui->plainTextEdit_2->setPlainText("排序完成");
}

void MainWindow::on_btn_bToS_clicked()
{
    paixumax::qMain();
     ui->plainTextEdit_2->setPlainText("排序完成");
}





void MainWindow::on_btn_cancel_clicked()
{
    MainWindow::close();
}



void MainWindow::on_pushButton_4_clicked()
{
    kuang::qMain();
  //  String str = plainTextEdit ->

}

