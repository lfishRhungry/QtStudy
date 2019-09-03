#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // treeWidget 树控件使用
    // 设置树头部 （参数使用匿名对象的方式）
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "介绍");
    // 新建item
    QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << "武力");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList() << "智力");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList() << "魅力");
    // 添加为根节点
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);
    // 准备子节点
    QStringList hero1;
    hero1 << "赵云" << "常山赵子龙";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(hero1);
    QStringList hero2;
    hero2 << "诸葛亮" << "卧龙一大条";
    QTreeWidgetItem *l2 = new QTreeWidgetItem(hero2);
    QStringList hero3;
    hero3 << "貂蝉" << "被吕布拐走";
    QTreeWidgetItem *l3 = new QTreeWidgetItem(hero3);
    // 添加子节点
    item->addChild(l1);
    item2->addChild(l2);
    item3->addChild(l3);
}

Widget::~Widget()
{
    delete ui;
}
