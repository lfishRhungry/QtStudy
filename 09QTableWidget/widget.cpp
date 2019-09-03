#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // tableWidget使用
    // 设置列数
    ui->tableWidget->setColumnCount(3);

    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    // 设置行数
    ui->tableWidget->setRowCount(4);

    // 设置具体内容
//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("孔子"));
    // 准备好容器（列表）
    QList<QString> nameList; // 等同于QStringList
    nameList << "孔子" << "小乔" << "墨子" << "孙悟空";
    QStringList sexList;
    sexList << "男" << "女" << "男" << "猴";

    for(int i = 0; i < 4; i++){
        int col = 0;
        // STL使用方式
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        // 这种STL使用方式是可以抛出异常的 上面这种错了就会崩溃
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        // int 转 qstring
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(18 + i)));
    }

}

Widget::~Widget()
{
    delete ui;
}
