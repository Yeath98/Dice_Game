// 在Game类的实现文件中
#include "Game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::startGame(int NumPlayers) {
    srand(static_cast<unsigned>(time(0)));
    numPlayers = NumPlayers;
    for (int i = 0; i < NumPlayers; ++i) {
        Player player(i + 1);
        Player score(i + 1);
        roundscores.push_back(score);
        players.push_back(player);
    }
}

// void Game::playRound() {
//     QVector<int> results(numPlayers);
//     qDebug() << "当前结果";
//     for (int i = 0; i < numPlayers; ++i) {
//         results[i] = rollDice();
//         qDebug() << "Player " << i + 1 << ": " << results[i] << "  ";
//     }
//     int maxScore = *std::max_element(results.begin(), results.end());
//     for (int i = 0; i < numPlayers; ++i) {
//         if (results[i] == maxScore) {
//             players[i].win();
//             roundscores[i].win();
//         } else {
//             players[i].lose();
//             roundscores[i].lose();
//         }
//     }
// }
void Game::playRound() {
    QVector<int> results(numPlayers);
    QString roundResultsText = "当前结果:\n";

    for (int i = 0; i < numPlayers; ++i) {
        results[i] = rollDice();
        roundResultsText += "Player " + QString::number(i + 1) + ": " + QString::number(results[i]) + "\n";
    }

    int maxScore = *std::max_element(results.begin(), results.end());

    for (int i = 0; i < numPlayers; ++i) {
        if (results[i] == maxScore) {
            players[i].win();
            roundscores[i].win();
        } else {
            players[i].lose();
            roundscores[i].lose();
        }
    }

    QMessageBox::information(nullptr, "轮次结果", roundResultsText);
}


void Game::displayAllStats() {
    for (Player player : players) {
        qDebug() << "=====================总成绩=====================";
        player.displayStats();
    }
}

void Game::displayCurrentStats() {
    for (int i = 0; i < numPlayers; ++i) {
        roundscores[i].displayStats();
        roundscores[i].clear();
    }
}

int Game::rollDice() {
    return rand() % 6 + 1 + rand() % 6 + 1;
}
