#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "qtinstance.h"
#include <QDebug>

// 自定义数据结构
struct CustomData
{
    int iValue;

    CustomData(int i = 0) :
        iValue(i)
    {
    }
};

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    qDebug() << "11111111" << QString::number((int)this, 16);

    QtFSD::QtInstance<QString>::instance()->setObj("abc", "QString");

    QtFSD::QtInstance<int>::instance()->setObj(123, "int");

    QtFSD::QtInstance<CustomData>::instance()->setObj(CustomData(222), "CustomData");

    QtFSD::QtInstance<CustomData*>::instance()->setObj(new CustomData(333), "CustomData*");

    qDebug() << "QString: " << QtFSD::QtInstance<QString>::instance()->getObj();

    qDebug() << "int: " << QtFSD::QtInstance<int>::instance()->getObj();

    qDebug() << "CustomData: " << QtFSD::QtInstance<CustomData>::instance()->getObj().iValue;

    qDebug() << "CustomData*: " << QtFSD::QtInstance<CustomData*>::instance()->getObj()->iValue;
}

MainWidget::~MainWidget()
{
    delete ui;
}
