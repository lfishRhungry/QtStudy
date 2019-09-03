#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // stackWidget使用
     // 设置默认索引位置
    ui->stackedWidget->setCurrentIndex(0);
    // 设置点击切换的连接
    connect(ui->pushButton_12, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_13, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_14, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    // 下拉框使用
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("奥迪");

    // label显示图片
    ui->label->setPixmap(QPixmap(":/moneyIcon.jpeg"));
    ui->label->setScaledContents(true); // 自适应大小

    // label显示gif
    QMovie *movie = new QMovie(":/girl1.gif");
    ui->label_2->setMovie(movie);
    ui->label_2->setScaledContents(true); // 自适应大小
    // 播放
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}
