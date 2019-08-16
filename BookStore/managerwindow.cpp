#include "managerwindow.h"
#include "ui_managerwindow.h"
#include"stack.h"
#include<QFile>
#include<QDebug>
#include"BBSTree.h"
#include"BBSTree.cpp"
#include"Book.h"
//#include"Book.cpp"
#include"Customer.h"
#include"Manager.h"
#include"BorrowRecord.h"
#include"BuyRecord.h"
#include"Date.h"
#include<QMessageBox>

void CreateBookTreeFromFileInManager(BBSTree<Book, int> *booklist){
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
            if(bnum.Length()>0){
                Book book(booktype, bnum, bname, wname, currentNumber, inventory, itemPrice);
                booklist->InsertBBSTree(book, bnum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< booklist->BBSTNodeNum() << " books have been inserted!" << endl;
}
void writeBookToFileTraveseInManager(BBSTNode<Book, int> *TNode,QTextStream & write){
    if (TNode != NULL){
        writeBookToFileTraveseInManager(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getBookNumber().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getBookName().AStringToString()
            << qSetFieldWidth(5) << TNode->data->value.getBookType().getType().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getBookType().getTypeName().AStringToString()
            << qSetFieldWidth(32) << TNode->data->value.getWriterName().AStringToString()
            << qSetFieldWidth(10) << TNode->data->value.getCurrentNumber()
            << qSetFieldWidth(10) << TNode->data->value.getInventory()
            << qSetFieldWidth(10) << right << fixed << TNode->data->value.getItemPrice() << endl;
        writeBookToFileTraveseInManager(TNode->rchild, write);
    }
}
void PrintBookTreeToFileInManager(BBSTree<Book, int> booklist){
    QFile writeFile("Book.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeBookToFileTraveseInManager(booklist.getRoot(), in);


}
void CreatCustomerListFromFileInManager(BBSTree<Customer,int> *customerlsit){
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

void writeCustomerToFileTraveseInManager(BBSTNode<Customer,int> *TNode,QTextStream &write){
    if (TNode != NULL){
       writeCustomerToFileTraveseInManager(TNode->lchild, write);

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
        writeCustomerToFileTraveseInManager(TNode->rchild, write);
    }
}
void PrintCustomerListToFileInManager(BBSTree<Customer,int> customerlist){
    QFile writeFile("Customer.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeCustomerToFileTraveseInManager(customerlist.getRoot(), in);

}
void CreateManagerListFromFileInManager(BBSTree<Manager,int> * managerlist){
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
                qDebug()<<manager.getState()<<endl;
                //qDebug()<<managerlistinmanager.SearchBBSTree(Mnum.AStringToInt()).data->value.getState()<<endl;
            }

        }

       qDebug()<<managerlist->BBSTNodeNum() << " managers have been inserted!" << endl;
}

void writeManagerToFileTraveseInManager(BBSTNode<Manager,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeManagerToFileTraveseInManager(TNode->lchild, write);

        write << left << qSetFieldWidth(15) << TNode->data->value.getNumber().AStringToString()
            <<qSetFieldWidth(32) << TNode->data->value.getName().AStringToString()
            << qSetFieldWidth(20) << TNode->data->value.getPassword().AStringToString()
            << qSetFieldWidth(15) << TNode->data->value.getPhoneNumber().AStringToString()
            << qSetFieldWidth(12) << TNode->data->value.getType().AStringToString()
            <<qSetFieldWidth(5)<<right<<TNode->data->value.getState()
            << endl;
        qDebug()<<TNode->data->value.getState()<<endl;

        writeManagerToFileTraveseInManager(TNode->rchild, write);
    }
}
void PrintManagerListToFileInManager(BBSTree<Manager,int> managerlist){
    QFile writeFile("Manager.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeManagerToFileTraveseInManager( managerlist.getRoot(), in);

}
void CreateBorrowRecordListFromFileInManager(BBSTree<BorrowRecord,int> *borrowrecordlist){
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
            if(borrowSate == 1){
                returnstate=true;
            }
            if(RecordNum.Length()>0){

                BorrowRecord borrowrecord(BorrowDate, RecordNum,CustomerNum, CustomerName, CustomerPhone,BookNumber,BookName,Writer,borrowPrivilage,returnstate);
                if(borrowrecord.getBorrowState()){
                    qDebug()<<borrowrecord.getRecordNumber().AStringToInt()<<endl;
                    qDebug()<<"true!"<<endl;
                }
                borrowrecordlist->InsertBBSTree(borrowrecord, RecordNum.AStringToInt());
                qDebug() << "Insert Successfully!" << endl;
            }

        }

       qDebug()<< borrowrecordlist->BBSTNodeNum() << " borrowrecords have been inserted!" << endl;
}

void writeBorrowRecordToFileTraveseInManager(BBSTNode<BorrowRecord,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeBorrowRecordToFileTraveseInManager(TNode->lchild, write);

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


        writeBorrowRecordToFileTraveseInManager(TNode->rchild, write);
    }
}
void PrintBorrowRecordListToFileInManager(BBSTree<BorrowRecord,int> borrowrecordlist){
    QFile writeFile("BorrowRecord.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;

    }
    QTextStream in(&writeFile);
    writeBorrowRecordToFileTraveseInManager( borrowrecordlist.getRoot(),in);

}
void CreateBuyRecordListFromeFileInManager(BBSTree<BuyRecord,int> *buyrecordlist){
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

void writeBuyRecordToFileTraveseInManager(BBSTNode<BuyRecord,int> *TNode,QTextStream& write){
    if (TNode != NULL){
        writeBuyRecordToFileTraveseInManager(TNode->lchild, write);

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

        writeBuyRecordToFileTraveseInManager(TNode->rchild, write);
    }
}
void PrintBuyRecordListToFileInManager(BBSTree<BuyRecord,int> buyrecordlist){
    QFile writeFile("BuyRecord.txt");
    if (!writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    QTextStream in(&writeFile);
    writeBuyRecordToFileTraveseInManager( buyrecordlist.getRoot(), in);
    writeFile.close();
}


 BBSTree<Book,int> booklistinmanager;
 BBSTree<Customer,int> customerlistinmanager;
 static BBSTree<Manager,int>  managerlistinmanager;
 BBSTree<BorrowRecord,int> borrowRecordlistinmanager;
 BBSTree<BuyRecord,int> buyrecordlistinmanager;
 int currentManagerNumber;
 struct buyNode{
     int bookNum;
     int sellNum;
 };
 struct borrowNode{
     int bookNum;
     int borrowNum;
 };


 ManagerWindow::ManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerWindow)
{
    ui->setupUi(this);
    CreatCustomerListFromFileInManager(&customerlistinmanager);
    CreateBookTreeFromFileInManager(&booklistinmanager);;
    CreateBorrowRecordListFromFileInManager(&borrowRecordlistinmanager);
    CreateBuyRecordListFromeFileInManager(&buyrecordlistinmanager);
    CreateManagerListFromFileInManager(&managerlistinmanager);

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
    ui->tableWidget_5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_5->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_6->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_6->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_7->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_7->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_8->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_8->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_8->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->tableWidget->setRowCount(booklistinmanager.BBSTNodeNum());
    ui->tableWidget->setColumnCount(8);
    Stack<BBSTNode<Book,int>*> bookStack;
    bookStack.push(booklistinmanager.getRoot());
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
       if(bookptr->rchild!=NULL)
           bookStack.push(bookptr->rchild);
       if(bookptr->lchild!=NULL)
           bookStack.push(bookptr->lchild);
       bookcount++;
    }
     ui->tableWidget_2->setRowCount(borrowRecordlistinmanager.BBSTNodeNum());
     ui->tableWidget_2->setColumnCount(11);
     Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack;
     borrowrecordstack.push(borrowRecordlistinmanager.getRoot());
     BBSTNode<BorrowRecord,int> *borrowrecordptr;
     int borrowrecordcount1=0;
     while(!borrowrecordstack.isEmpty()){
         borrowrecordstack.pop(borrowrecordptr);
         ui->tableWidget_2->setItem(borrowrecordcount1,0,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerNum().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,1,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerName().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,2,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerPhone().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,3,new QTableWidgetItem(QString::number(borrowrecordptr->data->value.getBorrowPrivilage())));
         ui->tableWidget_2->setItem(borrowrecordcount1,4,new QTableWidgetItem(borrowrecordptr->data->value.getBookNum().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,5,new QTableWidgetItem(borrowrecordptr->data->value.getBookName().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,6,new QTableWidgetItem(borrowrecordptr->data->value.getWriterName().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,7,new QTableWidgetItem(borrowrecordptr->data->value.getBorrowTime().getDateValue().AStringToString()));
         ui->tableWidget_2->setItem(borrowrecordcount1,8,new QTableWidgetItem(borrowrecordptr->data->value.getReturnTime().getDateValue().AStringToString()));
         if(borrowrecordptr->data->value.getBorrowState()){
             ui->tableWidget_2->setItem(borrowrecordcount1,9,new QTableWidgetItem("returned"));
         }
         else{
              ui->tableWidget_2->setItem(borrowrecordcount1,9,new QTableWidgetItem("returnning"));
         }

         ui->tableWidget_2->setItem(borrowrecordcount1,10,new QTableWidgetItem(borrowrecordptr->data->value.getRecordNumber().AStringToString()));
         borrowrecordcount1++;

         if(borrowrecordptr->rchild!=NULL)
             borrowrecordstack.push(borrowrecordptr->rchild);
         if(borrowrecordptr->lchild!=NULL)
             borrowrecordstack.push(borrowrecordptr->lchild);

     }
    ui->tableWidget_3->setRowCount(buyrecordlistinmanager.BBSTNodeNum());
    ui->tableWidget_3->setColumnCount(12);
    Stack<BBSTNode<BuyRecord,int>*> buyrecordstack;
    buyrecordstack.push(buyrecordlistinmanager.getRoot());
    BBSTNode<BuyRecord,int> *buyrecordptr;
    int buyrecordcount=0;
    while(!buyrecordstack.isEmpty()){
        buyrecordstack.pop(buyrecordptr);
        ui->tableWidget_3->setItem(buyrecordcount,0,new QTableWidgetItem(buyrecordptr->data->value.getCustomerNum().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,1,new QTableWidgetItem(buyrecordptr->data->value.getCustomerName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,2,new QTableWidgetItem(buyrecordptr->data->value.getCustomerPhone().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,3,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyPrivilage())));
        ui->tableWidget_3->setItem(buyrecordcount,4,new QTableWidgetItem(buyrecordptr->data->value.getBookNum().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,5,new QTableWidgetItem(buyrecordptr->data->value.getBookName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,6,new QTableWidgetItem(buyrecordptr->data->value.getWriterName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,7,new QTableWidgetItem(buyrecordptr->data->value.getBuyTime().getDateValue().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,8,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getItemPrice())));
        ui->tableWidget_3->setItem(buyrecordcount,9,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyNum())));
        ui->tableWidget_3->setItem(buyrecordcount,10,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getTotalPrice())));
        ui->tableWidget_3->setItem(buyrecordcount,11,new QTableWidgetItem(buyrecordptr->data->value.getRecordNumber().AStringToString()));
        buyrecordcount++;
        if(buyrecordptr->rchild!=NULL)
            buyrecordstack.push(buyrecordptr->rchild);
        if(buyrecordptr->lchild!=NULL)
            buyrecordstack.push(buyrecordptr->lchild);
    }
    ui->tableWidget_4->setRowCount(customerlistinmanager.BBSTNodeNum());
    ui->tableWidget_4->setColumnCount(6);
    Stack<BBSTNode<Customer,int>*> customerstack;
    customerstack.push(customerlistinmanager.getRoot());
    BBSTNode<Customer,int>* customerptr;
    int customercount=0;
    while(!customerstack.isEmpty()){
        customerstack.pop(customerptr);
        ui->tableWidget_4->setItem(customercount,0,new QTableWidgetItem(customerptr->data->value.getNumber().AStringToString()));
        ui->tableWidget_4->setItem(customercount,1,new QTableWidgetItem(customerptr->data->value.getName().AStringToString()));
        ui->tableWidget_4->setItem(customercount,2,new QTableWidgetItem(customerptr->data->value.getPhoneNumber().AStringToString()));
        ui->tableWidget_4->setItem(customercount,3,new QTableWidgetItem(customerptr->data->value.getVip().getType().AStringToString()));
        ui->tableWidget_4->setItem(customercount,4,new QTableWidgetItem(customerptr->data->value.getVip().getTypeName().AStringToString()));
        ui->tableWidget_4->setItem(customercount,5,new QTableWidgetItem(QString::number(customerptr->data->value.getVip().getMoney())));
        customercount++;
        if(customerptr->rchild!=NULL)
            customerstack.push(customerptr->rchild);
        if(customerptr->lchild!=NULL)
            customerstack.push(customerptr->lchild);
    }
    ui->tableWidget_5->setRowCount(4);
    ui->tableWidget_5->setColumnCount(5);
    ui->tableWidget_5->setItem(0,0, new QTableWidgetItem("0"));
    ui->tableWidget_5->setItem(0,1, new QTableWidgetItem("Vip0"));
    ui->tableWidget_5->setItem(0,2, new QTableWidgetItem(QString::number(0)));
    ui->tableWidget_5->setItem(0,3, new QTableWidgetItem(QString::number(0.98)));
    ui->tableWidget_5->setItem(0,4, new QTableWidgetItem(QString::number(0.0)));
    ui->tableWidget_5->setItem(1,0, new QTableWidgetItem("1"));
    ui->tableWidget_5->setItem(1,1, new QTableWidgetItem("Vip1"));
    ui->tableWidget_5->setItem(1,2, new QTableWidgetItem(QString::number(15)));
    ui->tableWidget_5->setItem(1,3, new QTableWidgetItem(QString::number(0.95)));
    ui->tableWidget_5->setItem(1,4, new QTableWidgetItem(QString::number(50.00)));
    ui->tableWidget_5->setItem(2,0, new QTableWidgetItem("2"));
    ui->tableWidget_5->setItem(2,1, new QTableWidgetItem("Vip2"));
    ui->tableWidget_5->setItem(2,2, new QTableWidgetItem(QString::number(25)));
    ui->tableWidget_5->setItem(2,3, new QTableWidgetItem(QString::number(0.90)));
    ui->tableWidget_5->setItem(2,4, new QTableWidgetItem(QString::number(100.00)));
    ui->tableWidget_5->setItem(3,0, new QTableWidgetItem("3"));
    ui->tableWidget_5->setItem(3,1, new QTableWidgetItem("Vip3"));
    ui->tableWidget_5->setItem(3,2, new QTableWidgetItem(QString::number(30)));
    ui->tableWidget_5->setItem(3,3, new QTableWidgetItem(QString::number(0.85)));
    ui->tableWidget_5->setItem(3,4, new QTableWidgetItem(QString::number(150.00)));


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
            if(Mnum.Length()>0&&state==1){
                BBSTNode<Manager,int>* managerptr;
                managerptr=&managerlistinmanager.SearchBBSTree(Mnum.AStringToInt());
                managerptr->data->value.setState(0);
                ui->lineEdit_5->setText( managerptr->data->value.getNumber().AStringToString());
                ui->lineEdit_6->setText( managerptr->data->value.getName().AStringToString());
                ui->lineEdit_7->setText( managerptr->data->value.getPassword().AStringToString());
                ui->lineEdit_8->setText(tr("manager"));
            }
        }
       //write the customer record to the file;
        PrintManagerListToFileInManager(managerlistinmanager);


        //analysisOfBuyrecord();
        buyNode buyNodelist[booklistinmanager.BBSTNodeNum()];
        Stack<BBSTNode<Book,int>*> bookstack_analysis;
        bookstack_analysis.push(booklistinmanager.getRoot());
        int index=0;
        BBSTNode<Book,int>* bookptr_analysis;
        while(!bookstack_analysis.isEmpty()){
            bookstack_analysis.pop(bookptr_analysis);
            buyNodelist[index].bookNum=bookptr_analysis->data->value.getBookNumber().AStringToInt();
            buyNodelist[index].sellNum=0;
            index++;
            if(bookptr_analysis->rchild!=NULL)
                bookstack_analysis.push(bookptr_analysis->rchild);
            if(bookptr_analysis->lchild!=NULL)
                bookstack_analysis.push(bookptr_analysis->lchild);
        }
        Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_analysis;
        buyrecordstack_analysis.push(buyrecordlistinmanager.getRoot());
        BBSTNode<BuyRecord,int>* buyrecordptr_analysis;
        while(!buyrecordstack_analysis.isEmpty()){
            buyrecordstack_analysis.pop(buyrecordptr_analysis);
            int currentBookNumber=buyrecordptr_analysis->data->value.getBookNum().AStringToInt();
            for(int j=0;j<booklistinmanager.BBSTNodeNum();j++){
                if(buyNodelist[j].bookNum==currentBookNumber){
                    buyNodelist[j].sellNum+=buyrecordptr_analysis->data->value.getBuyNum();
                }
            }
            if(buyrecordptr_analysis->rchild!=NULL)
                buyrecordstack_analysis.push(buyrecordptr_analysis->rchild);
            if(buyrecordptr_analysis->lchild!=NULL)
                buyrecordstack_analysis.push(buyrecordptr_analysis->lchild);
        }
        for(int i=0;i<booklistinmanager.BBSTNodeNum()-1;i++){
            int min_index=i;
            for(int j=i+1;j<booklistinmanager.BBSTNodeNum();j++){
                if(buyNodelist[j].sellNum<buyNodelist[min_index].sellNum){
                    min_index=j;
                }
            }
            if(i!=min_index){
                buyNode tempNode=buyNodelist[i];
                buyNodelist[i]=buyNodelist[min_index];
                buyNodelist[min_index]=tempNode;
            }
        }
        for(int k=booklistinmanager.BBSTNodeNum()-1,p=0;k>=0;k--,p++){
            int bnum=buyNodelist[k].bookNum;
            ui->tableWidget_7->insertRow(p);
            ui->tableWidget_7->setItem(p,0,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookNumber().AStringToString()));
            ui->tableWidget_7->setItem(p,1,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookName().AStringToString()));
            ui->tableWidget_7->setItem(p,2,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getWriterName().AStringToString()));
            ui->tableWidget_7->setItem(p,3,new QTableWidgetItem(QString::number(buyNodelist[k].sellNum)));

        }

        //analysis of the borrowRecord;
        borrowNode borrowNodelist[booklistinmanager.BBSTNodeNum()];
        Stack<BBSTNode<Book,int>*> bookstack_analysis_borrow;
        bookstack_analysis_borrow.push(booklistinmanager.getRoot());
        int index_borrow=0;
        BBSTNode<Book,int>* bookptr_analysis_borrow;
        while(!bookstack_analysis_borrow.isEmpty()){
            bookstack_analysis_borrow.pop(bookptr_analysis_borrow);
            borrowNodelist[index_borrow].bookNum=bookptr_analysis_borrow->data->value.getBookNumber().AStringToInt();
            borrowNodelist[index_borrow].borrowNum=0;
            index_borrow++;
            if(bookptr_analysis_borrow->rchild!=NULL)
                bookstack_analysis_borrow.push(bookptr_analysis_borrow->rchild);
            if(bookptr_analysis_borrow->lchild!=NULL)
                bookstack_analysis_borrow.push(bookptr_analysis_borrow->lchild);
        }
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_analysis;
        borrowrecordstack_analysis.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_analysis;
        while(!borrowrecordstack_analysis.isEmpty()){
            borrowrecordstack_analysis.pop(borrowrecordptr_analysis);
            int currentBookNumber=borrowrecordptr_analysis->data->value.getBookNum().AStringToInt();
            for(int j=0;j<booklistinmanager.BBSTNodeNum();j++){
                if(borrowNodelist[j].bookNum==currentBookNumber){
                    borrowNodelist[j].borrowNum++;
                }
            }
            if(borrowrecordptr_analysis->rchild!=NULL)
                borrowrecordstack_analysis.push(borrowrecordptr_analysis->rchild);
            if(borrowrecordptr_analysis->lchild!=NULL)
                borrowrecordstack_analysis.push(borrowrecordptr_analysis->lchild);
        }
        for(int i=0;i<booklistinmanager.BBSTNodeNum()-1;i++){
            int min_index=i;
            for(int j=i+1;j<booklistinmanager.BBSTNodeNum();j++){
                if(borrowNodelist[j].borrowNum<borrowNodelist[min_index].borrowNum){
                    min_index=j;
                }
            }
            if(i!=min_index){
                borrowNode tempNode=borrowNodelist[i];
                borrowNodelist[i]=borrowNodelist[min_index];
                borrowNodelist[min_index]=tempNode;
            }
        }
        for(int k=booklistinmanager.BBSTNodeNum()-1,p=0;k>=0;k--,p++){
            int bnum=borrowNodelist[k].bookNum;
            ui->tableWidget_8->insertRow(p);
            ui->tableWidget_8->setItem(p,0,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookNumber().AStringToString()));
            ui->tableWidget_8->setItem(p,1,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookName().AStringToString()));
            ui->tableWidget_8->setItem(p,2,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getWriterName().AStringToString()));
            ui->tableWidget_8->setItem(p,3,new QTableWidgetItem(QString::number(borrowNodelist[k].borrowNum)));

        }
}

