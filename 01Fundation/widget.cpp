#include "widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent) // 初始化列表 可以以这样调用父类函数的形式
{
    // 按键对象设置
    // QObject的子类都会自动释放
    QPushButton *btn = new QPushButton; // 按键类
    // btn->show(); // 都是QWidget的子孙类 都要show出来 默认用顶层单独方法弹出
    btn->setParent(this); // 将父窗口设置为主窗口
    btn->setText("你好"); // 显示文本 这里将文本参数隐式转换为QString
    // 再来一个button
    QPushButton *btn2 = new QPushButton("再见"); // 构造函数顺带传参
    btn2->setParent(this);
    btn2->move(200, 200); // 设置位置

    // 设置窗口大小
    this->resize(1000, 800);
    // 设置固定大小窗口
    // this->setFixedSize(600, 400);

    // 设置窗口标题
    this->setWindowTitle("第一个项目");

    // 创建自定义按钮对象
    MyPushButton *mybtn = new MyPushButton;
    mybtn->setText("自定义关闭按钮");
    mybtn->move(200, 0);
    mybtn->setParent(this); // 其实是将对象放在了QObject对象树上 不用自己释放

    // 点击自定义关闭按钮实现窗口关闭
    // 参数：信号发送者指针 信号地址 接受者指针 槽函数地址
    connect(mybtn, &MyPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    qDebug() << "Widget析构调用" << endl; // 执行完这里后Widget并没有被析构完成 而是继续检查其子对象
}
