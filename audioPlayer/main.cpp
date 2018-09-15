#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QQmlContext"
#include "datamanagementlistview.h"
#include "asyncimageprovider.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QScopedPointer<dataManagementListView> ptr(dataManagementListView::getInstance());
  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("DataManagerLV", ptr.data());
  engine.addImageProvider("loadImage", new asyncImageProvider());
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;
  return app.exec();
}
