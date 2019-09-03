#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug() << "请吃饭";
}

void Student::treat(QString foodName){
    // 输出时最好将QString做类型转换
    // toUtf8转换为QByteArray 然后再使用data转换为char*
    qDebug() << "请吃：" << foodName.toUtf8().data();
}
