#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击按钮 选择文件
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString filePath = QFileDialog::getOpenFileName(this, "选择文件", "C:/Users/lfish/Desktop", "(*.txt)");
//        qDebug() << filePath;

        // 如果不选择文件
        if (filePath.isEmpty()){
            QMessageBox::warning(this, "打开失败", "未选择文件");
            return;
        }

        ui->lineEdit->setText(filePath);


        // 读文件
        // 将文件内容放入textedit
        QFile file(filePath); // 默认支持格式utf-8
        // 设置打开方式 记得关闭文件对象
        file.open(QIODevice::ReadOnly); // 只读方式

        QByteArray arr;
//        arr = file.readAll(); // 读文件 全部读取
        // 按行读取
        while (!file.atEnd()) {
            arr += file.readLine();
        }

        // 显示
        // 设置一个gbk的编码对象
//        QTextCodec *codec = QTextCodec::codecForName("gbk");
//        ui->textEdit->setText(codec->toUnicode(arr)); // 将gbk解码为unicode
        ui->textEdit->setText(arr); // 做了隐式类型转换

        // 关闭文件对象
        file.close();


//        // 写文件
//        file.open(QIODevice::Append); // 追加方式写入
//        file.write("飘柔洗发水");
//        file.close();


        // 文件信息类
        QFileInfo info(filePath);
        qDebug() << "\n大小：\n" << info.size() << "\n后缀名：\n" << info.suffix() << "\n文件名：\n" << info.fileName() << "\n路径：\n" << info.filePath();
        qDebug() << "\n创建日期：\n" << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "\n最后修改日期：\n" << info.lastModified().toString(("yyyy-MM-dd hh:mm:ss"));

    });
}

Widget::~Widget()
{
    delete ui;
}
