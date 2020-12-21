#include "Game.h"
#include "OMPEval/test.cpp"

using namespace std;
using namespace omp;


Game::Game()
    : QObject()
{

}

Game::~Game()
{
	
}

void Game::initialize()
{
    m_table = new Table();
}

void Game::doOMPEvalTests()
{
    printBuildInfo();
    cout << endl << "=== Tests ===" << endl;
    cout << "Util:" << endl;
    UtilTest().run();
    cout << "Hand:" << endl;
    HandTest().run();
    cout << "HandEvaluator:" << endl;
    HandEvaluatorTest().run();
    cout << "EquityCalculator:" << endl;
    EquityCalculatorTest().run();
}

Table::Table(int n_players)
{
    initialize(n_players);
}

Table::~Table()
{

}

void Table::initialize(int n_players)
{
    if (!m_players.isEmpty()) m_players.clear();
    for (int i=0; i<n_players; i++) {
        m_players.append(new Player());
    }
    m_deck = new Deck();
}

Player::Player()
{

}

Player::~Player()
{
    initialize();
}

void Player::initialize()
{
    if (!m_hand.isEmpty()) m_hand.clear();
}

Deck::Deck()
{

}

Deck::~Deck()
{

}

void Deck::initialize()
{

}

void Deck::deal(QList<Player *> players)
{

}

void Deck::gather(QList<Player *> players)
{

}
