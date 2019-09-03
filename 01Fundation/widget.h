#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT // 消息循环机制全靠它

public:
    Widget(QWidget *parent = 0); // 默认参数
    ~Widget();
};

#endif // WIDGET_H
