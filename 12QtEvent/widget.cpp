#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器事件
    // 返回一个独有的定时器标识符
    id1 = startTimer(1000); // 每间隔1秒钟触发一次定时器事件
    id2 = startTimer(2000); // 每间隔2秒钟也启动一次定时器事件

    // 利用qtimer定时器类实现定时器功能
    QTimer *timer = new QTimer(this);
    timer->start(500); // 每间隔半秒钟启动一次定时器
    connect(timer, &QTimer::timeout, [=](){
        static int num3 = 0;
        ui->label_4->setText(QString::number(num3++));
    });
    // 通过按钮实现定时器对象的启动与停止
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        if (timer->isActive()){
            timer->stop();
            ui->pushButton->setText("启动");
        }else {
            timer->start();
            ui->pushButton->setText("暂停");
        }
    });

    // 通过事件过滤器 在事件分发器处理之前做更加高级的拦截
    // 给控件安装事件过滤器
    ui->label->installEventFilter(this);
    // 然后重写事件过滤器函数
}
// 重写事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *ev){
    if (obj == ui->label){
        if(ev->type() == QEvent::MouseButtonPress){
            QMouseEvent *mev = static_cast<QMouseEvent *>(ev);
            QString str = QString("由过滤器拦截鼠标按下 x = %1 y = %2").arg(mev->x()).arg(mev->y());
            qDebug() << str;
            return true; // 表示事件已经被程序员处理了
        }
    }
    // 其他情况交给父类过滤器作为默认情况处理
    return QWidget::eventFilter(obj, ev);
}

Widget::~Widget()
{
    delete ui;
}

// 重写定时器
void Widget::timerEvent(QTimerEvent *ev){
    static int num = 0;
    static int num2 = 0;
    // 对不同的计时器触发事件作出不同的响应
    if (ev->timerId() == id1)
        ui->label_2->setText(QString::number(num++));
    if (ev->timerId() == id2)
        ui->label_3->setText(QString::number(num2++));
}
