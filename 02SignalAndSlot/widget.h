#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "teacher.h"
#include "student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    // 将tch和stu写为类成员 方便之后的触发函数找到
    Teacher *tch;
    Student *stu;

    // 下课函数
    void classIsOver();
};

#endif // WIDGET_H
