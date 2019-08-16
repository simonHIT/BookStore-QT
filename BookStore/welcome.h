#ifndef WELCOME_H
#define WELCOME_H
#include"signin.h"
#include"mainwindow.h"
#include"managerwindow.h"
#include <QMainWindow>

namespace Ui {
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();
signals:
    void toCustomerWindow();
    void toManagerWindow();
    void toSigninWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Welcome *ui;


};

#endif // WELCOME_H
