#ifndef QTLIBFUNCCHECKBOX_H
#define QTLIBFUNCCHECKBOX_H

#include <QObject>

class QApplication;
class QWidget;

namespace QtFSD {

class QtLibFuncCheckBox : public QObject
{
    Q_OBJECT
public:
    explicit QtLibFuncCheckBox(QObject *parent = nullptr);
    virtual ~QtLibFuncCheckBox();

    // 属性
    virtual QString f_getPluginName() = 0;

    // 初始化
    virtual bool f_initialize(const QString& pluginPath) = 0;

    // 样式风格
    virtual QString f_getStyleSheet() = 0;
    virtual void f_setStyleSheet(QApplication *pApp) = 0;
    virtual void f_setStyleSheet(QWidget *pWnd) = 0;

signals:

public slots:

protected:
    QString m_strPluginPath; // 插件路径
};

}

Q_DECLARE_INTERFACE(QtFSD::QtLibFuncCheckBox, "Qt.Lib.Func.CheckBox");

#endif // QTLIBFUNCCHECKBOX_H
