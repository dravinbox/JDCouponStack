#include "colorbll.h"
#include <QtDebug>

ColorBLL::ColorBLL(QObject *parent) : QObject(parent)
{
    for(int i=0;i<3;i++){
           data.append(new ColorModel("white","#FF32FF"));
       }
}

QList<QObject*> ColorBLL::getModel(){
    return data;
}

void ColorBLL::appendColor(QString name,QString color){
    //todo 添加新的colorModel 数据进去，就无法更新页面，可以参考一下url
    //https://blog.csdn.net/r5014/article/details/71159279
    qDebug()<<name;
    data.append(new ColorModel(name,color));
}
