#ifndef QTLIBFUNCBASE_H
#define QTLIBFUNCBASE_H

#include <QObject>

class QApplication;
class QWidget;

namespace QtFSD {

class QtLibFuncBase : public QObject
{
    Q_OBJECT
public:
    explicit QtLibFuncBase(QObject *parent = nullptr);
    virtual ~QtLibFuncBase();

    // 属性
    virtual QString f_getPluginName() = 0;

    // 初始化
    virtual bool f_initialize(const QString& pluginPath);

    // 样式风格
    virtual QString f_getStyleSheet(const QString& qssFileName = QString("style1.qss"));
    virtual void f_setStyleSheet(QApplication *pApp, const QString& qssFileName = QString("style1.qss"));
    virtual void f_setStyleSheet(QWidget *pWnd, const QString& qssFileName = QString("style1.qss"));

signals:

public slots:

protected:
    QString m_strPluginPath; // 插件路径
};

}

#endif // QTLIBFUNCBASE_H
