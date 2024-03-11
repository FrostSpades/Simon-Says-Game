#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(Model())
{
    ui->setupUi(this);
    enableGameButtons();
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
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

void MainWindow::glowButton(int buttonID) {
    if (buttonID == 0) {
        ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
        QTimer::singleShot(2000, this, &MainWindow::resetColors);
    }
    else {
        ui->blueButton->setStyleSheet("background-color: rgb(50,50,200);");
        QTimer::singleShot(2000, this, &MainWindow::resetColors);
    }
}

void MainWindow::resetColors() {
    ui->redButton->setStyleSheet("background-color: rgb(200,150,150);");
    ui->blueButton->setStyleSheet("background-color: rgb(150,150,200);");
}

void MainWindow::on_redButton_clicked()
{
    resetColors();
    glowButton(0);
}


void MainWindow::on_blueButton_clicked()
{
    resetColors();
    glowButton(1);
}


void MainWindow::on_startButton_clicked()
{
    model.clearMoves();
}

