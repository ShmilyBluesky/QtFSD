#include "qtpluginmanager.h"
#include "qtinstance.h"
#include "QtLibCheckBox/include/qtlibfunccheckbox.h"
#include <QApplication>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

QtFSD::QtPluginManager::QtPluginManager()
{

}

QtFSD::QtPluginManager::~QtPluginManager()
{

}

void QtFSD::QtPluginManager::initManger(const QString &pluginDir)
{
    //设置要遍历的目录
    QDir dir(pluginDir);

    //设置文件过滤器
    QStringList nameFilters;
    nameFilters << "*.dll";

    //将过滤后的文件名称存入到files列表中
    QFileInfoList listFileInfo = dir.entryInfoList(nameFilters, QDir::Files, QDir::Name);
    for (int i=0; i<listFileInfo.size(); i++)
    {
        QString strFilePath = listFileInfo.at(i).filePath();

        QString strPluginName("");
        bool bFlag = false;
        QPluginLoader *pLoader = new QPluginLoader(strFilePath);
        QObject *pObj = pLoader->instance();

        // QtLibFuncCheckBox
        if (! bFlag && nullptr != pObj)
        {
            QtFSD::QtLibFuncCheckBox *pInterface = qobject_cast<QtFSD::QtLibFuncCheckBox*>(pObj);
            if (nullptr != pInterface)
            {
                strPluginName = pInterface->f_getPluginName();
                pInterface->f_initialize(pluginDir);
                QtFSD::QtInstance<QtFSD::QtLibFuncCheckBox*>::instance()->setObj(pInterface);
                bFlag = true;
            }
        }

        if (bFlag)
        {
            qDebug() << QString("Info[QtPluginManager]: Load plugin(%1) success! path: ").arg(strPluginName) << strFilePath;
        }
        else
        {
            qDebug() << "Info[QtPluginManager]: Load plugin failed! path: " << strFilePath;
            pLoader->deleteLater();
            pLoader = nullptr;
        }
    }
}
