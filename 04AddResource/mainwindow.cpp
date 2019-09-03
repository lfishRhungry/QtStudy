#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // 建立UI的这一行代码放在最上面
    ui->setupUi(this);

    this->resize(1200, 1000);

    // 在新建菜单bar上添加图片
    // ui->actionNew->setIcon(QIcon("C:\\moneyIcon.jpeg"));
    // 资源文件使用方式 ': + 前缀名 + 文件名'
    ui->actionNew->setIcon(QIcon(":/moneyIcon.jpeg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
