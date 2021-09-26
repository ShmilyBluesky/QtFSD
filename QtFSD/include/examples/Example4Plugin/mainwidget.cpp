#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "qtpluginmanager.h"
#include "qtinstance.h"
#include "qtlibfunccheckbox.h"
#include <QApplication>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    const QString strPluginDir("plugin");
    const QString strQssFileName("style1.qss");
    QtFSD::QtPluginManager pluginMgr;
    pluginMgr.initManger(QApplication::applicationDirPath() + "/" + strPluginDir);
    if (QtFSD::QtInstance<QtFSD::QtLibFuncCheckBox*>::instance()->isInited())
    {
        QtFSD::QtLibFuncCheckBox* pCheckBox = QtFSD::QtInstance<QtFSD::QtLibFuncCheckBox*>::instance()->getObj();
        pCheckBox->f_setStyleSheet(ui->checkBox, strQssFileName);
        qDebug() << pCheckBox->f_getStyleSheet(strQssFileName);
    }
}

MainWidget::~MainWidget()
{
    delete ui;
}
