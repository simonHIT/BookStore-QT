#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
#include"stack.h"
#include"BBSTree.h"
#include"BBSTree.cpp"
#include"Book.h"
#include"Book.cpp"
#include"Customer.h"
#include"Manager.h"
#include"BorrowRecord.h"
#include"BuyRecord.h"
#include"Date.h"
#include<QFile>
void CreateBookTreeFromFile(BBSTree<Book, int> *booklist){
    QFile readFile("Book.txt");
        if (!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            cerr << "File could not be opened." << endl;

        }
        QTextStream out(&readFile);

        char bookNumber[12], bookName[64], type[4],typeName[64], writerName[64];
        int currentNumber;
        int inventory;
        double itemPrice;
        while (!out.atEnd()){
            out >> bookNumber >> bookName >> type>>typeName>> writerName >> currentNumber >> inventory >> itemPrice;
            AString bnum(bookNumber);
            AString bname(bookName);
            AString btype(type);
            BookType booktype(type);
            AString wname(writerName);
            Book book(booktype, bnum, bname, wname, currentNumber, inventory, itemPrice);
            if(bnum.Length()>0){
                booklist->InsertBBSTree(book, bnum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< booklist->BBSTNodeNum() << " books have been inserted!" << endl;
}
void writeBookToFileTravese(BBSTNode<Book, int> *TNode,QTextStream & write){
    if (TNode != NULL){
        writeBookToFileTravese(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getBookNumber().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getBookName().AStringToString()
            << qSetFieldWidth(5) << TNode->data->value.getBookType().getType().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getBookType().getTypeName().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getWriterName().AStringToString()
            << qSetFieldWidth(10) << TNode->data->value.getCurrentNumber()
            << qSetFieldWidth(10) << TNode->data->value.getInventory()
            << qSetFieldWidth(10) << right << fixed << TNode->data->value.getItemPrice() << endl;
        writeBookToFileTravese(TNode->rchild, write);
    }
}
void PrintBookTreeToFile(BBSTree<Book, int> booklist){
    QFile writeFile("Book.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeBookToFileTravese(booklist.getRoot(), in);


}
void CreatCustomerListFromFile(BBSTree<Customer,int> *customerlsit){
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

void writeCustomerToFileTravese(BBSTNode<Customer,int> *TNode,QTextStream &write){
    if (TNode != NULL){
       writeCustomerToFileTravese(TNode->lchild, write);

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
        writeCustomerToFileTravese(TNode->rchild, write);
    }
}
void PrintCustomerListToFile(BBSTree<Customer,int> customerlist){
    QFile writeFile("Customer.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeCustomerToFileTravese(customerlist.getRoot(), in);

}
void CreateManagerListFromFile(BBSTree<Manager,int> * managerlist){
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

void writeManagerToFileTravese(BBSTNode<Manager,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeManagerToFileTravese(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getNumber().AStringToString()
            <<qSetFieldWidth(32) << TNode->data->value.getName().AStringToString()
            << qSetFieldWidth(20) << TNode->data->value.getPassword().AStringToString()
            << qSetFieldWidth(15) << TNode->data->value.getPhoneNumber().AStringToString()
            << qSetFieldWidth(12) << TNode->data->value.getType().AStringToString()
            <<qSetFieldWidth(5)<<right<<TNode->data->value.getState()
            << endl;

        writeManagerToFileTravese(TNode->rchild, write);
    }
}
void PrintManagerListToFile(BBSTree<Manager,int> managerlist){
    QFile writeFile("Manager.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeManagerToFileTravese( managerlist.getRoot(), in);

}
void CreateBorrowRecordListFromFile(BBSTree<BorrowRecord,int> *borrowrecordlist){
    QFile readFile("BorrowRecord.txt");
        if (!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            cerr << "File could not be opened." << endl;

        }
        QTextStream out(&readFile);
        char  recordNumber[12],customerNumber[12], customerName[12],customerPhone[15], bookNumber[12],bookName[32],writer[12],borrowTime[10],returnTime[10];
        int borrowSate;

        int borrowPrivilage;

        while (!out.atEnd()){
            out >> recordNumber>> customerNumber >> customerName>>customerPhone>>  bookNumber >> bookName >> writer >> borrowTime>>returnTime>>borrowSate>>borrowPrivilage;
            AString RecordNum(recordNumber);
            AString CustomerNum(customerNumber);
            AString CustomerName(customerName);
            AString CustomerPhone(customerPhone);
            AString BookNumber(bookNumber);
            AString BookName(bookName);
            AString Writer(writer);
            AString BorrowTime(borrowTime);
            AString ReturnTime(returnTime);
            Date BorrowDate(BorrowTime);
            Date ReturnDate(ReturnTime);
            bool returnstate=false;
            if(borrowSate==1){
                returnstate=true;
            }
            if(RecordNum.Length()>0){
                BorrowRecord borrowrecord(BorrowDate, RecordNum,CustomerNum, CustomerName, CustomerPhone,BookNumber,BookName,Writer,borrowPrivilage,returnstate);

                borrowrecordlist->InsertBBSTree(borrowrecord, RecordNum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< borrowrecordlist->BBSTNodeNum() << " borrowrecords have been inserted!" << endl;
}

void writeBorrowRecordToFileTravese(BBSTNode<BorrowRecord,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeBorrowRecordToFileTravese(TNode->lchild, write);

        int returnState=0;
        if(TNode->data->value.getBorrowState()==true){
            returnState=1;
        }
        write << left << qSetFieldWidth(12) << TNode->data->value.getRecordNumber().AStringToString()
            <<  qSetFieldWidth(12) << TNode->data->value.getCustomerNum().AStringToString()
            <<  qSetFieldWidth(12) << TNode->data->value.getCustomerName().AStringToString()
            <<  qSetFieldWidth(15) << TNode->data->value.getCustomerPhone().AStringToString()
            <<  qSetFieldWidth(12) <<TNode->data->value.getBookNum().AStringToString()
            <<  qSetFieldWidth(32)<<TNode->data->value.getBookName().AStringToString()
            << qSetFieldWidth(12)<<TNode->data->value.getWriterName().AStringToString()
            << qSetFieldWidth(10)<<TNode->data->value.getBorrowTime().getDateValue().AStringToString()
            << qSetFieldWidth(10)<<TNode->data->value.getReturnTime().getDateValue().AStringToString()
            << qSetFieldWidth(10)<<returnState
           <<qSetFieldWidth(10)<<right<<TNode->data->value.getBorrowPrivilage()<< endl;


        writeBorrowRecordToFileTravese(TNode->rchild, write);
    }
}
void PrintBorrowRecordListToFile(BBSTree<BorrowRecord,int> borrowrecordlist){
    QFile writeFile("BorrowRecord.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;

    }
    QTextStream in(&writeFile);
    writeBorrowRecordToFileTravese( borrowrecordlist.getRoot(),in);

}
void CreateBuyRecordListFromeFile(BBSTree<BuyRecord,int> *buyrecordlist){
    QFile readFile("BuyRecord.txt");
        if (!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            cerr << "File could not be opened." << endl;

        }
        QTextStream out(&readFile);
        char recordNumber[12], customerNumber[12], customerName[12],customerPhone[15], bookNumber[12],bookName[32],writer[12],buyTime[10];
        int buyNumber;
        double buyPrivilage;
        double itemPrice;
        double totalPrice;

        while (!out.atEnd()){
            out >> recordNumber>> customerNumber >> customerName>>customerPhone>>  bookNumber >> bookName >> writer >> buyTime>>buyNumber>>buyPrivilage>>itemPrice>>totalPrice;


            AString Recordnum(recordNumber);

            AString CustomerNum(customerNumber);
            AString CustomerName(customerName);
            AString CustomerPhone(customerPhone);
            AString BookNumber(bookNumber);
            AString BookName(bookName);
            AString Writer(writer);
            AString BuyTime(buyTime);
            Date BuyDate(BuyTime);
            if(CustomerNum.Length()>0){
                BuyRecord buyrecord(BuyDate,buyNumber,itemPrice,buyPrivilage,Recordnum,Writer,CustomerNum,CustomerName,CustomerPhone,BookNumber,BookName);

                buyrecordlist->InsertBBSTree(buyrecord, Recordnum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< buyrecordlist->BBSTNodeNum() << " buyrecords have been inserted!" << endl;
}

void writeBuyRecordToFileTravese(BBSTNode<BuyRecord,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeBuyRecordToFileTravese(TNode->lchild, write);

        write << left << qSetFieldWidth(12) << TNode->data->value.getRecordNumber().AStringToString()
             << qSetFieldWidth(12) << TNode->data->value.getCustomerNum().AStringToString()
            << qSetFieldWidth(12) << TNode->data->value.getCustomerName().AStringToString()
            << qSetFieldWidth(15) << TNode->data->value.getCustomerPhone().AStringToString()
            << qSetFieldWidth(12) <<TNode->data->value.getBookNum().AStringToString()
            << qSetFieldWidth(32)<<TNode->data->value.getBookName().AStringToString()
            <<qSetFieldWidth(12)<<TNode->data->value.getWriterName().AStringToString()
           <<qSetFieldWidth(10)<<TNode->data->value.getBuyTime().getDateValue().AStringToString()
            <<qSetFieldWidth(10)<<TNode->data->value.getBuyNum()
            <<qSetFieldWidth(10)<< fixed <<TNode->data->value.getBuyPrivilage()
            <<qSetFieldWidth(10) << fixed <<TNode->data->value.getItemPrice()
            <<qSetFieldWidth(10)<<right<<fixed <<TNode->data->value.getTotalPrice()<<endl;

        writeBuyRecordToFileTravese(TNode->rchild, write);
    }
}
void PrintBuyRecordListToFile(BBSTree<BuyRecord,int> buyrecordlist){
    QFile writeFile("BuyRecord.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeBuyRecordToFileTravese( buyrecordlist.getRoot(), in);
    writeFile.close();
}

 BBSTree<Book,int> booklist;
 BBSTree<Customer,int> customerlist;
 BBSTree<Manager,int>  managerlist;
 BBSTree<BorrowRecord,int> borrowRecordlist;
 BBSTree<BuyRecord,int> buyrecordlist;
 int currentCustomerNumber;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_4->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);

    CreateBookTreeFromFile(&booklist);
    CreatCustomerListFromFile(&customerlist);
    CreateManagerListFromFile(&managerlist);
    CreateBorrowRecordListFromFile(&borrowRecordlist);
    CreateBuyRecordListFromeFile(&buyrecordlist);

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
            if(Cnum.Length()>0&&state==1){
                BBSTNode<Customer,int>* customerptr;
                customerptr=&customerlist.SearchBBSTree(Cnum.AStringToInt());
                currentCustomerNumber=customerptr->data->value.getNumber().AStringToInt();
                ui->lineEdit_2->setText(customerptr->data->value.getNumber().AStringToString());
                ui->lineEdit_3->setText(customerptr->data->value.getName().AStringToString());
                ui->lineEdit_4->setText(customerptr->data->value.getPassword().AStringToString());
                ui->lineEdit_5->setText(customerptr->data->value.getPhoneNumber().AStringToString());
                ui->lineEdit_6->setText(customerptr->data->value.getVip().getTypeName().AStringToString());
                customerptr->data->value.setState(0);
                //qDebug() << "Insert Successfully!" << endl;
            }

        }
        //修改过的登录状态保存到文件中
        PrintCustomerListToFile(customerlist);


    ui->tableWidget->setRowCount(booklist.BBSTNodeNum());
    ui->tableWidget->setColumnCount(8);
    Stack<BBSTNode<Book,int>*> bookStack;
    bookStack.push(booklist.getRoot());
    BBSTNode<Book,int> *bookptr;
    int bookcount=0;
    while(!bookStack.isEmpty()){
        bookStack.pop(bookptr);
       ui->tableWidget->setItem(bookcount,0,new QTableWidgetItem(bookptr->data->value.getBookNumber().AStringToString()));
       ui->tableWidget->setItem(bookcount,1,new QTableWidgetItem(bookptr->data->value.getBookName().AStringToString()));
       ui->tableWidget->setItem(bookcount,2,new QTableWidgetItem(bookptr->data->value.getWriterName().AStringToString()));
       ui->tableWidget->setItem(bookcount,3,new QTableWidgetItem(bookptr->data->value.getBookType().getType().AStringToString()));
       ui->tableWidget->setItem(bookcount,4,new QTableWidgetItem(bookptr->data->value.getBookType().getTypeName().AStringToString()));
       ui->tableWidget->setItem(bookcount,5,new QTableWidgetItem(QString::number(bookptr->data->value.getItemPrice())));
       ui->tableWidget->setItem(bookcount,6,new QTableWidgetItem(QString::number(bookptr->data->value.getCurrentNumber())));
       ui->tableWidget->setItem(bookcount,7,new QTableWidgetItem(QString::number(bookptr->data->value.getInventory())));
       bookcount++;
       if(bookptr->rchild!=NULL)
           bookStack.push(bookptr->rchild);
       if(bookptr->lchild!=NULL)
           bookStack.push(bookptr->lchild);

    }

   Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack;
   borrowrecordstack.push(borrowRecordlist.getRoot());
   BBSTNode<BorrowRecord,int> *borrowrecordptr;
   int borrowrecordcount1=0;
   int borrowrecordcount2=0;
   while(!borrowrecordstack.isEmpty()){
       borrowrecordstack.pop(borrowrecordptr);
       if(borrowrecordptr->data->value.getCustomerNum().AStringToInt()==currentCustomerNumber){
           if(borrowrecordptr->data->value.getBorrowState()){
               ui->tableWidget_2->insertRow(borrowrecordcount1);
               ui->tableWidget_2->setItem(borrowrecordcount1,0,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerNum().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,1,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerName().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,2,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerPhone().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,3,new QTableWidgetItem(QString::number(borrowrecordptr->data->value.getBorrowPrivilage())));
               ui->tableWidget_2->setItem(borrowrecordcount1,4,new QTableWidgetItem(borrowrecordptr->data->value.getBookNum().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,5,new QTableWidgetItem(borrowrecordptr->data->value.getBookName().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,6,new QTableWidgetItem(borrowrecordptr->data->value.getWriterName().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,7,new QTableWidgetItem(borrowrecordptr->data->value.getBorrowTime().getDateValue().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,8,new QTableWidgetItem(borrowrecordptr->data->value.getReturnTime().getDateValue().AStringToString()));
               ui->tableWidget_2->setItem(borrowrecordcount1,9,new QTableWidgetItem("returned"));
               ui->tableWidget_2->setItem(borrowrecordcount1,10,new QTableWidgetItem(borrowrecordptr->data->value.getRecordNumber().AStringToString()));
               borrowrecordcount1++;
           }
           else{
               ui->tableWidget_3->insertRow(borrowrecordcount2);
               ui->tableWidget_3->setItem(borrowrecordcount2,0,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerNum().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,1,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerName().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,2,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerPhone().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,3,new QTableWidgetItem(QString::number(borrowrecordptr->data->value.getBorrowPrivilage())));
               ui->tableWidget_3->setItem(borrowrecordcount2,4,new QTableWidgetItem(borrowrecordptr->data->value.getBookNum().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,5,new QTableWidgetItem(borrowrecordptr->data->value.getBookName().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,6,new QTableWidgetItem(borrowrecordptr->data->value.getWriterName().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,7,new QTableWidgetItem(borrowrecordptr->data->value.getBorrowTime().getDateValue().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,8,new QTableWidgetItem(borrowrecordptr->data->value.getReturnTime().getDateValue().AStringToString()));
               ui->tableWidget_3->setItem(borrowrecordcount2,9,new QTableWidgetItem("returning"));
               ui->tableWidget_3->setItem(borrowrecordcount2,10,new QTableWidgetItem(borrowrecordptr->data->value.getRecordNumber().AStringToString()));
               borrowrecordcount2++;
           }

       }

       if(borrowrecordptr->rchild!=NULL)
           borrowrecordstack.push(borrowrecordptr->rchild);
       if(borrowrecordptr->lchild!=NULL)
           borrowrecordstack.push(borrowrecordptr->lchild);

   }

   //ui->tableWidget_4->setRowCount(buyrecordlist.BBSTNodeNum());
   //ui->tableWidget_4->setColumnCount(12);
   Stack<BBSTNode<BuyRecord,int>*> buyrecordstack;
   buyrecordstack.push(buyrecordlist.getRoot());
   BBSTNode<BuyRecord,int> *buyrecordptr;
   int buyrecordcount=0;
   while(!buyrecordstack.isEmpty()){
       buyrecordstack.pop(buyrecordptr);
       if(buyrecordptr->data->value.getCustomerNum().AStringToInt()==currentCustomerNumber){
           ui->tableWidget_4->insertRow(buyrecordcount);
           ui->tableWidget_4->setItem(buyrecordcount,0,new QTableWidgetItem(buyrecordptr->data->value.getCustomerNum().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,1,new QTableWidgetItem(buyrecordptr->data->value.getCustomerName().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,2,new QTableWidgetItem(buyrecordptr->data->value.getCustomerPhone().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,3,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyPrivilage())));
           ui->tableWidget_4->setItem(buyrecordcount,4,new QTableWidgetItem(buyrecordptr->data->value.getBookNum().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,5,new QTableWidgetItem(buyrecordptr->data->value.getBookName().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,6,new QTableWidgetItem(buyrecordptr->data->value.getWriterName().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,7,new QTableWidgetItem(buyrecordptr->data->value.getBuyTime().getDateValue().AStringToString()));
           ui->tableWidget_4->setItem(buyrecordcount,8,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getItemPrice())));
           ui->tableWidget_4->setItem(buyrecordcount,9,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyNum())));
           ui->tableWidget_4->setItem(buyrecordcount,10,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getTotalPrice())));
           ui->tableWidget_4->setItem(buyrecordcount,11,new QTableWidgetItem(buyrecordptr->data->value.getRecordNumber().AStringToString()));
           buyrecordcount++;
       }

       if(buyrecordptr->rchild!=NULL)
           buyrecordstack.push(buyrecordptr->rchild);
       if(buyrecordptr->lchild!=NULL)
           buyrecordstack.push(buyrecordptr->lchild);
   }
}



MainWindow::~MainWindow()
{
    PrintBookTreeToFile(booklist);
    PrintBorrowRecordListToFile(borrowRecordlist);
    PrintBuyRecordListToFile(buyrecordlist);
    PrintCustomerListToFile(customerlist);
    PrintManagerListToFile(managerlist);
    delete ui;
}

void MainWindow::namechange_handle()
{
    BBSTNode<Customer,int> *customerptr_change;
    customerptr_change=&customerlist.SearchBBSTree(currentCustomerNumber);
    char * name_change;
    QByteArray name_changeArray=ui->lineEdit_3->text().toLatin1();
    name_change=name_changeArray.data();
    AString name_changeValue(name_change);
    customerptr_change->data->value.setName(name_changeValue);

}

void MainWindow::passwordchange_handle()
{
    BBSTNode<Customer,int> *customerptr_change;
    customerptr_change=&customerlist.SearchBBSTree(currentCustomerNumber);
    char * password_change;
    QByteArray password_changeArray=ui->lineEdit_4->text().toLatin1();
    password_change=password_changeArray.data();
    AString password_changeValue(password_change);
    customerptr_change->data->value.setPassword(password_changeValue);

}

void MainWindow::phonechange_handle()
{
    BBSTNode<Customer,int> *customerptr_change;
    customerptr_change=&customerlist.SearchBBSTree(currentCustomerNumber);
    char * phone_change;
    QByteArray phone_changeArray=ui->lineEdit_4->text().toLatin1();
    phone_change=phone_changeArray.data();
    AString phone_changeValue(phone_change);
    customerptr_change->data->value.setPhoneNumber(phone_changeValue);

}




void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        char * bookNum;
        QByteArray booknumberArray=ui->lineEdit->text().toLatin1();
        bookNum=booknumberArray.data();
        AString bookNumber(bookNum);
        int bookindex_number=ui->tableWidget->rowCount();

        while(bookindex_number!=0){

            ui->tableWidget->removeRow(bookindex_number-1);
            bookindex_number=ui->tableWidget->rowCount();
        }
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(8);
        BBSTNode<Book,int>* bookPtr;
        bookPtr=&booklist.SearchBBSTree(bookNumber.AStringToInt());
        if(bookPtr!=NULL){
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(bookPtr->data->value.getBookNumber().AStringToString()));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(bookPtr->data->value.getBookName().AStringToString()));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(bookPtr->data->value.getWriterName().AStringToString()));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(bookPtr->data->value.getBookType().getType().AStringToString()));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(bookPtr->data->value.getBookType().getTypeName().AStringToString()));
            ui->tableWidget->setItem(0,5,new QTableWidgetItem(QString::number(bookPtr->data->value.getItemPrice())));
            ui->tableWidget->setItem(0,6,new QTableWidgetItem(QString::number(bookPtr->data->value.getCurrentNumber())));
            ui->tableWidget->setItem(0,7,new QTableWidgetItem(QString::number(bookPtr->data->value.getInventory())));
        }else{
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }

    }
    else if(ui->radioButton_2->isChecked()){
        char* bookName_char;
        QByteArray bookName_Array=ui->lineEdit->text().toLatin1();
        bookName_char=bookName_Array.data();
        AString bookName_AString(bookName_char);
        Stack<BBSTNode<Book,int>*> bookstack_Name;
        bookstack_Name.push(booklist.getRoot());
        BBSTNode<Book,int>* bookptr_name;
        int find_name=0;
        int bookindex_name=ui->tableWidget->rowCount();

        while(bookindex_name!=0){

            ui->tableWidget->removeRow(bookindex_name-1);
            bookindex_name=ui->tableWidget->rowCount();
        }
        while(!bookstack_Name.isEmpty()){
            bookstack_Name.pop(bookptr_name);
            int nextLength_name=bookName_AString.Length();
            int* next_name=new int[nextLength_name];
            bookName_AString.getNext(next_name);
            int location_writer=bookptr_name->data->value.getBookName().Find(bookName_AString,0,next_name);
            if(location_writer!=-1){

                int rowCount_name=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount_name);
                ui->tableWidget->setItem(rowCount_name,0,new QTableWidgetItem(bookptr_name->data->value.getBookNumber().AStringToString()));
                ui->tableWidget->setItem(rowCount_name,1,new QTableWidgetItem(bookptr_name->data->value.getBookName().AStringToString()));
                ui->tableWidget->setItem(rowCount_name,2,new QTableWidgetItem(bookptr_name->data->value.getWriterName().AStringToString()));
                ui->tableWidget->setItem(rowCount_name,3,new QTableWidgetItem(bookptr_name->data->value.getBookType().getType().AStringToString()));
                ui->tableWidget->setItem(rowCount_name,4,new QTableWidgetItem(bookptr_name->data->value.getBookType().getTypeName().AStringToString()));
                ui->tableWidget->setItem(rowCount_name,5,new QTableWidgetItem(QString::number(bookptr_name->data->value.getItemPrice())));
                ui->tableWidget->setItem(rowCount_name,6,new QTableWidgetItem(QString::number(bookptr_name->data->value.getCurrentNumber())));
                ui->tableWidget->setItem(rowCount_name,7,new QTableWidgetItem(QString::number(bookptr_name->data->value.getInventory())));
                find_name++;
            }
            if(bookptr_name->rchild!=NULL)
                bookstack_Name.push(bookptr_name->rchild);
            if(bookptr_name->lchild!=NULL)
                bookstack_Name.push(bookptr_name->lchild);
        }
        if(find_name==0){

            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }

    }
    else if(ui->radioButton_3->isChecked()){
        char* writerName_char;
        QByteArray writerName_Array=ui->lineEdit->text().toLatin1();
        writerName_char=writerName_Array.data();
        AString writerName_AString(writerName_char);
        Stack<BBSTNode<Book,int>*> bookstack_writer;
        bookstack_writer.push(booklist.getRoot());
        BBSTNode<Book,int>* bookptr_writer;
        int find_writer=0;
        int bookindex_writer=ui->tableWidget->rowCount();

        while(bookindex_writer!=0){

            ui->tableWidget->removeRow(bookindex_writer-1);
            bookindex_writer=ui->tableWidget->rowCount();
        }
        while(!bookstack_writer.isEmpty()){
            bookstack_writer.pop(bookptr_writer);
            if(writerName_AString==bookptr_writer->data->value.getWriterName()){

                int rowCount_writer=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount_writer);
                ui->tableWidget->setItem(rowCount_writer,0,new QTableWidgetItem(bookptr_writer->data->value.getBookNumber().AStringToString()));
                ui->tableWidget->setItem(rowCount_writer,1,new QTableWidgetItem(bookptr_writer->data->value.getBookName().AStringToString()));
                ui->tableWidget->setItem(rowCount_writer,2,new QTableWidgetItem(bookptr_writer->data->value.getWriterName().AStringToString()));
                ui->tableWidget->setItem(rowCount_writer,3,new QTableWidgetItem(bookptr_writer->data->value.getBookType().getType().AStringToString()));
                ui->tableWidget->setItem(rowCount_writer,4,new QTableWidgetItem(bookptr_writer->data->value.getBookType().getTypeName().AStringToString()));
                ui->tableWidget->setItem(rowCount_writer,5,new QTableWidgetItem(QString::number(bookptr_writer->data->value.getItemPrice())));
                ui->tableWidget->setItem(rowCount_writer,6,new QTableWidgetItem(QString::number(bookptr_writer->data->value.getCurrentNumber())));
                ui->tableWidget->setItem(rowCount_writer,7,new QTableWidgetItem(QString::number(bookptr_writer->data->value.getInventory())));
                find_writer++;
            }
            if(bookptr_writer->rchild!=NULL)
                bookstack_writer.push(bookptr_writer->rchild);
            if(bookptr_writer->lchild!=NULL)
                bookstack_writer.push(bookptr_writer->lchild);
        }
        if(find_writer==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::warning(this,tr("Error!"),tr("Choose a way first!"),QMessageBox::Yes);
    }
}

void MainWindow::bookselection_handle()
{   //buy book
    if(ui->tableWidget->selectedItems().size()>0){
        int currentRow;
        currentRow=ui->tableWidget->currentRow();
        char* bNum_buy;
        QByteArray bNum_buyArray=ui->tableWidget->item(currentRow,0)->text().toLatin1();
        bNum_buy=bNum_buyArray.data();
        AString bookNumber(bNum_buy);
        BBSTNode<Book,int>* currentbookptr_buy;
        currentbookptr_buy=&booklist.SearchBBSTree(bookNumber.AStringToInt());
        if(currentbookptr_buy->data->value.getCurrentNumber()>0&&currentbookptr_buy->data->value.getInventory()>0){
            if(!ui->lineEdit_7->text().isEmpty()){

                int buynum_buy=ui->lineEdit_7->text().toInt();

                char* bname_buy;
                QByteArray bname_buyArray=ui->tableWidget->item(currentRow,1)->text().toLatin1();
                bname_buy=bname_buyArray.data();
                AString bookName_buy(bname_buy);
                char* writer_buy;
                QByteArray writer_buyArray=ui->tableWidget->item(currentRow,2)->text().toLatin1();
                writer_buy=writer_buyArray.data();
                AString writerofBook_buy(writer_buy);
                int recordnum_buy;
                if(buyrecordlist.BBSTNodeNum()==0){
                    recordnum_buy=1;
                }
                else{
                    recordnum_buy=buyrecordlist.getRoot()->data->value.getRecordNumber().AStringToInt();
                    Stack<BBSTNode<BuyRecord,int>*> buyrecordstack;
                    buyrecordstack.push(buyrecordlist.getRoot());
                    BBSTNode<BuyRecord,int>* buyrecordptr_customer;
                    while(!buyrecordstack.isEmpty()){
                        buyrecordstack.pop(buyrecordptr_customer);
                        if(buyrecordptr_customer->data->value.getRecordNumber().AStringToInt()>recordnum_buy)
                            recordnum_buy=buyrecordptr_customer->data->value.getRecordNumber().AStringToInt();
                        if(buyrecordptr_customer->rchild!=NULL)
                            buyrecordstack.push(buyrecordptr_customer->rchild);
                        if(buyrecordptr_customer->lchild!=NULL)
                            buyrecordstack.push(buyrecordptr_customer->lchild);
                    }
                    recordnum_buy++;
                }
                //int recordnum_buy=buyrecordlist.BBSTNodeNum()+1;
                char recordnum_buy_buf[10];
                itoa(recordnum_buy,recordnum_buy_buf,10);
                AString recordNumber(recordnum_buy_buf);
                AString customernum_buy=customerlist.SearchBBSTree(currentCustomerNumber).data->value.getNumber();
                AString customername_buy=customerlist.SearchBBSTree(currentCustomerNumber).data->value.getName();
                AString customerphonr_buy=customerlist.SearchBBSTree(currentCustomerNumber).data->value.getPhoneNumber();
                Date date_buy;
                double buyprivilage=customerlist.SearchBBSTree(currentCustomerNumber).data->value.getVip().getBuyPrivilage();

                double itemprice_book=ui->tableWidget->item(currentRow,5)->text().toDouble();
                BuyRecord buyrecord(date_buy,buynum_buy,itemprice_book,buyprivilage, recordNumber,writerofBook_buy,customernum_buy,customername_buy,customerphonr_buy,bookNumber,bookName_buy);
                if( buyrecordlist.InsertBBSTree(buyrecord,recordNumber.AStringToInt())){
                    QMessageBox::warning(this,tr("Thanks"),tr("Buy Successfully!"),QMessageBox::Yes);
                    buyrecordlist.InsertBBSTree(buyrecord,recordNumber.AStringToInt());
                    int currentnum_currentbook=currentbookptr_buy->data->value.getCurrentNumber();
                    int currentinventory_currentbook=currentbookptr_buy->data->value.getInventory();
                    currentbookptr_buy->data->value.setCurrentNumber(currentnum_currentbook-1);
                    currentbookptr_buy->data->value.setInventory(currentinventory_currentbook-1);
                    ui->tableWidget->setItem(currentRow,6,new QTableWidgetItem(QString::number(currentbookptr_buy->data->value.getCurrentNumber())));
                    ui->tableWidget->setItem(currentRow,7,new QTableWidgetItem(QString::number(currentbookptr_buy->data->value.getInventory())));
                    int rowcount_buyrecord=ui->tableWidget_4->rowCount();
                    ui->tableWidget_4->insertRow(rowcount_buyrecord);
                    ui->tableWidget_4->setItem(rowcount_buyrecord,0,new QTableWidgetItem(customernum_buy.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,1,new QTableWidgetItem(customername_buy.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,2,new QTableWidgetItem(customerphonr_buy.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,3,new QTableWidgetItem(QString::number(buyprivilage)));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,4,new QTableWidgetItem(bookNumber.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,5,new QTableWidgetItem(bookName_buy.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,6,new QTableWidgetItem(writerofBook_buy.AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,7,new QTableWidgetItem(date_buy.getDateValue().AStringToString()));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,8,new QTableWidgetItem(QString::number(itemprice_book)));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,9,new QTableWidgetItem(QString::number(buynum_buy)));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,10,new QTableWidgetItem(QString::number(buyrecord.getTotalPrice())));
                    ui->tableWidget_4->setItem(rowcount_buyrecord,11,new QTableWidgetItem(recordNumber.AStringToString()));
                    //将购买记录写入文件
                    PrintBuyRecordListToFile(buyrecordlist);
                    PrintBookTreeToFile(booklist);

                }
                else{
                     QMessageBox::warning(this,tr("Error!"),tr("RecordNumber existed!"),QMessageBox::Yes);
                }

            }
            else{
                QMessageBox::warning(this,tr("Error!"),tr("Input number to buy first!"),QMessageBox::Yes);
            }
        }
        else{
            QMessageBox::warning(this,tr("Error!"),tr("No books!"),QMessageBox::Yes);
        }
    }
    disconnect(ui->tableWidget,SIGNAL(itemSelectionChanged()),this,SLOT(bookselection_handle()));
}

/*void MainWindow::saveAllFiles()
{
    PrintBookTreeToFile(booklist);
    PrintBorrowRecordListToFile(borrowRecordlist);
    PrintBuyRecordListToFile(buyrecordlist);
    PrintCustomerListToFile(customerlist);
    PrintManagerListToFile(managerlist);
}
void MainWindow::closeEvent(QCloseEvent *event){
    saveAllFiles();
}*/

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(booklist.BBSTNodeNum());
    ui->tableWidget->setColumnCount(8);
    Stack<BBSTNode<Book,int>*> bookStack;
    bookStack.push(booklist.getRoot());
    BBSTNode<Book,int> *bookptr;
    int bookcount=0;
    while(!bookStack.isEmpty()){
        bookStack.pop(bookptr);
       ui->tableWidget->setItem(bookcount,0,new QTableWidgetItem(bookptr->data->value.getBookNumber().AStringToString()));
       ui->tableWidget->setItem(bookcount,1,new QTableWidgetItem(bookptr->data->value.getBookName().AStringToString()));
       ui->tableWidget->setItem(bookcount,2,new QTableWidgetItem(bookptr->data->value.getWriterName().AStringToString()));
       ui->tableWidget->setItem(bookcount,3,new QTableWidgetItem(bookptr->data->value.getBookType().getType().AStringToString()));
       ui->tableWidget->setItem(bookcount,4,new QTableWidgetItem(bookptr->data->value.getBookType().getTypeName().AStringToString()));
       ui->tableWidget->setItem(bookcount,5,new QTableWidgetItem(QString::number(bookptr->data->value.getItemPrice())));
       ui->tableWidget->setItem(bookcount,6,new QTableWidgetItem(QString::number(bookptr->data->value.getCurrentNumber())));
       ui->tableWidget->setItem(bookcount,7,new QTableWidgetItem(QString::number(bookptr->data->value.getInventory())));
       bookcount++;
       if(bookptr->rchild!=NULL)
           bookStack.push(bookptr->rchild);
       if(bookptr->lchild!=NULL)
           bookStack.push(bookptr->lchild);

    }
}

void MainWindow::on_pushButton_5_clicked()
{


    emit ui->lineEdit_3->textEdited(QString());
    emit ui->lineEdit_4->textEdited(QString());
    emit ui->lineEdit_5->textEdited(QString());
    connect(ui->lineEdit_3,SIGNAL(textEdited(QString)),this,SLOT(namechange_handle()));
    connect(ui->lineEdit_4,SIGNAL(textEdited(QString)),this,SLOT(passwordchange_handle()));
    connect(ui->lineEdit_5,SIGNAL(textEdited(QString)),this,SLOT(phonechange_handle()));
    PrintCustomerListToFile(customerlist);
    QMessageBox::warning(this,tr("Be sure to your change!"),tr("Have changed!"),QMessageBox::Yes);
}

void MainWindow::on_pushButton_3_clicked()
{
    //emit ui->tableWidget->itemSelectionChanged();
    //connect(ui->tableWidget,SIGNAL(itemSelectionChanged()),this,SLOT(bookselection_handle()));
    bookselection_handle();
}

void MainWindow::on_pushButton_6_clicked()
{
    //borrow books
    if(ui->tableWidget->selectedItems().size()>0){
        int currentRow_borrow;
        currentRow_borrow=ui->tableWidget->currentRow();
        char* bNum_borrow;
        QByteArray bNum_borrowArray=ui->tableWidget->item( currentRow_borrow,0)->text().toLatin1();
        bNum_borrow=bNum_borrowArray.data();
        AString bookNumber(bNum_borrow);
        BBSTNode<Book,int>* currentbookptr_borrow;
        currentbookptr_borrow=&booklist.SearchBBSTree(bookNumber.AStringToInt());
        BBSTNode<Customer,int>* currentcustomerptr_borrow;
         currentcustomerptr_borrow=&customerlist.SearchBBSTree(currentCustomerNumber);
        if(currentbookptr_borrow->data->value.getCurrentNumber()>0){

            int recordNum;
            if(borrowRecordlist.BBSTNodeNum()==0){
                recordNum=1;
            }
            else{
                recordNum=borrowRecordlist.getRoot()->data->value.getRecordNumber().AStringToInt();
                Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack;
                borrowrecordstack.push(borrowRecordlist.getRoot());
                BBSTNode<BorrowRecord,int>* borrowrecordptr;
                while(!borrowrecordstack.isEmpty()){
                    borrowrecordstack.pop(borrowrecordptr);
                    if(borrowrecordptr->data->value.getRecordNumber().AStringToInt()>=recordNum)
                        recordNum=borrowrecordptr->data->value.getRecordNumber().AStringToInt();
                    if(borrowrecordptr->rchild!=NULL)
                        borrowrecordstack.push(borrowrecordptr->rchild);
                    if(borrowrecordptr->lchild!=NULL)
                        borrowrecordstack.push(borrowrecordptr->lchild);
                }
                recordNum++;
            }
            char recordNum_char[10];
            itoa(recordNum,recordNum_char,10);
            AString recordNumber_borrow(recordNum_char);
            AString customerNum_borrow=currentcustomerptr_borrow->data->value.getNumber();
            AString customerName_borrow=currentcustomerptr_borrow->data->value.getName();
            AString customerPhone_borrow=currentcustomerptr_borrow->data->value.getPhoneNumber();
            int borrowprivilage_borrow=currentcustomerptr_borrow->data->value.getVip().getBorrowPrivilage();
            AString bookNum_borrow=currentbookptr_borrow->data->value.getBookNumber();
            AString bookName_borrow=currentbookptr_borrow->data->value.getBookName();
            AString bookWriter_borrow=currentbookptr_borrow->data->value.getWriterName();
            bool returnState_borrow=false;
            Date date_borrow;
            BorrowRecord borrowrecord_borrow(date_borrow, recordNumber_borrow, customerNum_borrow, customerName_borrow,customerPhone_borrow, bookNum_borrow,bookName_borrow, bookWriter_borrow,borrowprivilage_borrow,returnState_borrow);
            if(borrowRecordlist.InsertBBSTree(borrowrecord_borrow,recordNumber_borrow.AStringToInt())){
                QMessageBox::warning(this,tr("Thanks"),tr("Borrow Successfully!"),QMessageBox::Yes);
                int currentNum_borrow=currentbookptr_borrow->data->value.getCurrentNumber();
                currentbookptr_borrow->data->value.setCurrentNumber(currentNum_borrow-1);
                int currentinventory_borrow=currentbookptr_borrow->data->value.getInventory();
                currentbookptr_borrow->data->value.setInventory(currentinventory_borrow);
                ui->tableWidget->setItem(currentRow_borrow,6,new QTableWidgetItem(QString::number(currentbookptr_borrow->data->value.getCurrentNumber())));
                ui->tableWidget->setItem(currentRow_borrow,7,new QTableWidgetItem(QString::number(currentbookptr_borrow->data->value.getInventory())));
                int rowcount_borrowrecord=ui->tableWidget_3->rowCount();
                ui->tableWidget_3->insertRow(rowcount_borrowrecord);
                ui->tableWidget_3->setItem(rowcount_borrowrecord,0,new QTableWidgetItem(borrowrecord_borrow.getCustomerNum().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,1,new QTableWidgetItem(borrowrecord_borrow.getCustomerName().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,2,new QTableWidgetItem(borrowrecord_borrow.getCustomerPhone().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,3,new QTableWidgetItem(QString::number(borrowrecord_borrow.getBorrowPrivilage())));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,4,new QTableWidgetItem(borrowrecord_borrow.getBookNum().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,5,new QTableWidgetItem(borrowrecord_borrow.getBookName().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,6,new QTableWidgetItem(borrowrecord_borrow.getWriterName().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,7,new QTableWidgetItem(borrowrecord_borrow.getBorrowTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,8,new QTableWidgetItem(borrowrecord_borrow.getReturnTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,9,new QTableWidgetItem("returning"));
                ui->tableWidget_3->setItem(rowcount_borrowrecord,10,new QTableWidgetItem(recordNumber_borrow.AStringToString()));
                //write record to file;
                PrintBookTreeToFile(booklist);
                PrintBorrowRecordListToFile(borrowRecordlist);

            }
            else{
                QMessageBox::warning(this,tr("Error!"),tr("RecordNumber existed!"),QMessageBox::Yes);
            }
        }
        else{
            QMessageBox::warning(this,tr("Sorry!"),tr("No books can borrow!"),QMessageBox::Yes);
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int currentRow_returning=ui->tableWidget_3->currentRow();

    Date date_returned;
    int rowCount_borrow_returned=ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(rowCount_borrow_returned);
    int recordNumber_retruned=ui->tableWidget_3->item(currentRow_returning,10)->text().toInt();
    borrowRecordlist.SearchBBSTree(recordNumber_retruned).data->value.setBorrowState(true);
    BBSTNode<BorrowRecord,int>* currentborrowrecordptr;
    currentborrowrecordptr=&borrowRecordlist.SearchBBSTree(recordNumber_retruned);
    AString bookNum_returned=currentborrowrecordptr->data->value.getBookNum();
    BBSTNode<Book,int>* currentbookptr_returned;
    currentbookptr_returned=&booklist.SearchBBSTree(bookNum_returned.AStringToInt());
    int currentnum_returned=currentbookptr_returned->data->value.getCurrentNumber();
    currentbookptr_returned->data->value.setCurrentNumber(currentnum_returned+1);
    //on_pushButton_2_clicked();
    int rowCountOfTheBook_returned;
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        char * bookNum_booktable;
        QByteArray bookNum_booktableArray=ui->tableWidget->item(i,0)->text().toLatin1();
        bookNum_booktable=bookNum_booktableArray.data();
        AString bookNum_booktable_target(bookNum_booktable);
        if(bookNum_booktable_target==bookNum_returned){
            rowCountOfTheBook_returned=i;
            break;
        }
    }
    ui->tableWidget->setItem(rowCountOfTheBook_returned,6,new QTableWidgetItem(QString::number(currentbookptr_returned->data->value.getCurrentNumber())));

    ui->tableWidget_2->setItem(rowCount_borrow_returned,0,new QTableWidgetItem(currentborrowrecordptr->data->value.getCustomerNum().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,1,new QTableWidgetItem(currentborrowrecordptr->data->value.getCustomerName().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,2,new QTableWidgetItem(currentborrowrecordptr->data->value.getCustomerPhone().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,3,new QTableWidgetItem(QString::number(currentborrowrecordptr->data->value.getBorrowPrivilage())));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,4,new QTableWidgetItem(currentborrowrecordptr->data->value.getBookNum().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,5,new QTableWidgetItem(currentborrowrecordptr->data->value.getBookName().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,6,new QTableWidgetItem(currentborrowrecordptr->data->value.getWriterName().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,7,new QTableWidgetItem(currentborrowrecordptr->data->value.getBorrowTime().getDateValue().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,8,new QTableWidgetItem(date_returned.getDateValue().AStringToString()));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,9,new QTableWidgetItem("returned"));
    ui->tableWidget_2->setItem(rowCount_borrow_returned,10,new QTableWidgetItem(currentborrowrecordptr->data->value.getRecordNumber().AStringToString()));

    ui->tableWidget_3->removeRow(currentRow_returning);
    //write records to files
    PrintBookTreeToFile(booklist);
    PrintBorrowRecordListToFile(borrowRecordlist);
}
