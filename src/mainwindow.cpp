#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/image/picture1.jpeg"));
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

