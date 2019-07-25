#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("共享内存创建者");

    m_ = new QSharedMemory();

    m_->setKey("smy");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(m_->isAttached())
    {
        if(!m_->detach())
            qDebug()<<"detach error";
        return;
    }

    if(m_->create(1024))//共享内存
    {

        m_->lock();

        char* d = (char*)m_->data();

        d = "hello";

        memcpy(m_->data(),d,strlen(d)*sizeof(char));

        m_->unlock();
    }
}


