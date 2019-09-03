#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QtDebug>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 重写鼠标进入
    void enterEvent(QEvent *);
    // 重写鼠标离开
    void leaveEvent(QEvent *);

    // 重写几个鼠标事件函数
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

    // 重写事件分发器函数 在事件被分发出去之前拦截
    bool event(QEvent *);


signals:

public slots:
};

#endif // MYLABEL_H
