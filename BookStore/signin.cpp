#include "signin.h"
#include "ui_signin.h"
#include<QMessageBox>
#include<QDebug>
#include"AString.h"
#include"BBSTree.h"
#include"BBSTree.cpp"
#include"stack.h"
#include"Customer.h"
#include"Manager.h"

#include<QFile>
void CreatCustomerListFromFileInSignIn(BBSTree<Customer,int> *customerlsit){
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

void writeCustomerToFileTraveseInSignIn(BBSTNode<Customer,int> *TNode,QTextStream &write){
    if (TNode != NULL){
       writeCustomerToFileTraveseInSignIn(TNode->lchild, write);

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
        writeCustomerToFileTraveseInSignIn(TNode->rchild, write);
    }
}
void PrintCustomerListToFileInSignIn(BBSTree<Customer,int> customerlist){
    QFile writeFile("Customer.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeCustomerToFileTraveseInSignIn(customerlist.getRoot(), in);

}
void CreateManagerListFromFileInSignIn(BBSTree<Manager,int> * managerlist){
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

void writeManagerToFileTraveseInSignIn(BBSTNode<Manager,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeManagerToFileTraveseInSignIn(TNode->lchild, write);
        qDebug()<<"in!"<<endl;
        write << left << qSetFieldWidth(15) << TNode->data->value.getNumber().AStringToString()
            <<qSetFieldWidth(32) << TNode->data->value.getName().AStringToString()
            << qSetFieldWidth(20) << TNode->data->value.getPassword().AStringToString()
            << qSetFieldWidth(15) << TNode->data->value.getPhoneNumber().AStringToString()
            << qSetFieldWidth(12) << TNode->data->value.getType().AStringToString()
            <<qSetFieldWidth(5)<<right<<TNode->data->value.getState()
            << endl;

        writeManagerToFileTraveseInSignIn(TNode->rchild, write);
    }
}
void PrintManagerListToFileInSignIn(BBSTree<Manager,int> managerlist){
    QFile writeFile("Manager.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    //qDebug()<<"in!"<<endl;
    writeManagerToFileTraveseInSignIn( managerlist.getRoot(), in);

}

 BBSTree<Customer,int> customerlistinsignin;
 BBSTree<Manager,int>  managerlistinsignin;


SignIn::SignIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    CreatCustomerListFromFileInSignIn(&customerlistinsignin);
    CreateManagerListFromFileInSignIn(&managerlistinsignin);
}

SignIn::~SignIn()
{
    PrintCustomerListToFileInSignIn(customerlistinsignin);
    PrintManagerListToFileInSignIn(managerlistinsignin);
    delete ui;
}

void SignIn::on_pushButton_2_clicked()
{
    emit nothingDone();
}

void SignIn::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        if(ui->comboBox->currentIndex()==0){
            int number;
            if(managerlistinsignin.BBSTNodeNum()==0){
                number=1;
            }
            else{
                number=managerlistinsignin.getRoot()->data->value.getNumber().AStringToInt();
                Stack<BBSTNode<Manager,int>*> managerstack_signin;
                BBSTNode<Manager,int>* managerptr;
                managerstack_signin.push(managerlistinsignin.getRoot());
                while(!managerstack_signin.isEmpty()){
                    managerstack_signin.pop(managerptr);
                    if(managerptr->data->value.getNumber().AStringToInt()>=number)
                        number=managerptr->data->value.getNumber().AStringToInt();
                    if(managerptr->rchild!=NULL)
                        managerstack_signin.push(managerptr->rchild);
                    if(managerptr->lchild!=NULL)
                        managerstack_signin.push(managerptr->lchild);
                }
                number++;
            }

            if(number>=1000000000){
                QMessageBox::warning(this,tr("Error!"),tr("Too much managers!"),QMessageBox::Yes);
            }
            else{
                if(ui->lineEdit_2->text()!=ui->lineEdit_3->text()){
                    QMessageBox::warning(this,tr("Error!"),tr("Passwords don't match!"),QMessageBox::Yes);
                }
                else{
                    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()){
                        QMessageBox::warning(this,tr("warning!"),tr("Uncompleted!"),QMessageBox::Yes);
                    }
                    else{
                        char numberValue[10];
                        itoa(number,numberValue,10);
                        AString Mnum(numberValue);
                        char *nameValue;
                        QByteArray nameArray=ui->lineEdit->text().toLatin1();
                        nameValue=nameArray.data();
                        AString Mname(nameValue);
                        char* Mpassword;
                        QByteArray passwordArray=ui->lineEdit_2->text().toLatin1();
                        Mpassword=passwordArray.data();
                        AString passwordValue(Mpassword);
                        char *phone;
                        QByteArray phoneArray=ui->lineEdit_4->text().toLatin1();
                        phone=phoneArray.data();
                        AString phoneNumber(phone);
                        if(Mname.Length()>12||passwordValue.Length()<6||passwordValue.Length()>16||phoneNumber.Length()!=11){
                            QMessageBox::warning(this,tr("Error!"),tr("Incorreced name or password or phone number!"),QMessageBox::Yes);

                        }
                        else{
                            int managerState=0;
                            AString type("Manager");
                            Manager manager(managerState,Mnum,Mname,passwordValue,phoneNumber,type);
                            if(managerlistinsignin.InsertBBSTree(manager,Mname.AStringToInt())){
                                //emit returnToWelcome();
                                PrintManagerListToFileInSignIn(managerlistinsignin);
                                QMessageBox::warning(this,tr("Please remember your usernumber!"),tr(manager.getNumber().AStringToString()),QMessageBox::Yes);

                            }

                            else{
                                QMessageBox::warning(this,tr("Error!"),tr("Unusable number!"),QMessageBox::Yes);
                            }
                        }

                    }

                }
            }
        }
        else{
            QMessageBox::warning(this,tr("Error!"),tr("Types Don't Match! "),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_2->isChecked()){
        if(ui->comboBox->currentIndex()==0){
            QMessageBox::warning(this,tr("Error!"),tr("Types Don't match!"),QMessageBox::Yes);
        }
        else{
            int number;
            if(customerlistinsignin.BBSTNodeNum()==0){
                number=1;
            }
            else{
                number=customerlistinsignin.getRoot()->data->value.getNumber().AStringToInt();
                Stack<BBSTNode<Customer,int>*> customerstack_signin;
                customerstack_signin.push(customerlistinsignin.getRoot());
                BBSTNode<Customer,int>* customerptr;
                while(!customerstack_signin.isEmpty()){
                    customerstack_signin.pop(customerptr);
                    if(customerptr->data->value.getNumber().AStringToInt()>=number)
                        number=customerptr->data->value.getNumber().AStringToInt();
                    if(customerptr->rchild!=NULL)
                        customerstack_signin.push(customerptr->rchild);
                    if(customerptr->lchild!=NULL)
                        customerstack_signin.push(customerptr->lchild);
                }
                number++;
            }


            if(number>=1000000000){
                QMessageBox::warning(this,tr("Error!"),tr("Too much customers!"),QMessageBox::Yes);
            }
            else{
                if(ui->lineEdit_2->text()!=ui->lineEdit_3->text()){
                    QMessageBox::warning(this,tr("Error!"),tr("Passwords don't match!"),QMessageBox::Yes);
                }
                else {
                    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()){
                        QMessageBox::warning(this,tr("warning!"),tr("Uncompleted!"),QMessageBox::Yes);
                    }
                    else{
                    char numberValue[10];
                    itoa(number,numberValue,10);
                    AString Cnum(numberValue);
                    char *nameValue;
                    QByteArray nameArray=ui->lineEdit->text().toLatin1();
                    nameValue=nameArray.data();
                    AString Cname(nameValue);
                    char* Mpassword;
                    QByteArray passwordArray=ui->lineEdit_2->text().toLatin1();
                    Mpassword=passwordArray.data();
                    AString passwordValue(Mpassword);
                    char *phone;
                    QByteArray phoneArray=ui->lineEdit_4->text().toLatin1();
                    phone=phoneArray.data();
                    AString phoneNumber(phone);
                    if(Cname.Length()>12||passwordValue.Length()<6||passwordValue.Length()>12||phoneNumber.Length()!=11){
                         QMessageBox::warning(this,tr("Error!"),tr("Incorreced name or password or phone number!"),QMessageBox::Yes);
                    }
                    else{
                        int customerState=0;
                        int typeofCustomer=ui->comboBox->currentIndex()-1;
                        char type[3];
                        itoa(typeofCustomer,type,10);
                        AString typeofVip(type);
                        Vip customerVip(typeofVip);
                        Customer customer(customerState,customerVip,Cnum,Cname,passwordValue,phoneNumber);
                        if(customerlistinsignin.InsertBBSTree(customer,number)){
                            //emit returnToWelcome();
                            PrintCustomerListToFileInSignIn(customerlistinsignin);
                            QMessageBox::warning(this,tr("Please remember your usernnumber:"),tr(customer.getNumber().AStringToString()),QMessageBox::Yes);
                        }
                        else{
                            QMessageBox::warning(this,tr("Error!"),tr("Unusable number!"),QMessageBox::Yes);
                        }
                    }

                  }
               }
           }

       }
    }
    else{
        QMessageBox::warning(this,tr("warning!"),tr("Please complete all first!"),QMessageBox::Yes);
    }
}

void SignIn::on_pushButton_3_clicked()
{
    emit returnToWelcome();
}
