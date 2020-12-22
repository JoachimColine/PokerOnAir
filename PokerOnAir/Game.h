#include <QObject>

class Player : public QObject
{
    Q_OBJECT

public:
    Player();
    ~Player();

private slots:
    void initialize();

private:
    QList<int> m_hand;
};

class Deck : public QObject
{
    Q_OBJECT

public:
    Deck();
    ~Deck();

private slots:
    void initialize(QList<Player*> players);
    void deal();
    void gather();

private:
    QList<int> m_dealtCards;
    QList<Player*> m_players;
};

class Table : public QObject
{
    Q_OBJECT

public:
    Table(int n_players = 6);
    ~Table();

private slots:
    void initialize(int n_players);

private:
    Deck* m_deck;
    QList<Player*> m_players;
    QList<Player*> m_equities;
};

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void initialize();
    void doOMPEvalTests();

private:
    Table* m_table;
    QWidget* m_parent;
};

