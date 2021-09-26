#ifndef QTPLUGINMANAGER_H
#define QTPLUGINMANAGER_H

#include <QtCore>

namespace QtFSD {

class QtPluginManager
{
public:
    QtPluginManager();
    ~QtPluginManager();

    // 初始化插件管理
    void initManger(const QString& pluginDir);
};

}

#endif // QTPLUGINMANAGER_H
