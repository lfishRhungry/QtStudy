#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1500, 1000);

    // 菜单栏
    // 菜单栏只有一个
    QMenuBar *bar = menuBar();
    // 将菜单栏设置到主窗口
    this->setMenuBar(bar);
    // 添加菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    // 添加菜单项
    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator(); // 添加分割线
    QAction *openAction = fileMenu->addAction("打开");

    // 工具栏
    // 可以有多个工具栏
    QToolBar *toolBar = new QToolBar(this);
    // 添加到主窗口 Qt冒号一般是枚举值 设置默认停靠位置
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    // 设置允许停靠位置
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 禁止浮动
    toolBar->setFloatable(false);
    // 工具栏添加控件
    QPushButton *btn = new QPushButton("按钮", this);
    toolBar->addWidget(btn);
    toolBar->addSeparator(); // 添加分割线
    // 工具栏中添加菜单项
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);

    // 状态栏
    // 注意观察菜单、工具栏、状态栏的创建方式以及与主窗口结合方式 都是通用可以替代的
    QStatusBar *status = statusBar();
    status->setParent(this);
    // 添加标签控件
    QLabel *label = new QLabel("左侧信息", this); // 加入对象树
    // 放入状态栏
    status->addWidget(label);
    // 添加标签控件
    QLabel *label2 = new QLabel("右侧信息", this);
    status->addPermanentWidget(label2);

    // 铆接部件 浮动窗口
    QDockWidget *dock = new QDockWidget("铆接部件", this);
    this->addDockWidget(Qt::BottomDockWidgetArea, dock); // 默认打开位置
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);

    // 核心部件 只能有一个
    QTextEdit *edit = new QTextEdit(this);
    this->setCentralWidget(edit); // 添加核心部件
}

MainWindow::~MainWindow()
{

}
