﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写绘图事件函数
    void paintEvent(QPaintEvent *);
    int posX;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
