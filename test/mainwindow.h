#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showToolTip();
};

class GBQToolTipper : public QObject
{
    Q_OBJECT
public:
    explicit GBQToolTipper(QObject *parent = 0);

    virtual bool eventFilter(QObject *obj, QEvent *event);

protected:
    bool headerViewEventFilter(QObject *obj, QEvent *event);
};
#endif // MAINWINDOW_H
