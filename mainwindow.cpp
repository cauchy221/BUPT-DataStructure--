#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //确定应用程序界面大小
    this->setFixedSize(QSize(width_l, height_l));
}

MainWindow::~MainWindow()
{
    delete ui;
}

