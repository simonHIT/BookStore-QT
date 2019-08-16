#ifndef WINDOWMANAGE_H
#define WINDOWMANAGE_H

#include <QObject>
#include"welcome.h"
#include"signin.h"
#include"mainwindow.h"
#include"managerwindow.h"
class WindowManage : public QObject
{
    Q_OBJECT
public:
    explicit WindowManage(QObject *parent = 0);

private slots:
    void displayCustomer();
    void displaySignIn();
    void displayManager();
    void closeSignIn();
    void updateWindows();

private:
    Welcome *welcome;
    MainWindow *customer;
    ManagerWindow *managerwindow;
    SignIn *signinwindow;
};

#endif // WINDOWMANAGE_H
