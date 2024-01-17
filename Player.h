#pragma once
#include <QDebug>

// 玩家类
class Player
{
public:
    // 构造函数，初始化
    Player(int id) : id(id), wins(0), losses(0) {}

    void win() {
        wins++;
    }

    void lose() {
        losses++;
    }

    void clear() {
        losses = 0;
        wins = 0;
    }

    void displayStats() const {
        qDebug() << "Player " << id << ": Wins -- " << wins << ", Losses -- " << losses;
    }

    int getID() const {
        return id;
    }
    int getWins() const {
        return wins;
    }
    int getLosses() const {
        return losses;
    }


private:
    // 成员属性：玩家ID，单次获胜次数，单次失败次数，总获胜次数，总失败次数
    int id;
    int wins;
    int losses;
};
