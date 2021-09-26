#ifndef QTLIBFUNCCHECKBOX_H
#define QTLIBFUNCCHECKBOX_H

#include <QObject>
#include "qtlibfuncbase.h"

namespace QtFSD {

class QtLibFuncCheckBox : public QtLibFuncBase
{
    Q_OBJECT
public:
    explicit QtLibFuncCheckBox(QObject *parent = nullptr);
    virtual ~QtLibFuncCheckBox();

signals:

public slots:

protected:

};

}

Q_DECLARE_INTERFACE(QtFSD::QtLibFuncCheckBox, "Qt.Lib.Func.CheckBox");

#endif // QTLIBFUNCCHECKBOX_H
