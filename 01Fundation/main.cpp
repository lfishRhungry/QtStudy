#include "widget.h" // 根据我们指定窗口类的名称创建的头文件
#include <QApplication> // 引用应用程序类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 有且仅有一个应用程序对象
    Widget w; // 窗口对象（自定义的名字）
    w.show(); // 需要show函数来展示窗口
    // 返回的同时进入消息循环机制
    return a.exec(); // 也形成了一个阻塞
}
