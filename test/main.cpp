#include "mainwindow.h"
#include <QApplication>
#include <QProxyStyle>

class QToolTipTest : public QProxyStyle
{
public:
    QToolTipTest() : QProxyStyle()
    {}

    int styleHint(StyleHint hint, const QStyleOption *option = 0, const QWidget *widget = 0,
                  QStyleHintReturn *returnData = 0) const
    {
        switch (hint) {
            case SH_ToolTip_WakeUpDelay:
                return 10;
            case SH_ToolTip_FallAsleepDelay:
                return 0;
            default:
                return QProxyStyle::styleHint(hint, option, widget, returnData);
        }
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QToolTipTest *style = new QToolTipTest();
    QApplication::setStyle(style);

    MainWindow w;
    w.show();

    return a.exec();
}
