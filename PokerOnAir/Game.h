#include <QObject>

class Player : public QObject
{
    Q_OBJECT

public:
    Player();
    ~Player();

    bool isActive() { return m_hand.isEmpty(); };
    std::string hand() { return m_hand.toStdString(); };
    void deal(QString hand) { m_hand = hand; };
    void fold() { m_hand.clear(); };

private slots:
    void initialize();

private:
    QString m_hand;
};

class Deck : public QObject
{
    Q_OBJECT

public:
    Deck(QList<Player*> players);
    ~Deck();

private slots:
    void initialize(QList<Player*> players);
    void shuffle();
    void deal();
    void gather();
    QString int2Str(int hand);

private:
    std::vector<int> m_deck;
    std::vector<int> m_shuffledDeck;
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
    void doDebugTests();

private:
    Table* m_table;
    QWidget* m_parent;
};

