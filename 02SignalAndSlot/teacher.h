#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

// 自定义信号
signals:
    // 自定义信号有固定限制：返回void 只需声明 不需要实现 自定义信号可以重载
    void hungry();
    void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
