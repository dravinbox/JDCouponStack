#include "colormodel.h"

ColorModel::ColorModel(QString name,QString color,QObject *parent)
{
    m_name = name;
    m_color = color;
}

QString ColorModel::name(){
    return m_name;
}

void ColorModel::setName(QString name){
    if(name != m_name) {
       m_name = name;
       emit nameChanged();
    }
}


QString ColorModel::color(){
    return m_color;
}

void ColorModel::setColor(QString color){
    if(color != m_color) {
       m_color = color;
       emit colorChanged();
    }
}