ManagerWindow::~ManagerWindow()
{
    PrintBookTreeToFileInManager(booklistinmanager);
    PrintBorrowRecordListToFileInManager(borrowRecordlistinmanager);
    PrintBuyRecordListToFileInManager(buyrecordlistinmanager);
    PrintCustomerListToFileInManager(customerlistinmanager);
    PrintManagerListToFileInManager(managerlistinmanager);
    delete ui;
}

void ManagerWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        //select with booknumber
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
        bookPtr=&booklistinmanager.SearchBBSTree(bookNumber.AStringToInt());
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
        //select with bookname
        char* bookName_char;
        QByteArray bookName_Array=ui->lineEdit->text().toLatin1();
        bookName_char=bookName_Array.data();
        AString bookName_AString(bookName_char);
        Stack<BBSTNode<Book,int>*> bookstack_Name;
        bookstack_Name.push(booklistinmanager.getRoot());
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
        //select with writer
        char* writerName_char;
        QByteArray writerName_Array=ui->lineEdit->text().toLatin1();
        writerName_char=writerName_Array.data();
        AString writerName_AString(writerName_char);
        Stack<BBSTNode<Book,int>*> bookstack_writer;
        bookstack_writer.push(booklistinmanager.getRoot());
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
        QMessageBox::warning(this,tr("Warning!"),tr("Choose a way first!"),QMessageBox::Yes);
    }
 }


void ManagerWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(booklistinmanager.BBSTNodeNum());
    ui->tableWidget->setColumnCount(8);
    Stack<BBSTNode<Book,int>*> bookStack;
    bookStack.push(booklistinmanager.getRoot());
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

void ManagerWindow::on_pushButton_3_clicked()
{
    //insert the book to the booklist,and display in the table;
    int bnum_insert;
    if(booklistinmanager.BBSTNodeNum()==0){
        bnum_insert=1;
    }
    else{
        bnum_insert=booklistinmanager.getRoot()->data->value.getBookNumber().AStringToInt();
        Stack<BBSTNode<Book,int>*> bookstack_insert;
        bookstack_insert.push(booklistinmanager.getRoot());
        BBSTNode<Book,int>* bookptr;
        while(!bookstack_insert.isEmpty()){
            bookstack_insert.pop(bookptr);
            if(bookptr->data->value.getBookNumber().AStringToInt()>=bnum_insert){
                bnum_insert=bookptr->data->value.getBookNumber().AStringToInt();
            }
            if(bookptr->rchild!=NULL)
                bookstack_insert.push(bookptr->rchild);
            if(bookptr->lchild!=NULL)
                bookstack_insert.push(bookptr->lchild);
        }
        bnum_insert++;
    }
    char bnum_insert_buf[10];
    itoa(bnum_insert,bnum_insert_buf,10);
    AString bookNumber_insert(bnum_insert_buf);
    char* bname_insert;
    QByteArray bname_insertArray=ui->lineEdit_9->text().toLatin1();
    bname_insert=bname_insertArray.data();
    AString bookName_insert(bname_insert);
    char* writer_insert;
    QByteArray writer_insertArray=ui->lineEdit_11->text().toLatin1();
    writer_insert=writer_insertArray.data();
    AString writerName(writer_insert);
    char* btype_insert;
    QByteArray btype_insertArray=ui->lineEdit_10->text().toLatin1();
    btype_insert=btype_insertArray.data();
    AString bookType(btype_insert);
    double itemPrice_insert=ui->lineEdit_12->text().toDouble();
    int incrementNum=ui->lineEdit_13->text().toInt();

    if(bookNumber_insert.Length()>0&&bookName_insert.Length()>0&&
            bookName_insert.Length()<32&&writerName.Length()>0&&
            writerName.Length()<32&&bookType.AStringToInt()>0&&bookType.AStringToInt()<14){
        Stack<BBSTNode<Book,int>*> bookstack_insert;
        bookstack_insert.push(booklistinmanager.getRoot());
        BBSTNode<Book,int>* bookptr_insert;
        int find_insert=0;
        while(!bookstack_insert.isEmpty()&&find_insert<1){
            bookstack_insert.pop(bookptr_insert);
            int currentbook_currentnumber=bookptr_insert->data->value.getCurrentNumber();
            int currentbook_inventory=bookptr_insert->data->value.getInventory();
            if(bookptr_insert->data->value.getBookName()==bookName_insert&&bookptr_insert->data->value.getWriterName()==writerName){
                QMessageBox::warning(this,tr("Tips!"),tr("The book has been inserted to the booktable!Just plus book number"),QMessageBox::Yes);
                bookptr_insert->data->value.setCurrentNumber(currentbook_currentnumber+incrementNum);
                bookptr_insert->data->value.setInventory(currentbook_inventory+incrementNum);
                int location=0;
                for(int i=0;i<ui->tableWidget->rowCount();i++){
                    char* bookname_existed;
                    QByteArray bookname_existedArray=ui->tableWidget->item(i,1)->text().toLatin1();
                    bookname_existed=bookname_existedArray.data();
                    AString bookName_existed(bookname_existed);
                    char* writer_existed;
                    QByteArray writer_existedArray=ui->tableWidget->item(i,2)->text().toLatin1();
                    writer_existed=writer_existedArray.data();
                    AString writer_Existed(writer_existed);
                    if(bookName_existed==bookName_insert&&writer_Existed==writerName){
                        location=i;
                        break;
                    }
                }
                ui->tableWidget->setItem(location,6,new QTableWidgetItem(QString::number(bookptr_insert->data->value.getCurrentNumber())));

                ui->tableWidget->setItem(location,7,new QTableWidgetItem(QString::number(bookptr_insert->data->value.getInventory())));
                find_insert++;
            }
            if(bookptr_insert->rchild!=NULL)
                bookstack_insert.push(bookptr_insert->rchild);
            if(bookptr_insert->lchild!=NULL)
                bookstack_insert.push(bookptr_insert->lchild);

        }
        if(find_insert==0){
            BookType bookType_insert(bookType);
            Book book(bookType_insert, bookNumber_insert, bookName_insert, writerName, incrementNum,incrementNum,itemPrice_insert);
            if(booklistinmanager.InsertBBSTree(book,bookNumber_insert.AStringToInt())){

                QMessageBox::warning(this,tr("Congratulations!"),tr("Insert Successfully!"),QMessageBox::Yes);
                int rowCount_insert=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount_insert);

                ui->tableWidget->setItem(rowCount_insert,0,new QTableWidgetItem(book.getBookNumber().AStringToString()));
                ui->tableWidget->setItem(rowCount_insert,1,new QTableWidgetItem(book.getBookName().AStringToString()));
                ui->tableWidget->setItem(rowCount_insert,2,new QTableWidgetItem(book.getWriterName().AStringToString()));
                ui->tableWidget->setItem(rowCount_insert,3,new QTableWidgetItem(book.getBookType().getType().AStringToString()));
                ui->tableWidget->setItem(rowCount_insert,4,new QTableWidgetItem(book.getBookType().getTypeName().AStringToString()));
                ui->tableWidget->setItem(rowCount_insert,5,new QTableWidgetItem(QString::number(book.getItemPrice())));
                ui->tableWidget->setItem(rowCount_insert,6,new QTableWidgetItem(QString::number(book.getCurrentNumber())));
                ui->tableWidget->setItem(rowCount_insert,7,new QTableWidgetItem(QString::number(book.getInventory())));
            }
            else{
                QMessageBox::warning(this,tr("Error!"),tr("BookNumber Existed!"),QMessageBox::Yes);
            }
        }
        //write book record to the file;
        PrintBookTreeToFileInManager(booklistinmanager);

    }
    else{
        QMessageBox::warning(this,tr("Error!"),tr("Book Information incorrected!"),QMessageBox::Yes);
    }
}

