#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QString resultsText;
    QString queryText;

    Game game;
    MainWindow mainWindow;

    int numPlayers = 0;
    int rounds, opt, begin = 0;
    bool flag = true;


    while (flag) {
        opt = mainWindow.displayMenu();

        switch (opt) {
        case 1:
            resultsText.clear();
            if (begin == 0) {
                numPlayers = QInputDialog::getInt(&mainWindow, "输入", "输入游玩的人数: ", 1, 1, 100, 1);
                begin = 1;
                game.startGame(numPlayers);

                rounds = QInputDialog::getInt(&mainWindow, "输入", "请输入需要游玩的轮次: ", 1, 1, 100, 1);
            }

            for (int i = 0; i < rounds; ++i) {
                game.playRound();
            }

            game.displayCurrentStats();
            game.displayAllStats();

            for (const Player& player : game.getPlayers()) {
                resultsText += "Player ID: " + QString::number(player.getID()) +
                               "\nWins: " + QString::number(player.getWins()) +
                               "\nLosses: " + QString::number(player.getLosses()) + "\n\n";
            }

            QMessageBox::information(&mainWindow, "结果", resultsText);


            break;

        case 2:
            if (numPlayers == 0) {
                QMessageBox::information(&mainWindow, "提示", "不存在历史战绩，请先开始游戏");
            } else {
                queryText.clear();
                for (const Player& player : game.getPlayers()) {
                    queryText += "Player ID: " + QString::number(player.getID()) +
                                   "\nWins: " + QString::number(player.getWins()) +
                                   "\nLosses: " + QString::number(player.getLosses()) + "\n\n";
                }
                QMessageBox::information(&mainWindow, "结果", queryText);
                game.displayAllStats();
            }
            break;

        case 3:
            game.resetGame();
            begin = 0;
            rounds = 0;
            break;

        case 4:
            QApplication::quit(); // 退出程序
            flag = false;
            break;
        defalut:
            QApplication::quit(); // 退出程序
            flag = false;
            break;


        }

    }

    return 0;
}

