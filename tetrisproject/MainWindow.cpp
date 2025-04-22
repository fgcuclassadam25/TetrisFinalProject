#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    stack = new QStackedWidget(this);
    setupMainMenu();
    setupGameOverScreen();

    game = new TetrisGame();
    connect(game, &TetrisGame::gameOver, this, &MainWindow::handleGameOver);

    stack->addWidget(mainMenu);
    stack->addWidget(game);
    stack->addWidget(gameOverScreen);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stack);
    setLayout(layout);
    resize(300, 600);

    stack->setCurrentWidget(mainMenu);
}

void MainWindow::setupMainMenu() {
    mainMenu = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainMenu);

    QLabel *title = new QLabel("Tetris Game");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; color: white;");

    playButton = new QPushButton("Play");
    layout->addWidget(title);
    layout->addWidget(playButton);
    layout->setAlignment(Qt::AlignCenter);

    mainMenu->setLayout(layout);
    mainMenu->setStyleSheet("background-color: black; color: white;");

    connect(playButton, &QPushButton::clicked, this, &MainWindow::startGame);
}

void MainWindow::setupGameOverScreen() {
    gameOverScreen = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(gameOverScreen);

    QLabel *gameOverLabel = new QLabel("Game Over");
    gameOverLabel->setAlignment(Qt::AlignCenter);
    gameOverLabel->setStyleSheet("font-size: 24px; color: white;");

    replayButton = new QPushButton("Replay");
    menuButton = new QPushButton("Main Menu");

    layout->addWidget(gameOverLabel);
    layout->addWidget(replayButton);
    layout->addWidget(menuButton);
    layout->setAlignment(Qt::AlignCenter);

    gameOverScreen->setLayout(layout);
    gameOverScreen->setStyleSheet("background-color: black; color: white;");

    connect(replayButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(menuButton, &QPushButton::clicked, this, &MainWindow::showMainMenu);
}

void MainWindow::startGame() {
    delete game;
    game = new TetrisGame();
    connect(game, &TetrisGame::gameOver, this, &MainWindow::handleGameOver);
    stack->addWidget(game);
    stack->setCurrentWidget(game);
}

void MainWindow::handleGameOver() {
    stack->setCurrentWidget(gameOverScreen);
}

void MainWindow::showMainMenu() {
    stack->setCurrentWidget(mainMenu);
}
