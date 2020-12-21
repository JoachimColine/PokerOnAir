#include "PokerOnAirWindow.h"
#include "OMPEval/test.cpp"

using namespace std;
using namespace omp;

PokerOnAirWindow::PokerOnAirWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

PokerOnAirWindow::~PokerOnAirWindow()
{

}

void PokerOnAirWindow::initialize()
{
    m_game = new Game();
}
