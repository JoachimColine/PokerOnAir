#include "Game.h"
#include "OMPEval/test.cpp"
#include "OMPEval/omp/EquityCalculator.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;
using namespace omp;

Game::Game(QWidget *parent)
    : QObject()
{
    m_parent = parent;
    initialize();
    doDebugTests();
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

void Game::doDebugTests()
{
    omp::EquityCalculator eq;
    std::vector<omp::CardRange> hands;
    hands.push_back("AcKc");
    hands.push_back("QcQs");
    eq.start(hands);
    eq.wait();
    auto r = eq.getResults();
    std::cout << r.equity[0] << " " << r.equity[1] << std::endl;
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
    m_deck = new Deck(m_players);
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

Deck::Deck(QList<Player *> players)
{
    initialize(players);
}

Deck::~Deck()
{

}

void Deck::initialize(QList<Player *> players)
{
    std::srand(unsigned(std::time(0)));
    m_players = players;
    m_deck.clear();
    for (int i=0; i<52; ++i) m_deck.push_back(i);
}

void Deck::shuffle()
{
    std::random_shuffle(m_deck.begin(), m_deck.end());
    m_shuffledDeck.clear();
    for (std::vector<int>::iterator it=m_deck.begin(); it!=m_deck.end(); ++it)
        m_shuffledDeck.push_back(*it);
}

void Deck::deal()
{
    if (m_players.isEmpty()) return;
    shuffle();
    foreach (Player* player, m_players) {
        QString card1 = int2Str(m_shuffledDeck.back());
        m_shuffledDeck.pop_back();
        QString card2 = int2Str(m_shuffledDeck.back());
        m_shuffledDeck.pop_back();
        player->deal(card1 + card2);
    }
}

void Deck::gather()
{
    if (m_players.isEmpty()) return;
    shuffle();
    foreach (Player* player, m_players) {
        player->deal("");
    }
}

QString Deck::int2Str(int hand)
{
    if (hand < 0 || hand > 51) return nullptr;
    QString str;
    switch (hand) {
        case 0:  str = "2s"; break;
        case 1:  str = "3s"; break;
        case 2:  str = "4s"; break;
        case 3:  str = "5s"; break;
        case 4:  str = "6s"; break;
        case 5:  str = "7s"; break;
        case 6:  str = "8s"; break;
        case 7:  str = "9s"; break;
        case 8:  str = "Ts"; break;
        case 9:  str = "Js"; break;
        case 10: str = "Qs"; break;
        case 11: str = "Ks"; break;
        case 12: str = "As"; break;
        case 13: str = "2h"; break;
        case 14: str = "3h"; break;
        case 15: str = "4h"; break;
        case 16: str = "5h"; break;
        case 17: str = "6h"; break;
        case 18: str = "7h"; break;
        case 19: str = "8h"; break;
        case 20: str = "9h"; break;
        case 21: str = "Th"; break;
        case 22: str = "Jh"; break;
        case 23: str = "Qh"; break;
        case 24: str = "Kh"; break;
        case 25: str = "Ah"; break;
        case 26: str = "2c"; break;
        case 27: str = "3c"; break;
        case 28: str = "4c"; break;
        case 29: str = "5c"; break;
        case 30: str = "6c"; break;
        case 31: str = "7c"; break;
        case 32: str = "8c"; break;
        case 33: str = "9c"; break;
        case 34: str = "Tc"; break;
        case 35: str = "Jc"; break;
        case 36: str = "Qc"; break;
        case 37: str = "Kc"; break;
        case 38: str = "Ac"; break;
        case 39: str = "2d"; break;
        case 40: str = "3d"; break;
        case 41: str = "4d"; break;
        case 42: str = "5d"; break;
        case 43: str = "6d"; break;
        case 44: str = "7d"; break;
        case 45: str = "8d"; break;
        case 46: str = "9d"; break;
        case 47: str = "Td"; break;
        case 48: str = "Jd"; break;
        case 49: str = "Qd"; break;
        case 50: str = "Kd"; break;
        case 51: str = "Ad"; break;
        default: str = nullptr;
    }
    return str;
}
