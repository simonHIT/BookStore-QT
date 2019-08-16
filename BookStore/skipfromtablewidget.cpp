#include "skipfromtablewidget.h"
#include "ui_skipfromtablewidget.h"
#include<QListWidget>
#include<QDebug>
SkipFromTableWidget::SkipFromTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkipFromTableWidget)
{
    ui->setupUi(this);
}

SkipFromTableWidget::~SkipFromTableWidget()
{
    delete ui;
}

void SkipFromTableWidget::on_pushButton_clicked()
{
    qDebug()<<"save!"<<endl;
}

void SkipFromTableWidget::on_pushButton_2_clicked()
{
    qDebug()<<"delete!"<<endl;
}
