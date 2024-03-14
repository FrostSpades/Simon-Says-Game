/*
 * Implementation of the MainWindow class. Represents the view
 * and controller for our simon game.
 *
 * CS3505
 * @date 03/13/2024
 * @author Ethan Andrews
 * @author Vasil Vassilev
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model()
{
    // Set up the looks of the ui
    ui->setupUi(this);
    ui->gameOverScreen->setVisible(false);
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");

    disableGameButtons();
    currentColors = 0;

    // Perform view to model connections
    connect(this, &MainWindow::startButtonPressed, &model, &Model::start);
    connect(this, &MainWindow::playerSelectionComplete, &model, &Model::validatePlayerMove);

    // Perform model to view connections
    connect(&model, &Model::lightUpButton, this, &MainWindow::glowButton);
    connect(&model, &Model::playersTurn, this, &MainWindow::enableGameButtons);
    connect(&model, &Model::turnOffButtons, this, &MainWindow::disableGameButtons);
    connect(&model, &Model::disableStart, this, &MainWindow::disableStartButton);
    connect(&model, &Model::enableStart, this, &MainWindow::enableStartButton);
    connect(&model, &Model::showGameOverScreen, this, &MainWindow::enableGameOverScreen);
    connect(&model, &Model::hideGameOverScreen, this, &MainWindow::disableGameOverScreen);
    connect(&model, &Model::setStartButtonName, this, &MainWindow::changeStartButtonText);
    connect(&model, &Model::setProgressBarPercentage, this, &MainWindow::changeProgressBarPercentage);
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

void MainWindow::enableStartButton() {
    ui->startButton->setEnabled(true);
}

void MainWindow::disableStartButton() {
    ui->startButton->setEnabled(false);
}

void MainWindow::enableGameOverScreen() {
    ui->gameOverScreen->setVisible(true);
}

void MainWindow::disableGameOverScreen() {
    ui->gameOverScreen->setVisible(false);
}

void MainWindow::changeStartButtonText(QString newName) {
    ui->startButton->setText(newName);
}

void MainWindow::changeProgressBarPercentage(int newPercentage) {
    ui->progressBar->setValue(newPercentage);
}

void MainWindow::glowButton(int buttonID, int timeToBeLit) {
    if (buttonID == 0) {
        // Determine colors by color id
        if (currentColors == 0) {
            ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
        }
        else {
            ui->redButton->setStyleSheet("background-color: rgb(255, 236, 66);");
        }
        QTimer::singleShot(timeToBeLit, this, [this](){this->resetColors();});
    }
    else {
        if (currentColors == 0) {
            ui->blueButton->setStyleSheet("background-color: rgb(50, 50, 200);");
        }
        else {
            ui->blueButton->setStyleSheet("background-color: rgb(79, 0, 163);");
        }
        QTimer::singleShot(timeToBeLit, this, [this](){this->resetColors();});
    }
}


void MainWindow::resetColors() {
    if (currentColors == 0) {
        ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
        ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
    }
    else {
        ui->redButton->setStyleSheet("background-color: rgb(189, 182, 81);");
        ui->blueButton->setStyleSheet("background-color: rgb(150, 92, 191);");
    }
}

void MainWindow::on_redButton_clicked()
{
    // Light up color
    if (currentColors == 0) {
        ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
        ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
    }
    else{
        ui->redButton->setStyleSheet("background-color: rgb(189, 182, 81);");
        ui->blueButton->setStyleSheet("background-color: rgb(150, 92, 191);");
    }

    // Notify model
    emit playerSelectionComplete(0);
}


void MainWindow::on_blueButton_clicked()
{
    // Light up color
    if (currentColors == 0) {
        ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
        ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
    }
    else {
        ui->redButton->setStyleSheet("background-color: rgb(189, 182, 81);");
        ui->blueButton->setStyleSheet("background-color: rgb(150, 92, 191);");
    }

    // Notify model
    emit playerSelectionComplete(1);
}

void MainWindow::on_startButton_clicked()
{
    emit startButtonPressed();
}


void MainWindow::on_brRadioButton_clicked()
{
    currentColors = 0;
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
}


void MainWindow::on_ypRadioButton_clicked()
{
    currentColors = 1;
    ui->redButton->setStyleSheet("background-color: rgb(189, 182, 81);");
    ui->blueButton->setStyleSheet("background-color: rgb(150, 92, 191);");
}

