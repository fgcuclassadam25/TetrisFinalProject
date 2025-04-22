#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "TetrisGame.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void startGame();
    void showMainMenu();
    void handleGameOver();

private:
    QStackedWidget *stack;
    QWidget *mainMenu;
    TetrisGame *game;
    QWidget *gameOverScreen;

    QPushButton *playButton;
    QPushButton *replayButton;
    QPushButton *menuButton;

    void setupMainMenu();
    void setupGameOverScreen();
};

#endif // MAINWINDOW_H
