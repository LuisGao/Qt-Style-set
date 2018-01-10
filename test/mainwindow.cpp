#include "mainwindow.h"
#include <QLabel>
#include <QToolTip>
#include <QVBoxLayout>
#include <QEvent>
#include <QHelpEvent>

GBQToolTipper::GBQToolTipper(QObject *obj)
    :QObject(obj)
{

}

bool GBQToolTipper::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::ToolTip)
    {
        QHelpEvent *pHelpEvent = static_cast<QHelpEvent*>(event);

        QString sItemText = "pView->model()->data(oIndex).toString()";
        QToolTip::showText(pHelpEvent->globalPos(), sItemText);

        return false;
    }

    return false;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel *label = new QLabel;
    label->setText("11111111111111111");
    label->setToolTip("123");
    //setCentralWidget(label);

    QLabel *label2 = new QLabel;
    label2->setText("2222222222");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(label2);
    setLayout(layout);

    this->installEventFilter(new GBQToolTipper(this));
}

MainWindow::~MainWindow()
{

}

void MainWindow::showToolTip()
{
    QPoint p(100 + 20, 100 + 20);
    QToolTip::showText(p, tr("Seconds: 2"), 0, QRect(), 2000);
}
