#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "qtlibfunccheckbox.h"
#include <QPluginLoader>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    QPluginLoader *pLoader = new QPluginLoader(QApplication::applicationDirPath() + "/plugin/QtLibCheckBox.dll");
    QObject *pObj = pLoader->instance();
    if (nullptr != pObj)
    {
        QtFSD::QtLibFuncCheckBox *pInterface = qobject_cast<QtFSD::QtLibFuncCheckBox*>(pObj);
        if (nullptr != pInterface)
        {
            pInterface->f_initialize(QApplication::applicationDirPath() + "/plugin");
            pInterface->f_setStyleSheet(ui->checkBox);

            qDebug() << pInterface->f_getStyleSheet();
        }
    }
}

MainWidget::~MainWidget()
{
    delete ui;
}
