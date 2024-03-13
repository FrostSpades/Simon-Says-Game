#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QTimer>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model()
{
    ui->setupUi(this);
    disableGameButtons();
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");

    //connect(&model, &Model::signal, this, &MainWindow::disableGameButtons);
    //connect(&model, &Model::createdSequence, this, &MainWindow::showSequence);
    connect(this, &MainWindow::startButtonPressed, &model, &Model::start);
    connect(this, &MainWindow::buttonLightingComplete, &model, &Model::lightNextButton);
    //connect(&model, &Model::)
    connect(&model, &Model::lightUpButton, this, &MainWindow::glowButton);
    connect(&model, &Model::playersTurn, this, &MainWindow::enableGameButtons);
    connect(this, &MainWindow::playerSelectionComplete, &model, &Model::validatePlayerMove);
    connect(&model, &Model::turnOffButtons, this, &MainWindow::disableGameButtons);
    connect(&model, &Model::gameOver, this, &MainWindow::gameOver);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableGameButtons() {
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
}

void MainWindow::disableGameButtons() {
    ui->redButton->setEnabled(false);
    ui->blueButton->setEnabled(false);
}

void MainWindow::glowButton(int buttonID, int timeToBeLit) {
    if (buttonID == 0) {
        ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
        QTimer::singleShot(timeToBeLit, this, [=](){resetColors();});
    }
    else {
        ui->blueButton->setStyleSheet("background-color: rgb(50,50,200);");
        QTimer::singleShot(timeToBeLit, this, [=](){resetColors();});
    }
}

void MainWindow::gameOver()
{
    disableGameButtons();
    ui->redButton->setStyleSheet("background-color: rgb(0,0,0);");
}

void MainWindow::resetColors() {
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
    // tell model colors have been reset

    // TODO: make this time scale properly
    QTimer::singleShot(300, this, [=](){emit buttonLightingComplete();});
}

void MainWindow::on_redButton_clicked()
{
    resetColors();
    glowButton(0, 300);
    emit playerSelectionComplete(0);
}


void MainWindow::on_blueButton_clicked()
{
    resetColors();
    glowButton(1, 300);
    emit playerSelectionComplete(1);
}


void MainWindow::on_startButton_clicked()
{
    model.start();
}

