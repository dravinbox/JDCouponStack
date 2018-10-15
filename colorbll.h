#ifndef COLORBLL_H
#define COLORBLL_H

#include <QObject>
#include "colormodel.h"

class ColorBLL : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> data READ data WRITE setData NOTIFY dataChanged)
public:
    explicit ColorBLL(QObject *parent = nullptr);
    Q_INVOKABLE QList<QObject*> getModel();
    Q_INVOKABLE void appendColor(QString name,QString color);
    Q_INVOKABLE void removeColor();

    QList<QObject*> data();
    void setData(QList<QObject*> data);

signals:
    void dataChanged();

//public slots:
private:
    QList<QObject*> m_data;

};

#endif // COLORBLL_H