void ManagerWindow::on_pushButton_12_clicked()
{
    if(ui->tableWidget->selectedItems().size()>0){
        int currentRow_delete;
        currentRow_delete=ui->tableWidget->currentRow();
        char* bNum_delete;
        QByteArray bNum_deleteArray=ui->tableWidget->item( currentRow_delete,0)->text().toLatin1();
        bNum_delete=bNum_deleteArray.data();
        AString bookNumber(bNum_delete);
        BBSTNode<Book,int>* bookptr_delete;
        bookptr_delete= &booklistinmanager.SearchBBSTree(bookNumber.AStringToInt());
        if(bookptr_delete->data->value.getCurrentNumber()>0||bookptr_delete->data->value.getInventory()>0){
            QMessageBox::warning(this,tr("Error!"),tr("Can't delete books!Current Number or inventory >0!"),QMessageBox::Yes);
        }
        else{
            booklistinmanager.DeleteBBSTree(bookNumber.AStringToInt());
            ui->tableWidget->removeRow(currentRow_delete);
            //write book record to the file;
            PrintBookTreeToFileInManager(booklistinmanager);
            QMessageBox::warning(this,tr("Tips!"),tr("Delete Successfully!"),QMessageBox::Yes);
        }
    }
}

void ManagerWindow::on_pushButton_11_clicked()
{
    emit ui->lineEdit_6->textEdited(QString());
    emit ui->lineEdit_7->textEdited(QString());

    connect(ui->lineEdit_6,SIGNAL(textEdited(QString)),this,SLOT(namechange_handle()));
    connect(ui->lineEdit_7,SIGNAL(textEdited(QString)),this,SLOT(passwordchange_handle()));
    //write the managerrecord to the file;
    PrintManagerListToFileInManager(managerlistinmanager);

    QMessageBox::warning(this,tr("Be sure to your change!"),tr("Have changed!"),QMessageBox::Yes);
}

void ManagerWindow::namechange_handle()
{
    BBSTNode<Manager,int> *managerptr_change;
    managerptr_change=&managerlistinmanager.SearchBBSTree(currentManagerNumber);
    char * name_change;
    QByteArray name_changeArray=ui->lineEdit_3->text().toLatin1();
    name_change=name_changeArray.data();
    AString name_changeValue(name_change);
    managerptr_change->data->value.setName(name_changeValue);
}

void ManagerWindow::passwordchange_handle()
{
    BBSTNode<Manager,int> *managerptr_change;
    managerptr_change=&managerlistinmanager.SearchBBSTree(currentManagerNumber);
    char * password_change;
    QByteArray password_changeArray=ui->lineEdit_4->text().toLatin1();
    password_change=password_changeArray.data();
    AString password_changeValue(password_change);
    managerptr_change->data->value.setPassword(password_changeValue);
}

