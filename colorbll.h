#ifndef COLORBLL_H
#define COLORBLL_H

#include <QObject>
#include "colormodel.h"

class ColorBLL : public QObject
{
    Q_OBJECT
public:
    explicit ColorBLL(QObject *parent = nullptr);
    Q_INVOKABLE QList<QObject*> getModel();
    Q_INVOKABLE void appendColor(QString name,QString color);

//signals:

//public slots:
private:
    QList<QObject*> data;

};

#endif // COLORBLL_H
