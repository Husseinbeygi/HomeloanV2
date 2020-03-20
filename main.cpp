#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <sqlite.h>
#include <QList>
#include <QString>
#include <viewmanager.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    ViewManager vm;
    auto root_context = engine.rootContext();
    root_context->setContextProperty("ViewManager",&vm);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