void ManagerWindow::on_pushButton_8_clicked()
{
    if(ui->radioButton_15->isChecked()){
        //select with vip type;
        char* viptype_search;
        QByteArray viptype_searchArray=ui->lineEdit_4->text().toLatin1();
        viptype_search=viptype_searchArray.data();
        AString type_search(viptype_search);
        int customerindex_type=ui->tableWidget_4->rowCount();
        while(customerindex_type!=0){
            ui->tableWidget_4->removeRow(customerindex_type-1);
            customerindex_type=ui->tableWidget_4->rowCount();
        }
        Stack<BBSTNode<Customer,int>*> customerstack_type;
        customerstack_type.push(customerlistinmanager.getRoot());
        BBSTNode<Customer,int>* customerptr_type;
        int find_type=0;
        while(!customerstack_type.isEmpty()){
            customerstack_type.pop(customerptr_type);
            if(customerptr_type->data->value.getVip().getType()==type_search){
                int rowcount_type=ui->tableWidget_4->rowCount();
                ui->tableWidget_4->insertRow(rowcount_type);
                ui->tableWidget_4->setItem(rowcount_type,0,new QTableWidgetItem(customerptr_type->data->value.getNumber().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_type,1,new QTableWidgetItem(customerptr_type->data->value.getName().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_type,2,new QTableWidgetItem(customerptr_type->data->value.getPhoneNumber().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_type,3,new QTableWidgetItem(customerptr_type->data->value.getVip().getType().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_type,4,new QTableWidgetItem(customerptr_type->data->value.getVip().getTypeName().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_type,5,new QTableWidgetItem(QString::number(customerptr_type->data->value.getVip().getMoney())));
                find_type++;
            }
            if(customerptr_type->rchild!=NULL)
                customerstack_type.push(customerptr_type->rchild);
            if(customerptr_type->lchild!=NULL)
                customerstack_type.push(customerptr_type->lchild);
        }
        if(find_type==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Vip type number error!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_14->isChecked()){
        //select with customer number;
        char* cnum_search;
        QByteArray cnum_searchArray=ui->lineEdit_4->text().toLatin1();
        cnum_search=cnum_searchArray.data();
        AString Cnumber(cnum_search);
        int rowindex_search=ui->tableWidget_4->rowCount();
        while(rowindex_search!=0){
            ui->tableWidget_4->removeRow(rowindex_search-1);
            rowindex_search=ui->tableWidget_4->rowCount();

        }
        BBSTNode<Customer,int>* customerptr_search_number;
        customerptr_search_number=&customerlistinmanager.SearchBBSTree(Cnumber.AStringToInt());
        if(customerptr_search_number!=NULL){
            ui->tableWidget_4->setRowCount(1);
            ui->tableWidget_4->setColumnCount(6);
            ui->tableWidget_4->setItem(0,0,new QTableWidgetItem(customerptr_search_number->data->value.getNumber().AStringToString()));
            ui->tableWidget_4->setItem(0,1,new QTableWidgetItem(customerptr_search_number->data->value.getName().AStringToString()));
            ui->tableWidget_4->setItem(0,2,new QTableWidgetItem(customerptr_search_number->data->value.getPhoneNumber().AStringToString()));
            ui->tableWidget_4->setItem(0,3,new QTableWidgetItem(customerptr_search_number->data->value.getVip().getType().AStringToString()));
            ui->tableWidget_4->setItem(0,4,new QTableWidgetItem(customerptr_search_number->data->value.getVip().getTypeName().AStringToString()));
            ui->tableWidget_4->setItem(0,5,new QTableWidgetItem(QString::number(customerptr_search_number->data->value.getVip().getMoney())));
        }
        else{
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }

    }
    else if(ui->radioButton_13->isChecked()){
        //select with customer name;
        char* customername_search;
        QByteArray customername_searchArray=ui->lineEdit_4->text().toLatin1();
        customername_search=customername_searchArray.data();
        AString customerName_search(customername_search);
        int customerindex_search=ui->tableWidget_4->rowCount();
        while(customerindex_search!=0){
            ui->tableWidget_4->removeRow(customerindex_search-1);
            customerindex_search=ui->tableWidget_4->rowCount();
        }
        Stack<BBSTNode<Customer,int>*> customerstack_name;
        customerstack_name.push(customerlistinmanager.getRoot());
        BBSTNode<Customer,int>* customerptr_name;
        int find_name=0;
        while(!customerstack_name.isEmpty()){
            customerstack_name.pop(customerptr_name);
            if(customerptr_name->data->value.getName()==customerName_search){
                int rowcount_name=ui->tableWidget_4->rowCount();
                ui->tableWidget_4->insertRow(rowcount_name);
                ui->tableWidget_4->setItem(rowcount_name,0,new QTableWidgetItem(customerptr_name->data->value.getNumber().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_name,1,new QTableWidgetItem(customerptr_name->data->value.getName().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_name,2,new QTableWidgetItem(customerptr_name->data->value.getPhoneNumber().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_name,3,new QTableWidgetItem(customerptr_name->data->value.getVip().getType().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_name,4,new QTableWidgetItem(customerptr_name->data->value.getVip().getTypeName().AStringToString()));
                ui->tableWidget_4->setItem(rowcount_name,5,new QTableWidgetItem(QString::number(customerptr_name->data->value.getVip().getMoney())));
                find_name++;
            }
            if(customerptr_name->rchild!=NULL)
                customerstack_name.push(customerptr_name->rchild);
            if(customerptr_name->lchild!=NULL)
                customerstack_name.push(customerptr_name->lchild);
        }
        if(find_name==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }

    }
    else{
        QMessageBox::warning(this,tr("Error!"),tr("Choose a way first!"),QMessageBox::Yes);
    }
}

void ManagerWindow::on_pushButton_9_clicked()
{
    //display all customers;
    ui->tableWidget_4->setRowCount(customerlistinmanager.BBSTNodeNum());
    ui->tableWidget_4->setColumnCount(6);
    Stack<BBSTNode<Customer,int>*> customerstack;
    customerstack.push(customerlistinmanager.getRoot());
    BBSTNode<Customer,int>* customerptr;
    int customercount=0;
    while(!customerstack.isEmpty()){
        customerstack.pop(customerptr);
        ui->tableWidget_4->setItem(customercount,0,new QTableWidgetItem(customerptr->data->value.getNumber().AStringToString()));
        ui->tableWidget_4->setItem(customercount,1,new QTableWidgetItem(customerptr->data->value.getName().AStringToString()));
        ui->tableWidget_4->setItem(customercount,2,new QTableWidgetItem(customerptr->data->value.getPhoneNumber().AStringToString()));
        ui->tableWidget_4->setItem(customercount,3,new QTableWidgetItem(customerptr->data->value.getVip().getType().AStringToString()));
        ui->tableWidget_4->setItem(customercount,4,new QTableWidgetItem(customerptr->data->value.getVip().getTypeName().AStringToString()));
        ui->tableWidget_4->setItem(customercount,5,new QTableWidgetItem(QString::number(customerptr->data->value.getVip().getMoney())));
        customercount++;
        if(customerptr->rchild!=NULL)
            customerstack.push(customerptr->rchild);
        if(customerptr->lchild!=NULL)
            customerstack.push(customerptr->lchild);
    }
}

void ManagerWindow::on_pushButton_10_clicked()
{
    //delete the customer who is selected
    if(ui->tableWidget_4->selectedItems().size()>0){
        int currentrow_delete;
        currentrow_delete=ui->tableWidget_4->currentRow();
        char* customernum_delete;
        QByteArray customernum_deleteArray=ui->tableWidget_4->item(currentrow_delete,0)->text().toLatin1();
        customernum_delete=customernum_deleteArray.data();
        AString Cnumber_delete(customernum_delete);
        customerlistinmanager.DeleteBBSTree(Cnumber_delete.AStringToInt());
        ui->tableWidget_4->removeRow(currentrow_delete);
        //write the customer record the file;
        PrintCustomerListToFileInManager(customerlistinmanager);

        QMessageBox::warning(this,tr("Mind your attention!"),tr("Delete Successfully!"),QMessageBox::Yes);
    }

}

void ManagerWindow::on_pushButton_6_clicked()
{
    if(ui->radioButton_9->isChecked()){
        //select with customer number
        char* customernumber_search;
        QByteArray customernumber_searchArray=ui->lineEdit_3->text().toLatin1();
        customernumber_search=customernumber_searchArray.data();
        AString customerNum_record(customernumber_search);
        Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_cnum;
        buyrecordstack_cnum.push(buyrecordlistinmanager.getRoot());
        BBSTNode<BuyRecord,int>* buyrecordptr_cnum;
        int find_cnum=0;
        int rowcountindex_cnum=ui->tableWidget_3->rowCount();
        while(rowcountindex_cnum!=0){
            ui->tableWidget_3->removeRow(rowcountindex_cnum-1);
            rowcountindex_cnum=ui->tableWidget_3->rowCount();
        }
        while(!buyrecordstack_cnum.isEmpty()){
            buyrecordstack_cnum.pop(buyrecordptr_cnum);
            if(buyrecordptr_cnum->data->value.getCustomerNum()==customerNum_record){
                int currentrow_cnum=ui->tableWidget_3->rowCount();
                ui->tableWidget_3->insertRow(currentrow_cnum);
                ui->tableWidget_3->setItem(currentrow_cnum,0,new QTableWidgetItem(buyrecordptr_cnum->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,1,new QTableWidgetItem(buyrecordptr_cnum->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,2,new QTableWidgetItem(buyrecordptr_cnum->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,3,new QTableWidgetItem(QString::number(buyrecordptr_cnum->data->value.getBuyPrivilage())));
                ui->tableWidget_3->setItem(currentrow_cnum,4,new QTableWidgetItem(buyrecordptr_cnum->data->value.getBookNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,5,new QTableWidgetItem(buyrecordptr_cnum->data->value.getBookName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,6,new QTableWidgetItem(buyrecordptr_cnum->data->value.getWriterName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,7,new QTableWidgetItem(buyrecordptr_cnum->data->value.getBuyTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cnum,8,new QTableWidgetItem(QString::number(buyrecordptr_cnum->data->value.getItemPrice())));
                ui->tableWidget_3->setItem(currentrow_cnum,9,new QTableWidgetItem(QString::number(buyrecordptr_cnum->data->value.getBuyNum())));
                ui->tableWidget_3->setItem(currentrow_cnum,10,new QTableWidgetItem(QString::number(buyrecordptr_cnum->data->value.getTotalPrice())));
                ui->tableWidget_3->setItem(currentrow_cnum,11,new QTableWidgetItem(buyrecordptr_cnum->data->value.getRecordNumber().AStringToString()));
                find_cnum++;
            }
            if(buyrecordptr_cnum->rchild!=NULL)
                buyrecordstack_cnum.push(buyrecordptr_cnum->rchild);
            if(buyrecordptr_cnum->lchild!=NULL)
                buyrecordstack_cnum.push(buyrecordptr_cnum->lchild);
        }
        if(find_cnum==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_10->isChecked()){
        //select with customer name
        char* customername_search;
        QByteArray customername_searchArray=ui->lineEdit_3->text().toLatin1();
        customername_search=customername_searchArray.data();
        AString customerName_record(customername_search);
        Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_cname;
        buyrecordstack_cname.push(buyrecordlistinmanager.getRoot());
        BBSTNode<BuyRecord,int>* buyrecordptr_cname;
        int find_cname=0;
        int rowcountindex_cname=ui->tableWidget_3->rowCount();
        while(rowcountindex_cname!=0){
            ui->tableWidget_3->removeRow(rowcountindex_cname-1);
            rowcountindex_cname=ui->tableWidget_3->rowCount();
        }
        while(!buyrecordstack_cname.isEmpty()){
            buyrecordstack_cname.pop(buyrecordptr_cname);
            if(buyrecordptr_cname->data->value.getCustomerName()==customerName_record){
                int currentrow_cname=ui->tableWidget_3->rowCount();
                ui->tableWidget_3->insertRow(currentrow_cname);
                ui->tableWidget_3->setItem(currentrow_cname,0,new QTableWidgetItem(buyrecordptr_cname->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,1,new QTableWidgetItem(buyrecordptr_cname->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,2,new QTableWidgetItem(buyrecordptr_cname->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,3,new QTableWidgetItem(QString::number(buyrecordptr_cname->data->value.getBuyPrivilage())));
                ui->tableWidget_3->setItem(currentrow_cname,4,new QTableWidgetItem(buyrecordptr_cname->data->value.getBookNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,5,new QTableWidgetItem(buyrecordptr_cname->data->value.getBookName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,6,new QTableWidgetItem(buyrecordptr_cname->data->value.getWriterName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,7,new QTableWidgetItem(buyrecordptr_cname->data->value.getBuyTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_cname,8,new QTableWidgetItem(QString::number(buyrecordptr_cname->data->value.getItemPrice())));
                ui->tableWidget_3->setItem(currentrow_cname,9,new QTableWidgetItem(QString::number(buyrecordptr_cname->data->value.getBuyNum())));
                ui->tableWidget_3->setItem(currentrow_cname,10,new QTableWidgetItem(QString::number(buyrecordptr_cname->data->value.getTotalPrice())));
                ui->tableWidget_3->setItem(currentrow_cname,11,new QTableWidgetItem(buyrecordptr_cname->data->value.getRecordNumber().AStringToString()));
                find_cname++;
            }
            if(buyrecordptr_cname->rchild!=NULL)
                buyrecordstack_cname.push(buyrecordptr_cname->rchild);
            if(buyrecordptr_cname->lchild!=NULL)
                buyrecordstack_cname.push(buyrecordptr_cname->lchild);
        }
        if(find_cname==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_11->isChecked()){
        //select with book number
        char* booknum_search;
        QByteArray booknum_searchArray=ui->lineEdit_3->text().toLatin1();
        booknum_search=booknum_searchArray.data();
        AString bookNumber_record(booknum_search);
        Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_bnum;
        buyrecordstack_bnum.push(buyrecordlistinmanager.getRoot());
        BBSTNode<BuyRecord,int>* buyrecordptr_bnum;
        int find_bnum=0;
        int rowcountindex_bnum=ui->tableWidget_3->rowCount();
        while(rowcountindex_bnum!=0){
            ui->tableWidget_3->removeRow(rowcountindex_bnum-1);
            rowcountindex_bnum=ui->tableWidget_3->rowCount();
        }
        while(!buyrecordstack_bnum.isEmpty()){
            buyrecordstack_bnum.pop(buyrecordptr_bnum);
            if(buyrecordptr_bnum->data->value.getBookNum()==bookNumber_record){
                int currentrow_bnum=ui->tableWidget_3->rowCount();
                ui->tableWidget_3->insertRow(currentrow_bnum);
                ui->tableWidget_3->setItem(currentrow_bnum,0,new QTableWidgetItem(buyrecordptr_bnum->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,1,new QTableWidgetItem(buyrecordptr_bnum->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,2,new QTableWidgetItem(buyrecordptr_bnum->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,3,new QTableWidgetItem(QString::number(buyrecordptr_bnum->data->value.getBuyPrivilage())));
                ui->tableWidget_3->setItem(currentrow_bnum,4,new QTableWidgetItem(buyrecordptr_bnum->data->value.getBookNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,5,new QTableWidgetItem(buyrecordptr_bnum->data->value.getBookName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,6,new QTableWidgetItem(buyrecordptr_bnum->data->value.getWriterName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,7,new QTableWidgetItem(buyrecordptr_bnum->data->value.getBuyTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bnum,8,new QTableWidgetItem(QString::number(buyrecordptr_bnum->data->value.getItemPrice())));
                ui->tableWidget_3->setItem(currentrow_bnum,9,new QTableWidgetItem(QString::number(buyrecordptr_bnum->data->value.getBuyNum())));
                ui->tableWidget_3->setItem(currentrow_bnum,10,new QTableWidgetItem(QString::number(buyrecordptr_bnum->data->value.getTotalPrice())));
                ui->tableWidget_3->setItem(currentrow_bnum,11,new QTableWidgetItem(buyrecordptr_bnum->data->value.getRecordNumber().AStringToString()));
                find_bnum++;
            }
            if(buyrecordptr_bnum->rchild!=NULL)
                buyrecordstack_bnum.push(buyrecordptr_bnum->rchild);
            if(buyrecordptr_bnum->lchild!=NULL)
                buyrecordstack_bnum.push(buyrecordptr_bnum->lchild);
        }
        if(find_bnum==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_12->isChecked()){
        //select with book name
        char* bookname_search;
        QByteArray bookname_searchArray=ui->lineEdit_3->text().toLatin1();
        bookname_search=bookname_searchArray.data();
        AString bookName_record(bookname_search);
        Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_bname;
        buyrecordstack_bname.push(buyrecordlistinmanager.getRoot());
        BBSTNode<BuyRecord,int>* buyrecordptr_bname;
        int find_bname=0;
        int rowcountindex_bname=ui->tableWidget_3->rowCount();
        while(rowcountindex_bname!=0){
            ui->tableWidget_3->removeRow(rowcountindex_bname-1);
            rowcountindex_bname=ui->tableWidget_3->rowCount();
        }
        while(!buyrecordstack_bname.isEmpty()){
            buyrecordstack_bname.pop(buyrecordptr_bname);
            if(buyrecordptr_bname->data->value.getBookName()==bookName_record){
                int currentrow_bname=ui->tableWidget_3->rowCount();
                ui->tableWidget_3->insertRow(currentrow_bname);
                ui->tableWidget_3->setItem(currentrow_bname,0,new QTableWidgetItem(buyrecordptr_bname->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,1,new QTableWidgetItem(buyrecordptr_bname->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,2,new QTableWidgetItem(buyrecordptr_bname->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,3,new QTableWidgetItem(QString::number(buyrecordptr_bname->data->value.getBuyPrivilage())));
                ui->tableWidget_3->setItem(currentrow_bname,4,new QTableWidgetItem(buyrecordptr_bname->data->value.getBookNum().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,5,new QTableWidgetItem(buyrecordptr_bname->data->value.getBookName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,6,new QTableWidgetItem(buyrecordptr_bname->data->value.getWriterName().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,7,new QTableWidgetItem(buyrecordptr_bname->data->value.getBuyTime().getDateValue().AStringToString()));
                ui->tableWidget_3->setItem(currentrow_bname,8,new QTableWidgetItem(QString::number(buyrecordptr_bname->data->value.getItemPrice())));
                ui->tableWidget_3->setItem(currentrow_bname,9,new QTableWidgetItem(QString::number(buyrecordptr_bname->data->value.getBuyNum())));
                ui->tableWidget_3->setItem(currentrow_bname,10,new QTableWidgetItem(QString::number(buyrecordptr_bname->data->value.getTotalPrice())));
                ui->tableWidget_3->setItem(currentrow_bname,11,new QTableWidgetItem(buyrecordptr_bname->data->value.getRecordNumber().AStringToString()));
                find_bname++;
            }
            if(buyrecordptr_bname->rchild!=NULL)
                buyrecordstack_bname.push(buyrecordptr_bname->rchild);
            if(buyrecordptr_bname->lchild!=NULL)
                buyrecordstack_bname.push(buyrecordptr_bname->lchild);
        }
        if(find_bname==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::warning(this,tr("Error!"),tr("Choose a way first!"),QMessageBox::Yes);
    }
}

void ManagerWindow::on_pushButton_7_clicked()
{
    //display all buyrecord
    ui->tableWidget_3->setRowCount(buyrecordlistinmanager.BBSTNodeNum());
    ui->tableWidget_3->setColumnCount(12);
    Stack<BBSTNode<BuyRecord,int>*> buyrecordstack;
    buyrecordstack.push(buyrecordlistinmanager.getRoot());
    BBSTNode<BuyRecord,int> *buyrecordptr;
    int buyrecordcount=0;
    while(!buyrecordstack.isEmpty()){
        buyrecordstack.pop(buyrecordptr);
        ui->tableWidget_3->setItem(buyrecordcount,0,new QTableWidgetItem(buyrecordptr->data->value.getCustomerNum().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,1,new QTableWidgetItem(buyrecordptr->data->value.getCustomerName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,2,new QTableWidgetItem(buyrecordptr->data->value.getCustomerPhone().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,3,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyPrivilage())));
        ui->tableWidget_3->setItem(buyrecordcount,4,new QTableWidgetItem(buyrecordptr->data->value.getBookNum().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,5,new QTableWidgetItem(buyrecordptr->data->value.getBookName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,6,new QTableWidgetItem(buyrecordptr->data->value.getWriterName().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,7,new QTableWidgetItem(buyrecordptr->data->value.getBuyTime().getDateValue().AStringToString()));
        ui->tableWidget_3->setItem(buyrecordcount,8,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getItemPrice())));
        ui->tableWidget_3->setItem(buyrecordcount,9,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getBuyNum())));
        ui->tableWidget_3->setItem(buyrecordcount,10,new QTableWidgetItem(QString::number(buyrecordptr->data->value.getTotalPrice())));
        ui->tableWidget_3->setItem(buyrecordcount,11,new QTableWidgetItem(buyrecordptr->data->value.getRecordNumber().AStringToString()));
        buyrecordcount++;
        if(buyrecordptr->rchild!=NULL)
            buyrecordstack.push(buyrecordptr->rchild);
        if(buyrecordptr->lchild!=NULL)
            buyrecordstack.push(buyrecordptr->lchild);
    }

}

void ManagerWindow::on_pushButton_14_clicked()
{
    if(ui->tableWidget_3->selectedItems().size()>0){
        int currentrow_delete;
        currentrow_delete=ui->tableWidget_3->currentRow();
        char* recordnum_delete;
        QByteArray recordnum_deleteArray=ui->tableWidget_3->item(currentrow_delete,11)->text().toLatin1();
        recordnum_delete=recordnum_deleteArray.data();
        AString recordNumber_delete(recordnum_delete);
        buyrecordlistinmanager.DeleteBBSTree(recordNumber_delete.AStringToInt());
        ui->tableWidget_3->removeRow(currentrow_delete);
        //write the buyrecord the file;

        PrintBuyRecordListToFileInManager(buyrecordlistinmanager);

        QMessageBox::warning(this,tr("Mind your attention!"),tr("Delete Successfully!"),QMessageBox::Yes);
    }
}

void ManagerWindow::on_pushButton_4_clicked()
{
    if(ui->radioButton_4->isChecked()){
        //select with book number
        char* booknum_search;
        QByteArray booknum_searchArray=ui->lineEdit_2->text().toLatin1();
        booknum_search=booknum_searchArray.data();
        AString bookNumber_record(booknum_search);
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_bnum;
        borrowrecordstack_bnum.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_bnum;
        int find_bnum=0;
        int rowcountindex_bnum=ui->tableWidget_2->rowCount();
        while(rowcountindex_bnum!=0){
            ui->tableWidget_2->removeRow(rowcountindex_bnum-1);
            rowcountindex_bnum=ui->tableWidget_2->rowCount();
        }
        while(!borrowrecordstack_bnum.isEmpty()){
            borrowrecordstack_bnum.pop(borrowrecordptr_bnum);
            if(borrowrecordptr_bnum->data->value.getBookNum()==bookNumber_record){
                int currentrow_bnum=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(currentrow_bnum);
                ui->tableWidget_2->setItem(currentrow_bnum,0,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,1,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,2,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,3,new QTableWidgetItem(QString::number(borrowrecordptr_bnum->data->value.getBorrowPrivilage())));
                ui->tableWidget_2->setItem(currentrow_bnum,4,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getBookNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,5,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getBookName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,6,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getWriterName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,7,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getBorrowTime().getDateValue().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bnum,8,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getReturnTime().getDateValue().AStringToString()));
                if(borrowrecordptr_bnum->data->value.getBorrowState()){
                    ui->tableWidget_2->setItem(currentrow_bnum,9,new QTableWidgetItem("returned"));
                }
                ui->tableWidget_2->setItem(currentrow_bnum,9,new QTableWidgetItem("returnning"));
                ui->tableWidget_2->setItem(currentrow_bnum,10,new QTableWidgetItem(borrowrecordptr_bnum->data->value.getRecordNumber().AStringToString()));
                find_bnum++;
            }
            if(borrowrecordptr_bnum->rchild!=NULL)
                borrowrecordstack_bnum.push(borrowrecordptr_bnum->rchild);
            if(borrowrecordptr_bnum->lchild!=NULL)
                borrowrecordstack_bnum.push(borrowrecordptr_bnum->lchild);
        }
        if(find_bnum==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_5->isChecked()){
        //select with book name
        char* bookname_search;
        QByteArray bookname_searchArray=ui->lineEdit_2->text().toLatin1();
        bookname_search=bookname_searchArray.data();
        AString bookName_record(bookname_search);
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_bname;
        borrowrecordstack_bname.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_bname;
        int find_bname=0;
        int rowcountindex_bname=ui->tableWidget_2->rowCount();
        while(rowcountindex_bname!=0){
            ui->tableWidget_2->removeRow(rowcountindex_bname-1);
            rowcountindex_bname=ui->tableWidget_2->rowCount();
        }
        while(!borrowrecordstack_bname.isEmpty()){
            borrowrecordstack_bname.pop(borrowrecordptr_bname);
            if(borrowrecordptr_bname->data->value.getBookName()==bookName_record){
                int currentrow_bname=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(currentrow_bname);
                ui->tableWidget_2->setItem(currentrow_bname,0,new QTableWidgetItem(borrowrecordptr_bname->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,1,new QTableWidgetItem(borrowrecordptr_bname->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,2,new QTableWidgetItem(borrowrecordptr_bname->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,3,new QTableWidgetItem(QString::number(borrowrecordptr_bname->data->value.getBorrowPrivilage())));
                ui->tableWidget_2->setItem(currentrow_bname,4,new QTableWidgetItem(borrowrecordptr_bname->data->value.getBookNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,5,new QTableWidgetItem(borrowrecordptr_bname->data->value.getBookName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,6,new QTableWidgetItem(borrowrecordptr_bname->data->value.getWriterName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,7,new QTableWidgetItem(borrowrecordptr_bname->data->value.getBorrowTime().getDateValue().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_bname,8,new QTableWidgetItem(borrowrecordptr_bname->data->value.getReturnTime().getDateValue().AStringToString()));
                if(borrowrecordptr_bname->data->value.getBorrowState()){
                    ui->tableWidget_2->setItem(currentrow_bname,9,new QTableWidgetItem("returned"));
                }
                ui->tableWidget_2->setItem(currentrow_bname,9,new QTableWidgetItem("returnning"));
                ui->tableWidget_2->setItem(currentrow_bname,10,new QTableWidgetItem(borrowrecordptr_bname->data->value.getRecordNumber().AStringToString()));
                find_bname++;
            }
            if(borrowrecordptr_bname->rchild!=NULL)
                borrowrecordstack_bname.push(borrowrecordptr_bname->rchild);
            if(borrowrecordptr_bname->lchild!=NULL)
                borrowrecordstack_bname.push(borrowrecordptr_bname->lchild);
        }
        if(find_bname==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_6->isChecked()){
        //select with customer number
        char* customernum_search;
        QByteArray customernum_searchArray=ui->lineEdit_2->text().toLatin1();
        customernum_search=customernum_searchArray.data();
        AString customerNumber_record(customernum_search);
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_cnum;
        borrowrecordstack_cnum.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_cnum;
        int find_cnum=0;
        int rowcountindex_cnum=ui->tableWidget_2->rowCount();
        while(rowcountindex_cnum!=0){
            ui->tableWidget_2->removeRow(rowcountindex_cnum-1);
            rowcountindex_cnum=ui->tableWidget_2->rowCount();
        }
        while(!borrowrecordstack_cnum.isEmpty()){
            borrowrecordstack_cnum.pop(borrowrecordptr_cnum);
            if(borrowrecordptr_cnum->data->value.getCustomerNum()==customerNumber_record){
                int currentrow_cnum=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(currentrow_cnum);
                ui->tableWidget_2->setItem(currentrow_cnum,0,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,1,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,2,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,3,new QTableWidgetItem(QString::number(borrowrecordptr_cnum->data->value.getBorrowPrivilage())));
                ui->tableWidget_2->setItem(currentrow_cnum,4,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getBookNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,5,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getBookName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,6,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getWriterName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,7,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getBorrowTime().getDateValue().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cnum,8,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getReturnTime().getDateValue().AStringToString()));
                if(borrowrecordptr_cnum->data->value.getBorrowState()){
                    ui->tableWidget_2->setItem(currentrow_cnum,9,new QTableWidgetItem("returned"));
                }
                ui->tableWidget_2->setItem(currentrow_cnum,9,new QTableWidgetItem("returnning"));
                ui->tableWidget_2->setItem(currentrow_cnum,10,new QTableWidgetItem(borrowrecordptr_cnum->data->value.getRecordNumber().AStringToString()));
                find_cnum++;
            }
            if(borrowrecordptr_cnum->rchild!=NULL)
                borrowrecordstack_cnum.push(borrowrecordptr_cnum->rchild);
            if(borrowrecordptr_cnum->lchild!=NULL)
                borrowrecordstack_cnum.push(borrowrecordptr_cnum->lchild);
        }
        if(find_cnum==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_7->isChecked()){
        //select with customer name
        char* customername_search;
        QByteArray customername_searchArray=ui->lineEdit_2->text().toLatin1();
        customername_search=customername_searchArray.data();
        AString customerName_record(customername_search);
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_cname;
        borrowrecordstack_cname.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_cname;
        int find_cname=0;
        int rowcountindex_cname=ui->tableWidget_2->rowCount();
        while(rowcountindex_cname!=0){
            ui->tableWidget_2->removeRow(rowcountindex_cname-1);
            rowcountindex_cname=ui->tableWidget_2->rowCount();
        }
        while(!borrowrecordstack_cname.isEmpty()){
            borrowrecordstack_cname.pop(borrowrecordptr_cname);
            if(borrowrecordptr_cname->data->value.getCustomerName()==customerName_record){
                int currentrow_cname=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(currentrow_cname);
                ui->tableWidget_2->setItem(currentrow_cname,0,new QTableWidgetItem(borrowrecordptr_cname->data->value.getCustomerNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,1,new QTableWidgetItem(borrowrecordptr_cname->data->value.getCustomerName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,2,new QTableWidgetItem(borrowrecordptr_cname->data->value.getCustomerPhone().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,3,new QTableWidgetItem(QString::number(borrowrecordptr_cname->data->value.getBorrowPrivilage())));
                ui->tableWidget_2->setItem(currentrow_cname,4,new QTableWidgetItem(borrowrecordptr_cname->data->value.getBookNum().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,5,new QTableWidgetItem(borrowrecordptr_cname->data->value.getBookName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,6,new QTableWidgetItem(borrowrecordptr_cname->data->value.getWriterName().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,7,new QTableWidgetItem(borrowrecordptr_cname->data->value.getBorrowTime().getDateValue().AStringToString()));
                ui->tableWidget_2->setItem(currentrow_cname,8,new QTableWidgetItem(borrowrecordptr_cname->data->value.getReturnTime().getDateValue().AStringToString()));
                if(borrowrecordptr_cname->data->value.getBorrowState()){
                    ui->tableWidget_2->setItem(currentrow_cname,9,new QTableWidgetItem("returned"));
                }
                else{
                     ui->tableWidget_2->setItem(currentrow_cname,9,new QTableWidgetItem("returnning"));
                }

                ui->tableWidget_2->setItem(currentrow_cname,10,new QTableWidgetItem(borrowrecordptr_cname->data->value.getRecordNumber().AStringToString()));
                find_cname++;
            }
            if(borrowrecordptr_cname->rchild!=NULL)
                borrowrecordstack_cname.push(borrowrecordptr_cname->rchild);
            if(borrowrecordptr_cname->lchild!=NULL)
                borrowrecordstack_cname.push(borrowrecordptr_cname->lchild);
        }
        if(find_cname==0){
            QMessageBox::warning(this,tr("Sorry!"),tr("Not found!"),QMessageBox::Yes);
        }
    }
    else if(ui->radioButton_8->isChecked()){
        //select with returnstate
        Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_state;
        borrowrecordstack_state.push(borrowRecordlistinmanager.getRoot());
        BBSTNode<BorrowRecord,int>* borrowrecordptr_state;
        int find_state=0;
        int rowcountindex_state=ui->tableWidget_2->rowCount();
        while(rowcountindex_state!=0){
            ui->tableWidget_2->removeRow(rowcountindex_state-1);
            rowcountindex_state=ui->tableWidget_2->rowCount();
        }
        char* state;
        QByteArray stateArray=ui->lineEdit_2->text().toLatin1();
        state=stateArray.data();
        AString State_search(state);
        AString Returning("returning");
        AString Returned("returned");
        bool returnState;
        if(State_search==Returning){
            returnState=false;
            while(!borrowrecordstack_state.isEmpty()){
                borrowrecordstack_state.pop(borrowrecordptr_state);
                if(!borrowrecordptr_state->data->value.getBorrowState()){
                    int currentrow_state=ui->tableWidget_2->rowCount();
                    ui->tableWidget_2->insertRow(currentrow_state);
                    ui->tableWidget_2->setItem(currentrow_state,0,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerNum().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,1,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,2,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerPhone().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,3,new QTableWidgetItem(QString::number(borrowrecordptr_state->data->value.getBorrowPrivilage())));
                    ui->tableWidget_2->setItem(currentrow_state,4,new QTableWidgetItem(borrowrecordptr_state->data->value.getBookNum().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,5,new QTableWidgetItem(borrowrecordptr_state->data->value.getBookName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,6,new QTableWidgetItem(borrowrecordptr_state->data->value.getWriterName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,7,new QTableWidgetItem(borrowrecordptr_state->data->value.getBorrowTime().getDateValue().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,8,new QTableWidgetItem(borrowrecordptr_state->data->value.getReturnTime().getDateValue().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,9,new QTableWidgetItem("returning"));
                    ui->tableWidget_2->setItem(currentrow_state,10,new QTableWidgetItem(borrowrecordptr_state->data->value.getRecordNumber().AStringToString()));
                    find_state++;
                }
                if(borrowrecordptr_state->rchild!=NULL)
                    borrowrecordstack_state.push(borrowrecordptr_state->rchild);
                if(borrowrecordptr_state->lchild!=NULL)
                    borrowrecordstack_state.push(borrowrecordptr_state->lchild);

        }
            if(find_state==0){
                QMessageBox::warning(this,tr("Tips"),tr("All books are returned! "),QMessageBox::Yes);
            }
        }
        else if(State_search==Returned){
            returnState=true;
            while(!borrowrecordstack_state.isEmpty()){
                borrowrecordstack_state.pop(borrowrecordptr_state);
                if(borrowrecordptr_state->data->value.getBorrowState()){
                    int currentrow_state=ui->tableWidget_2->rowCount();
                    ui->tableWidget_2->insertRow(currentrow_state);
                    ui->tableWidget_2->setItem(currentrow_state,0,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerNum().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,1,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,2,new QTableWidgetItem(borrowrecordptr_state->data->value.getCustomerPhone().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,3,new QTableWidgetItem(QString::number(borrowrecordptr_state->data->value.getBorrowPrivilage())));
                    ui->tableWidget_2->setItem(currentrow_state,4,new QTableWidgetItem(borrowrecordptr_state->data->value.getBookNum().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,5,new QTableWidgetItem(borrowrecordptr_state->data->value.getBookName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,6,new QTableWidgetItem(borrowrecordptr_state->data->value.getWriterName().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,7,new QTableWidgetItem(borrowrecordptr_state->data->value.getBorrowTime().getDateValue().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,8,new QTableWidgetItem(borrowrecordptr_state->data->value.getReturnTime().getDateValue().AStringToString()));
                    ui->tableWidget_2->setItem(currentrow_state,9,new QTableWidgetItem("returned"));
                    ui->tableWidget_2->setItem(currentrow_state,10,new QTableWidgetItem(borrowrecordptr_state->data->value.getRecordNumber().AStringToString()));
                    find_state++;
                }
                if(borrowrecordptr_state->rchild!=NULL)
                    borrowrecordstack_state.push(borrowrecordptr_state->rchild);
                if(borrowrecordptr_state->lchild!=NULL)
                    borrowrecordstack_state.push(borrowrecordptr_state->lchild);

        }
            if(find_state==0){
                QMessageBox::warning(this,tr("Tips"),tr("All books aren't returned! "),QMessageBox::Yes);
            }
        }
        else{
            QMessageBox::warning(this,tr("Error!"),tr("Borrow state Error!"),QMessageBox::Yes);
        }


    }
}

void ManagerWindow::on_pushButton_5_clicked()
{
    //dispaly all records
    ui->tableWidget_2->setRowCount(borrowRecordlistinmanager.BBSTNodeNum());
    ui->tableWidget_2->setColumnCount(11);
    Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack;
    borrowrecordstack.push(borrowRecordlistinmanager.getRoot());
    BBSTNode<BorrowRecord,int> *borrowrecordptr;
    int borrowrecordcount1=0;
    while(!borrowrecordstack.isEmpty()){
        borrowrecordstack.pop(borrowrecordptr);
        ui->tableWidget_2->setItem(borrowrecordcount1,0,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerNum().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,1,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerName().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,2,new QTableWidgetItem(borrowrecordptr->data->value.getCustomerPhone().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,3,new QTableWidgetItem(QString::number(borrowrecordptr->data->value.getBorrowPrivilage())));
        ui->tableWidget_2->setItem(borrowrecordcount1,4,new QTableWidgetItem(borrowrecordptr->data->value.getBookNum().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,5,new QTableWidgetItem(borrowrecordptr->data->value.getBookName().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,6,new QTableWidgetItem(borrowrecordptr->data->value.getWriterName().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,7,new QTableWidgetItem(borrowrecordptr->data->value.getBorrowTime().getDateValue().AStringToString()));
        ui->tableWidget_2->setItem(borrowrecordcount1,8,new QTableWidgetItem(borrowrecordptr->data->value.getReturnTime().getDateValue().AStringToString()));
        if(borrowrecordptr->data->value.getBorrowState()){
            ui->tableWidget_2->setItem(borrowrecordcount1,9,new QTableWidgetItem("returned"));
        }
        else{
            ui->tableWidget_2->setItem(borrowrecordcount1,9,new QTableWidgetItem("returnning"));
        }

        ui->tableWidget_2->setItem(borrowrecordcount1,10,new QTableWidgetItem(borrowrecordptr->data->value.getRecordNumber().AStringToString()));
        borrowrecordcount1++;

        if(borrowrecordptr->rchild!=NULL)
            borrowrecordstack.push(borrowrecordptr->rchild);
        if(borrowrecordptr->lchild!=NULL)
            borrowrecordstack.push(borrowrecordptr->lchild);

    }
}

void ManagerWindow::on_pushButton_13_clicked()
{
    //delete the record chosen;
    if(ui->tableWidget_2->selectedItems().size()>0){
        int currentRow_delete;
        currentRow_delete=ui->tableWidget_2->currentRow();
        char* recordnumber_delete;
        QByteArray recordnumber_deleteArray=ui->tableWidget_2->item(currentRow_delete,10)->text().toLatin1();
        recordnumber_delete=recordnumber_deleteArray.data();
        AString recordNumber(recordnumber_delete);
        BBSTNode<BorrowRecord,int>* recordptr_delete;
        recordptr_delete=&borrowRecordlistinmanager.SearchBBSTree(recordNumber.AStringToInt());
        if(!recordptr_delete->data->value.getBorrowState()){
            QMessageBox::warning(this,tr("Error!"),tr("Book isn't returned!Can't delete!"),QMessageBox::Yes);
        }
        else{
            borrowRecordlistinmanager.DeleteBBSTree(recordNumber.AStringToInt());
            ui->tableWidget_2->removeRow(currentRow_delete);
           //write the borrow record to the file;
            PrintBorrowRecordListToFileInManager(borrowRecordlistinmanager);
            PrintBuyRecordListToFileInManager(buyrecordlistinmanager);
            PrintCustomerListToFileInManager(customerlistinmanager);
            PrintManagerListToFileInManager(managerlistinmanager);
            QMessageBox::warning(this,tr("Mind your Attention!"),tr("Delete Successfully!"),QMessageBox::Yes);
        }
    }
}

void ManagerWindow::on_pushButton_15_clicked()
{
    //update the buy message
    //analysisOfBuyrecord();
    int rowCount=ui->tableWidget_7->rowCount();
    while(rowCount!=0){
        ui->tableWidget_7->removeRow(rowCount-1);
        rowCount=ui->tableWidget_7->rowCount();
    }
    buyNode buyNodelist[booklistinmanager.BBSTNodeNum()];
    Stack<BBSTNode<Book,int>*> bookstack_analysis;
    bookstack_analysis.push(booklistinmanager.getRoot());
    int index=0;
    BBSTNode<Book,int>* bookptr_analysis;
    while(!bookstack_analysis.isEmpty()){
        bookstack_analysis.pop(bookptr_analysis);
        buyNodelist[index].bookNum=bookptr_analysis->data->value.getBookNumber().AStringToInt();
        buyNodelist[index].sellNum=0;
        index++;
        if(bookptr_analysis->rchild!=NULL)
            bookstack_analysis.push(bookptr_analysis->rchild);
        if(bookptr_analysis->lchild!=NULL)
            bookstack_analysis.push(bookptr_analysis->lchild);
    }
    Stack<BBSTNode<BuyRecord,int>*> buyrecordstack_analysis;
    buyrecordstack_analysis.push(buyrecordlistinmanager.getRoot());
    BBSTNode<BuyRecord,int>* buyrecordptr_analysis;
    while(!buyrecordstack_analysis.isEmpty()){
        buyrecordstack_analysis.pop(buyrecordptr_analysis);
        int currentBookNumber=buyrecordptr_analysis->data->value.getBookNum().AStringToInt();
        for(int j=0;j<booklistinmanager.BBSTNodeNum();j++){
            if(buyNodelist[j].bookNum==currentBookNumber){
                buyNodelist[j].sellNum+=buyrecordptr_analysis->data->value.getBuyNum();
            }
        }
        if(buyrecordptr_analysis->rchild!=NULL)
            buyrecordstack_analysis.push(buyrecordptr_analysis->rchild);
        if(buyrecordptr_analysis->lchild!=NULL)
            buyrecordstack_analysis.push(buyrecordptr_analysis->lchild);
    }
    for(int i=0;i<booklistinmanager.BBSTNodeNum()-1;i++){
        int min_index=i;
        for(int j=i+1;j<booklistinmanager.BBSTNodeNum();j++){
            if(buyNodelist[j].sellNum<buyNodelist[min_index].sellNum){
                min_index=j;
            }
        }
        if(i!=min_index){
            buyNode tempNode=buyNodelist[i];
            buyNodelist[i]=buyNodelist[min_index];
            buyNodelist[min_index]=tempNode;
        }
    }
    for(int k=booklistinmanager.BBSTNodeNum()-1,p=0;k>=0;k--,p++){
        int bnum=buyNodelist[k].bookNum;
        ui->tableWidget_7->insertRow(p);
        ui->tableWidget_7->setItem(p,0,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookNumber().AStringToString()));
        ui->tableWidget_7->setItem(p,1,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookName().AStringToString()));
        ui->tableWidget_7->setItem(p,2,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getWriterName().AStringToString()));
        ui->tableWidget_7->setItem(p,3,new QTableWidgetItem(QString::number(buyNodelist[k].sellNum)));

    }

}

void ManagerWindow::on_pushButton_16_clicked()
{
    //update the borrow message
    int rowCount=ui->tableWidget_8->rowCount();
    while(rowCount!=0){
        ui->tableWidget_8->removeRow(rowCount-1);
        rowCount=ui->tableWidget_8->rowCount();
    }
    borrowNode borrowNodelist[booklistinmanager.BBSTNodeNum()];
    Stack<BBSTNode<Book,int>*> bookstack_analysis;
    bookstack_analysis.push(booklistinmanager.getRoot());
    int index=0;
    BBSTNode<Book,int>* bookptr_analysis;
    while(!bookstack_analysis.isEmpty()){
        bookstack_analysis.pop(bookptr_analysis);
        borrowNodelist[index].bookNum=bookptr_analysis->data->value.getBookNumber().AStringToInt();
        borrowNodelist[index].borrowNum=0;
        index++;
        if(bookptr_analysis->rchild!=NULL)
            bookstack_analysis.push(bookptr_analysis->rchild);
        if(bookptr_analysis->lchild!=NULL)
            bookstack_analysis.push(bookptr_analysis->lchild);
    }
    Stack<BBSTNode<BorrowRecord,int>*> borrowrecordstack_analysis;
    borrowrecordstack_analysis.push(borrowRecordlistinmanager.getRoot());
    BBSTNode<BorrowRecord,int>* borrowrecordptr_analysis;
    while(!borrowrecordstack_analysis.isEmpty()){
        borrowrecordstack_analysis.pop(borrowrecordptr_analysis);
        int currentBookNumber=borrowrecordptr_analysis->data->value.getBookNum().AStringToInt();
        for(int j=0;j<booklistinmanager.BBSTNodeNum();j++){
            if(borrowNodelist[j].bookNum==currentBookNumber){
                borrowNodelist[j].borrowNum++;
            }
        }
        if(borrowrecordptr_analysis->rchild!=NULL)
            borrowrecordstack_analysis.push(borrowrecordptr_analysis->rchild);
        if(borrowrecordptr_analysis->lchild!=NULL)
            borrowrecordstack_analysis.push(borrowrecordptr_analysis->lchild);
    }
    for(int i=0;i<booklistinmanager.BBSTNodeNum()-1;i++){
        int min_index=i;
        for(int j=i+1;j<booklistinmanager.BBSTNodeNum();j++){
            if(borrowNodelist[j].borrowNum<borrowNodelist[min_index].borrowNum){
                min_index=j;
            }
        }
        if(i!=min_index){
            borrowNode tempNode=borrowNodelist[i];
            borrowNodelist[i]=borrowNodelist[min_index];
            borrowNodelist[min_index]=tempNode;
        }
    }
    for(int k=booklistinmanager.BBSTNodeNum()-1,p=0;k>=0;k--,p++){
        int bnum=borrowNodelist[k].bookNum;
        ui->tableWidget_8->insertRow(p);
        ui->tableWidget_8->setItem(p,0,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookNumber().AStringToString()));
        ui->tableWidget_8->setItem(p,1,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getBookName().AStringToString()));
        ui->tableWidget_8->setItem(p,2,new QTableWidgetItem(booklistinmanager.SearchBBSTree(bnum).data->value.getWriterName().AStringToString()));
        ui->tableWidget_8->setItem(p,3,new QTableWidgetItem(QString::number(borrowNodelist[k].borrowNum)));

    }
}
