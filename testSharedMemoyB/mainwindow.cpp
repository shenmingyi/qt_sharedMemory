#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ = new QSharedMemory();
    this->setWindowTitle("共享内存读取");

    m_->setKey("smy");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    m_->lock();

    if(!m_->attach())
    {
        qDebug()<<"attach error!";
        return;
    }

    char*d;
    d = (char *)m_->constData();

    qDebug()<<d;

    m_->unlock();

    m_->detach();
}

