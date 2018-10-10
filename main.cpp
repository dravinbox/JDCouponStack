#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "user.h"
#include "colorbll.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<User>("UserModel", 1, 0, "User");
    qmlRegisterType<ColorBLL>("ColorBLL", 1, 0, "ColorBLL");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
