#include "welcome.h"
#include "ui_welcome.h"
#include<qmessagebox.h>
#include<QDebug>
#include<QEvent>
#include"BBSTree.h"
#include"BBSTree.cpp"

#include"Customer.h"
#include"Manager.h"
#include"stack.h"
#include<QFile>
void CreatCustomerListFromFileInWelcome(BBSTree<Customer,int> *customerlsit){
    QFile readFile("Customer.txt");
        if (!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            cerr << "File could not be opened." << endl;

        }
        QTextStream out(&readFile);
        char cNumber[12], cName[64], passWord[20], phone[15],type[2],typeName[10];
        int borrowPrivilage;
        double money;
        double buyPrivilage;
        int state;
        while (!out.atEnd()){
            out >> cNumber >> cName >> passWord>>phone>> type >> typeName >> borrowPrivilage >> buyPrivilage>>money>>state;
            AString Cnum(cNumber);
            AString Cname(cName);
            AString PassWord(passWord);
            AString Phone(phone);
            AString VType(type);
            Vip vip(VType);
            if(Cnum.Length()>0){
                Customer customer(state,vip,Cnum,Cname,PassWord,Phone);
                customerlsit->InsertBBSTree(customer, Cnum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< customerlsit->BBSTNodeNum() << " customers have been inserted!" << endl;
}

void writeCustomerToFileTraveseInWelcome(BBSTNode<Customer,int> *TNode,QTextStream &write){
    if (TNode != NULL){
       writeCustomerToFileTraveseInWelcome(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getNumber().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getName().AStringToString()
            <<qSetFieldWidth(20)<<TNode->data->value.getPassword().AStringToString()
            << qSetFieldWidth(20) << TNode->data->value.getPhoneNumber().AStringToString()
            << qSetFieldWidth(2) << TNode->data->value.getVip().getType().AStringToString()
            << qSetFieldWidth(10) << TNode->data->value.getVip().getTypeName().AStringToString()
            << qSetFieldWidth(10) << TNode->data->value.getVip().getBorrowPrivilage()
            << qSetFieldWidth(10) << fixed <<TNode->data->value.getVip().getBuyPrivilage()
            << qSetFieldWidth(10) <<  fixed<< TNode->data->value.getVip().getMoney()
            <<right <<qSetFieldWidth(5)<<TNode->data->value.getState()<< endl;
        writeCustomerToFileTraveseInWelcome(TNode->rchild, write);
    }
}
void PrintCustomerListToFileInWelcome(BBSTree<Customer,int> customerlist){
    QFile writeFile("Customer.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeCustomerToFileTraveseInWelcome(customerlist.getRoot(), in);

}
void CreateManagerListFromFileInWelcome(BBSTree<Manager,int> * managerlist){
    QFile readFile("Manager.txt");
        if (!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            cerr << "File could not be opened." << endl;

        }
        QTextStream out(&readFile);
        char mNumber[12], mName[64], passWord[20], phone[15], managerType[12];
        int state;

        while (!out.atEnd()){
            out >>mNumber >> mName >>  passWord>> phone>>  managerType>>state ;
            AString Mnum(mNumber);
            AString Mname( mName);
            AString PassWord(passWord);
            AString Phone(phone);
            AString MType(managerType);
            if(Mnum.Length()>0){
                Manager manager(state,Mnum,Mname,PassWord,Phone,MType);
                managerlist->InsertBBSTree(manager, Mnum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<<managerlist->BBSTNodeNum() << " managers have been inserted!" << endl;
}

void writeManagerToFileTraveseInWelcome(BBSTNode<Manager,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeManagerToFileTraveseInWelcome(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getNumber().AStringToString()
            <<qSetFieldWidth(32) << TNode->data->value.getName().AStringToString()
            << qSetFieldWidth(20) << TNode->data->value.getPassword().AStringToString()
            << qSetFieldWidth(15) << TNode->data->value.getPhoneNumber().AStringToString()
            << qSetFieldWidth(12) << TNode->data->value.getType().AStringToString()
            <<qSetFieldWidth(5)<<right<<TNode->data->value.getState()
            << endl;
            qDebug()<<TNode->data->value.getState()<<endl;
        writeManagerToFileTraveseInWelcome(TNode->rchild, write);
    }
}
void PrintManagerListToFileInWelcome(BBSTree<Manager,int> managerlist){
    QFile writeFile("Manager.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeManagerToFileTraveseInWelcome( managerlist.getRoot(), in);

}

 BBSTree<Customer,int> customerlistinwelcome;
 BBSTree<Manager,int>  managerlistinwelcome;

Welcome::Welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    CreatCustomerListFromFileInWelcome(&customerlistinwelcome);
    CreateManagerListFromFileInWelcome(&managerlistinwelcome);

}

Welcome::~Welcome()
{
    PrintCustomerListToFileInWelcome(customerlistinwelcome);
    PrintManagerListToFileInWelcome(managerlistinwelcome);
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        Stack<BBSTNode<Customer,int>*> customerstack_welcome;
        BBSTNode<Customer,int>* customerptr_welcome;
        customerstack_welcome.push(customerlistinwelcome.getRoot());
        int find=0;
        while(!customerstack_welcome.isEmpty()&&find<1){
            customerstack_welcome.pop(customerptr_welcome);
            if(ui->lineEdit->text()==tr(customerptr_welcome->data->value.getNumber().AStringToString())&&ui->lineEdit_2->text()
                    ==tr(customerptr_welcome->data->value.getName().AStringToString())&&ui->lineEdit_3->text()
                    ==tr(customerptr_welcome->data->value.getPassword().AStringToString())){
                customerptr_welcome->data->value.setState(1);
                PrintCustomerListToFileInWelcome(customerlistinwelcome);
                find++;
                emit toCustomerWindow();
            }
            if(customerptr_welcome->rchild!=NULL)
                customerstack_welcome.push(customerptr_welcome->rchild);
            if(customerptr_welcome->lchild!=NULL)
                customerstack_welcome.push(customerptr_welcome->lchild);
        }
        if(find==0){
            QMessageBox::warning(this,tr("warning!"),tr("user number or user name or user password error!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_2->isChecked()){
        Stack<BBSTNode<Manager,int>*> managerstack_welcome;
        BBSTNode<Manager,int>* managerptr_welcome;
        managerstack_welcome.push(managerlistinwelcome.getRoot());
        int findmanager=0;
        while (!managerstack_welcome.isEmpty()&&findmanager<1) {
            managerstack_welcome.pop(managerptr_welcome);
            if(ui->lineEdit->text()==tr(managerptr_welcome->data->value.getNumber().AStringToString())&&ui->lineEdit_2->text()==
                    tr(managerptr_welcome->data->value.getName().AStringToString())&&ui->lineEdit_3->text()==
                    tr(managerptr_welcome->data->value.getPassword().AStringToString())){
                managerptr_welcome->data->value.setState(1);
                PrintManagerListToFileInWelcome(managerlistinwelcome);
                findmanager++;

               emit toManagerWindow();

            }
            if(managerptr_welcome->rchild!=NULL)
                managerstack_welcome.push(managerptr_welcome->rchild);
            if(managerptr_welcome->lchild!=NULL)
                managerstack_welcome.push(managerptr_welcome->lchild);
        }
        if(findmanager==0){
            QMessageBox::warning(this,tr("warning!"),tr("user number or user name or user password error!"),QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::warning(this,tr("Error!"),tr("Not choose a way!"),QMessageBox::Yes);
    }

}

void Welcome::on_pushButton_2_clicked()
{
    emit toSigninWindow();

}

