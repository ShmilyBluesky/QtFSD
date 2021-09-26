#include "qtlibfuncbase.h"
#include <QApplication>
#include <QCheckBox>
#include <QFile>
#include <QDebug>

QtFSD::QtLibFuncBase::QtLibFuncBase(QObject *parent) :
    QObject(parent),
    m_strPluginPath("")
{

}

QtFSD::QtLibFuncBase::~QtLibFuncBase()
{

}

bool QtFSD::QtLibFuncBase::f_initialize(const QString &pluginPath)
{
    m_strPluginPath = pluginPath;

    return true;
}

QString QtFSD::QtLibFuncBase::f_getStyleSheet(const QString &qssFileName)
{
    if (m_strPluginPath.length() <= 0)
    {
        qDebug() << QString("Error[QtLibFuncBase]: m_strPluginPath is null!");
    }

    QString strStyleSheet("");
    QString strPath = m_strPluginPath + "/" + f_getPluginName();
    QString strPathQss = strPath + "/" + qssFileName;

    QFile file(strPathQss);
    if (file.open(QIODevice::ReadOnly))
    {
        strStyleSheet = QString(file.readAll());
        file.close();
    }

    strStyleSheet = strStyleSheet.replace("$$PWD", strPath);

    return strStyleSheet;
}

void QtFSD::QtLibFuncBase::f_setStyleSheet(QApplication *pApp, const QString &qssFileName)
{
    if (pApp)
        pApp->setStyleSheet(f_getStyleSheet(qssFileName));
}

void QtFSD::QtLibFuncBase::f_setStyleSheet(QWidget *pWnd, const QString &qssFileName)
{
    if (pWnd)
        pWnd->setStyleSheet(f_getStyleSheet(qssFileName));
}
