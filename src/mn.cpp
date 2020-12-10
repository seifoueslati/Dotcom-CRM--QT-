#include <QGuiApplication>
#include <QApplication>
#include <QQuickView>
int mn(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + QLatin1String("/Qt5_CinematicExperience.qml")));
    view.show();

}
