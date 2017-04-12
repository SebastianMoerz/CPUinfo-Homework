#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include "cpuinforeader.h"
#include <QQmlContext>
#include <QtCore>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // create instance of CPUinfoReader-Class
    CPUinfoReader cpureader;

    // link CPUinfoReader-Instance to QML
    engine.rootContext()->setContextProperty("cpureader", &cpureader);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QList<QObject*> rootObjList = engine.rootObjects();;
    QObject* viewerobject = rootObjList.first();


    return app.exec();
}





CPUinfoReader::CPUinfoReader()
{
}

CPUinfoReader::~CPUinfoReader()
{
}
