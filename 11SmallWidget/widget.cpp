#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 将按钮连接到自定义控件的接口
    // 这里的信号接受者可以是this也可以是widget
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getData();
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        ui->widget->setData(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
