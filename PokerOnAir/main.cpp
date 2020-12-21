#include "PokerOnAirWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokerOnAirWindow poaw;
    poaw.show();
    return a.exec();
}
