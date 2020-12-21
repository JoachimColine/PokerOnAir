#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Game.h>

class PokerOnAirWindow : public QMainWindow
{
    Q_OBJECT

public:
    PokerOnAirWindow(QWidget *parent = nullptr);
    ~PokerOnAirWindow();

private slots:
    void initialize();

private:
    Game* m_game;
};
#endif // MAINWINDOW_H
