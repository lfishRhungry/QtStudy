#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置为鼠标追踪模式 鼠标不按下时也可以捕获移动事件
//    this->setMouseTracking(true);
}
    // 重写鼠标进入
void MyLabel::enterEvent(QEvent *){
//    qDebug() << "鼠标进入";
}

    // 重写鼠标离开
void MyLabel::leaveEvent(QEvent *){
//    qDebug() << "鼠标离开";
}

    // 重写几个鼠标事件函数
void MyLabel::mousePressEvent(QMouseEvent *ev){
    // 做到只有鼠标左键按下才有反应
    if(ev->button() == Qt::LeftButton){
        // qt下格式化字符串
        QString str = QString("鼠标按下 x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    // 做到只有鼠标左键按下才有反应
    if(ev->button() == Qt::LeftButton){
        qDebug() << "鼠标释放";
    }
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    // 使用联合按键的位运算来判断持续动作的鼠标按键
    if(ev->buttons() & Qt::LeftButton){
        // 鼠标移动的事件 默认是鼠标按下之后移动
        QString str = QString("鼠标位置 x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

    // 重写事件分发器函数 在事件被分发出去之前拦截
bool MyLabel::event(QEvent *ev){
    // 由于需要鼠标按下事件的一些参数 需要对qevent向下造型
    // 这是造型方式的一种
    QMouseEvent *mev = static_cast<QMouseEvent *>(ev);
    if (ev->type() == QEvent::MouseButtonPress){
        QString str = QString("坐标 x = %1 y = %2").arg(mev->x()).arg(mev->y());
        qDebug() << "鼠标按下event被处理" << str;
        return true;
    }
    // 由于事件分发器统一处理所有事件 对于非用户处理的事件 交给分类处理
    return QLabel::event(ev);
}
