#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>

namespace Ui {
class SignIn;
}

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();
signals:
    void returnToWelcome();
    void nothingDone();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SignIn *ui;

};

#endif // SIGNIN_H
