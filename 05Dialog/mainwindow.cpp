#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000, 800);

    // 点击新建 弹出对话框
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 模态对话框
        QDialog dlg(this);
        dlg.resize(500, 500);
        dlg.exec(); // 带有阻塞功能
    });

    connect(ui->actionopen, &QAction::triggered, this, [=](){
        // 非模态对话框
        // 必须在堆上建立，不然由于异步原因 对象随着slot函数执行完毕而销毁
        QDialog *dlg2 = new QDialog(this);
        dlg2->resize(500, 500);
        dlg2->show(); // 区别所在
        dlg2->setAttribute(Qt::WA_DeleteOnClose); // 55号属性 避免在主程序退出之前内存泄漏
    });

    // 弹出QMessage对话框 是模态对话框
    connect(ui->actionsave, &QAction::triggered, this, [=](){
    // 错误提示类型
//        QMessageBox::critical(this, "错误", "critical");
    // 信息类型
//        QMessageBox::information(this, "信息", "infomation");
        // 提问类型 参数4是按键类型 参数5是默认选中按键
        if ( QMessageBox::Save == QMessageBox::question(this, "提问", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)){
            qDebug()<<"点击保存";
        }else {
            qDebug()<<"点击取消";
        }
    });

    connect(ui->actionchoose, &QAction::triggered, this, [=](){
    // 文件对话框
        // 参数：父窗口 标题 默认路径 筛选方式
//        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\lfish\\Desktop", "(*.txt)");
//        qDebug()<<"打开的文件是："<<fileName;
        // 颜色对话框 可以填入默认颜色值
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug()<<"选择的颜色是"<<color.red()<<color.green()<<color.blue();
        // 字体对话框
        bool ok;
        QFont font = QFontDialog::getFont(&ok, QFont("微软雅黑", 12));
        qDebug()<<"字体"<<font.family().toUtf8().data()<<"字号"<<font.pointSize()<<"倾斜"<<font.italic()<<"加粗"<<font.bold();


    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
