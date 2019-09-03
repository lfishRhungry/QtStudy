#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

// 自定义槽函数，也可以写在全局函数下或pulic下或使用lambda表达式
public slots:
    // 槽函数只能返回void 需要声明 也需要实现 也可以重载
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
