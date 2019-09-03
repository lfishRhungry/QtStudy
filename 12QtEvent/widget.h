#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写定时器事件
    void timerEvent(QTimerEvent *);
    // 声明两个定时器标识符
    int id1;
    int id2;
    // 重写事件过滤器
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
