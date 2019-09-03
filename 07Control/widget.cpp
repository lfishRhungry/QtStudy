#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 单选按钮 默认选中
    ui->radioButton->setChecked(true);
    // 复选按钮 捕捉价格低
    connect(ui->checkBox, &QCheckBox::stateChanged, this, [=](int state){
        qDebug()<<"state = "<<state;
    });

    // listWidget 其中每一行都是一个item
    QListWidgetItem *item = new QListWidgetItem("床头明月光");
    item->setTextAlignment(Qt::AlignHCenter); // 对齐方式
    ui->listWidget->addItem(item);
    // QStringList =====> QList<QString> 类似于List<String>
    // 可以一次性添加 但是不能设置对齐
    QStringList list;
    list<<"疑是地上霜"<<"举头望明月"<<"低头思故乡";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
