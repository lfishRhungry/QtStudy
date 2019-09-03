#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    // 组合QSpinBox和QSlider控件
    // 为重载信号函数做精确指针
    void (QSpinBox:: *spinSignal)(int) = &QSpinBox::valueChanged;
    // spinbox增加 slider移动
    connect(ui->spinBox, spinSignal, ui->horizontalSlider, &QSlider::setValue);
    // slider移动 spinbox增加
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}

smallWidget::~smallWidget()
{
    delete ui;
}

// 接口实现
void smallWidget::setData(int val){
    ui->spinBox->setValue(val);
}

int smallWidget::getData(){
    return ui->spinBox->value();
}
