#ifndef QTINSTANCE_H
#define QTINSTANCE_H

#include <QDebug>
#include <QDateTime>

namespace QtFSD {

template<typename Obj>
class QtInstance
{
protected:
    explicit QtInstance() :
        m_bInited(false),
        m_strInstanceName("")
    {
    }

public:
    ~QtInstance()
    {
    }

    // 单例对象
    static QtInstance *instance()
    {
        static QtInstance *pInstance = nullptr;
        if (nullptr == pInstance)
            pInstance = new QtInstance();
        return pInstance;
    }

    // 保存
    void setObj(Obj obj, const QString& strInstanceName = QString(""))
    {
        m_obj = obj;
        m_strInstanceName = strInstanceName;

        m_bInited = true;

        qDebug() << QString("Info[QtInstance]: this instance(0x%1: %2) is initialized at %3!").
                    arg(QString::number((int)this, 16)).arg(m_strInstanceName).
                    arg(QDateTime::currentDateTime().toString());
    }

    // 获取
    Obj getObj()
    {
        if (!m_bInited)
        {
            qDebug() << QString("Error[QtInstance]: this instance(0x%1: %2) do not initialize!").
                        arg(QString::number((int)this, 16)).arg(m_strInstanceName);
        }

        return m_obj;
    }

private:
    Obj m_obj; // object

    bool m_bInited; // 是否初始化
    QString m_strInstanceName; // 实例名称
};

}

#endif // QTINSTANCE_H
