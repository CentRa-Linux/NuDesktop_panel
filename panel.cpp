#include "panel.h"

panel::panel() {}

int panel::create(int width, QString name,
                  QQmlApplicationEngine *applicationEngine,
                  QGuiApplication *app) {
  QQmlEngine engine;
  const QUrl url(QStringLiteral("qrc:/panel.qml"));
  QQmlComponent panelComponent(&engine, url, QQmlComponent::PreferSynchronous);
  panel::panelWindow = dynamic_cast<QQuickWindow *>(panelComponent.create());
  panel::panelWindow->setParent(
      dynamic_cast<QQuickWindow *>(applicationEngine->rootObjects().first()));

  panel::panelWindow->setProperty("settingwidth", width);
  panel::panelWindow->setFlags(
      Qt::X11BypassWindowManagerHint | Qt::CustomizeWindowHint |
      Qt::WindowDoesNotAcceptFocus | Qt::WindowStaysOnTopHint);
  panel::panelWindow->raise();

  KWindowSystem::setStrut(panel::panelWindow->winId(), 0, 0, 0,
                          panel::panelWindow->height());
  KWindowSystem::setOnAllDesktops(panel::panelWindow->winId(), true);
  KWindowSystem::setType(panel::panelWindow->winId(), NET::Dock);
  KWindowSystem::setState(panel::panelWindow->winId(), NET::SkipTaskbar |
                                                           NET::SkipPager |
                                                           NET::SkipSwitcher);
  KWindowEffects::enableBlurBehind(panel::panelWindow);
  qDebug() << panel::panelWindow->winId();
  return 0;
}
