#ifndef SKIPFROMTABLEWIDGET_H
#define SKIPFROMTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class SkipFromTableWidget;
}

class SkipFromTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SkipFromTableWidget(QWidget *parent = 0);
    ~SkipFromTableWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SkipFromTableWidget *ui;
};

#endif // SKIPFROMTABLEWIDGET_H
