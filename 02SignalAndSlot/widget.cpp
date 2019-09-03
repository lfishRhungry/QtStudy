// 老师发出信号饿了 学生请客吃饭
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 创建老师和学生对象
    tch = new Teacher(this); // 初始化的同时加入对象树中 就不需要管理释放了
    stu = new Student(this);

    // 再重载的情况下 构造connect需要的槽函数与信号指针 明确使用的是什么类型的哪一个槽函数
    void (Teacher::*teacherSignal1)() = &Teacher::hungry;
    void (Teacher::*teacherSignal2)(QString) = &Teacher::hungry;
    void (Student::*studentSlot1)() = &Student::treat;
    void (Student::*studentSlot2)(QString) = &Student::treat;

    // 链接信号与槽
    connect(tch, teacherSignal1, stu, studentSlot1);
    // 有参数自定义信号和槽函数链接
    connect(tch,teacherSignal2, stu, studentSlot2);

    // 信号和槽还可以断开连接
    // disconnect(tch, teacherSignal1, stu, studentSlot1);

    // 信号还可以连接信号
    QPushButton *btn = new QPushButton(this);
    this->resize(1000, 800);
    btn->setText("下课");
    btn->move(300, 300);
    connect(btn, &QPushButton::clicked, tch, teacherSignal1);
    // 一个信号还可以连接多个信号或槽函数
    // 多个信号可以连接同一个槽函数
    // 信号和槽函数参数类型必须一一对应，但是信号参数个数可以可以多于槽函数信号参数
    // 槽函数可以不处理一些参数 但是类型必须一一对应

    // 调用触发信号的函数
    classIsOver();

    // lambda表达式
    connect(btn, &QPushButton::clicked, this, [=](){
        btn->setText("aaaa");
    });
    // lambda表达式示例
    int n = []()->int{return 1000;}();
    qDebug() << "n=" << n;
    // lambda表达式创建关闭窗口按钮
    QPushButton *btn2 = new QPushButton(this);
    btn2->setText("按钮");
    btn2->move(700, 500);
    connect(btn2, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

// 自定义信号触发函数
void Widget::classIsOver(){
    // 触发信号
    emit tch->hungry();
    emit tch->hungry("北京烤鸭");
}

Widget::~Widget()
{

}
