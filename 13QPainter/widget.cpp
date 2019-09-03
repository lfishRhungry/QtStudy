#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 实现按钮移动图片
    posX = 10;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        // 手动调用绘图事件使用update最好
        update();
        // 增量放在这里 不要放在绘图事件函数中 因为绘图事件由系统调用 不知道调用多少次
        posX += 20;
    });
}

// 重写绘图事件函数
// 绘图事件是由系统自动调用的
void Widget::paintEvent(QPaintEvent *){
    // 声明一个画家对象
    QPainter painter(this);

    // 超出屏幕宽度自动归位
    if (posX >= this->width())
        posX = 10;
    // 利用画家绘制图片
    painter.drawPixmap(posX, 100, QPixmap(":/moneyIcon.jpeg"));

//    // 画圆
//    painter.drawEllipse(QPoint(100, 100), 50, 50);
//    // 设置抗锯齿能力 效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(250, 100), 50, 50);

//    // 画矩形
//    painter.drawRect(QRect(20, 20, 50, 50));
//    // 移动画家的基准点
//    painter.translate(QPoint(100, 0));
//    painter.save(); // 保存位置
//    painter.drawRect(QRect(20, 20, 50, 50));
//    painter.translate(QPoint(100, 0));
//    painter.restore(); // 还原位置
//    painter.drawRect(QRect(20, 20, 50, 50));

//    // 声明画笔
//    QPen pen(QColor(255, 0, 0));
//    // 设置画笔宽度
//    pen.setWidth(3);
//    // 设置画笔风格
//    pen.setStyle(Qt::DotLine);
//    // 给画家对象
//    painter.setPen(pen);

//    // 声明画刷 给painter对象
//    QBrush brush(Qt::cyan);
//    brush.setStyle(Qt::Dense6Pattern); // 设置画刷风格
//    painter.setBrush(brush);

//    // 画直线
//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
//    // 画圆
//    painter.drawEllipse(QPoint(100, 100), 50, 50);
//    // 画矩形
//    painter.drawRect(QRect(20, 20, 50, 50));
//    // 画文字
//    painter.drawText(QRect(20, 200, 100, 100), "三鹿奶粉，海天酱油");
}

Widget::~Widget()
{
    delete ui;
}
