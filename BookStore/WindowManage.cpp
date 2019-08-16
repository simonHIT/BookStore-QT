#include "WindowManage.h"

WindowManage::WindowManage(QObject *parent) : QObject(parent)
{
   welcome=new Welcome;
   customer=new MainWindow;
   signinwindow= new SignIn;
   managerwindow=new ManagerWindow;
   connect(welcome,SIGNAL(toSigninWindow()),this,SLOT(displaySignIn()));
   connect(welcome,SIGNAL(toCustomerWindow()),this,SLOT(displayCustomer()));
   connect(welcome,SIGNAL(toManagerWindow()),this,SLOT(displayManager()));
   connect(signinwindow,SIGNAL(nothingDone()),this,SLOT(closeSignIn()));
   connect(signinwindow,SIGNAL(returnToWelcome()),this,SLOT(updateWindows()));
   welcome->show();
}

void WindowManage::displayCustomer()
{
    //customer=new MainWindow;
    delete customer;
    welcome->close();
    delete welcome;
    customer=new MainWindow;
    customer->show();

}

void WindowManage::displaySignIn()
{
    //signinwindow= new SignIn;
    signinwindow->show();
}

void WindowManage::displayManager()
{
   //managerwindow=new ManagerWindow;
    delete managerwindow;
    welcome->close();
    delete welcome;
    managerwindow=new ManagerWindow;
    managerwindow->show();
}

void WindowManage::closeSignIn()
{
    signinwindow->close();
}

void WindowManage::updateWindows()
{

    delete welcome;
    signinwindow->close();
    delete customer;
    delete managerwindow;
    delete signinwindow;
    welcome =new Welcome;
    signinwindow=new SignIn;
    customer=new MainWindow;
    managerwindow=new ManagerWindow;
    connect(welcome,SIGNAL(toCustomerWindow()),this,SLOT(displayCustomer()));
    connect(welcome,SIGNAL(toManagerWindow()),this,SLOT(displayManager()));
    connect(signinwindow,SIGNAL(nothingDone()),this,SLOT(closeSignIn()));
    connect(signinwindow,SIGNAL(returnToWelcome()),this,SLOT(updateWindows()));
    connect(welcome,SIGNAL(toSigninWindow()),this,SLOT(displaySignIn()));
    welcome->show();

}




