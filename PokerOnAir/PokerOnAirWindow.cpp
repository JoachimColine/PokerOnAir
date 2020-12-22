#include "PokerOnAirWindow.h"

PokerOnAirWindow::PokerOnAirWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initialize();
}

PokerOnAirWindow::~PokerOnAirWindow()
{

}

void PokerOnAirWindow::initialize()
{
    m_game = new Game(this);
}
