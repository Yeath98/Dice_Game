#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include "Player.h"

class Game : public QObject {
    Q_OBJECT
public:
    Game();
    ~Game();

    void startGame(int numPlayers);
    void playRound();

    void displayAllStats();
    void displayCurrentStats();



    const QVector<Player>& getPlayers() const {
        return players;
    }

    void resetGame() {
        numPlayers = 0;
        players.clear();
        roundscores.clear();
    }


private:
    int rollDice();
    int numPlayers;
    QVector<Player> players;
    QVector<Player> roundscores;
};

#endif // GAME_H
