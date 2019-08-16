#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void buybook();

private slots:

    void namechange_handle();
    void passwordchange_handle();
    void phonechange_handle();
    void on_pushButton_clicked();
    void bookselection_handle();
    //void saveAllFiles();
    //void closeEvent(QCloseEvent* event);


    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
