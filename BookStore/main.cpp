#include "mainwindow.h"
#include <QApplication>
#include"managerwindow.h"
#include"skipfromtablewidget.h"
#include"welcome.h"
#include"signin.h"
#include"AString.h"
#include"BBSTree.h"
#include"BBSTree.cpp"
#include"stack.h"
#include"WindowManage.h"
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("GBK");//ַי¿צ1

    QTextCodec::setCodecForLocale(codec);


    WindowManage windowmanage;

    return a.exec();

}
