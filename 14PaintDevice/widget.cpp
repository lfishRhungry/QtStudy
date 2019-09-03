#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QPixmap做绘图设备
    // 对不同平台做了优化
//    QPixmap pix(300, 300);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    pix.save("C:/Users/lfish/Desktop/test.png"); // 保存

    // QImage做绘图设备
    // 可以对像素进行访问
//    QImage img(300, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    img.save("C:/Users/lfish/Desktop/test1.png"); // 保存

    // QPicture可以重现QPainter的各种指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(Qt::blue);
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    // 保存为任意后缀名均可 因为只是绘图命令 不是图片
    pic.save("C:/Users/lfish/Desktop/test.xx");
}

// 重写绘图事件函数
void Widget::paintEvent(QPaintEvent *){
//    QImage img;
//    img.load(":/moneyIcon.jpeg");
//    QPainter painter(this);

//    // 访问像素
//    for (int i = 50; i < 100; i++){
//        for (int j = 50; j < 100; j++){
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }

//    painter.drawImage(0, 0, img);

    // 重现QPicture绘图命令
    QPicture pic;
    pic.load("C:/Users/lfish/Desktop/test.xx");
    QPainter painter(this);
    painter.drawPicture(0, 0, pic);

}

Widget::~Widget()
{
    delete ui;
}
