// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::displayMenu()
{
    //cancel按钮无效，因为QInputDialog的原因
    QStringList options;
    options << "开始游戏" << "查询历史战绩" << "重置游戏" << "退出游戏";
    QString choice = QInputDialog::getItem(this, "菜单", "请选择一个操作：", options, 0, false);


    if (!choice.isEmpty()) {
        if (choice == "开始游戏") {
            emit startGameClicked();
        }
        else if (choice == "查询历史战绩") {
            emit historyClicked();
        }
        else if (choice == "重置游戏") {
            emit resetGameClicked();
        }
        else if (choice == "退出游戏") {
            emit exitGameClicked();
        }
    }
    else{
        QCoreApplication::quit(); // 用户点击了取消按钮，退出应用程序
    }

    // 返回用户的选择，你可以将不同的选择映射为整数，例如：1 表示开始游戏，2 表示查询历史战绩，以此类推。
    if (choice == "开始游戏") {
        return 1;
    } else if (choice == "查询历史战绩") {
        return 2;
    } else if (choice == "重置游戏") {
        return 3;
    } else if (choice == "退出游戏") {
        return 4;
    } else {
        // 如果用户取消选择或发生错误，可以返回一个特殊值，如 -1。
        return -1;
    }
}

