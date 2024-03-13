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
    connect(&model, &Model::createdSequence, this, &MainWindow::showSequence);
    connect(this, &MainWindow::startButtonPressed, &model, &Model::start);
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
    }
    else {
        ui->blueButton->setStyleSheet("background-color: rgb(50,50,200);");
    }
}

void MainWindow::showSequence(std::vector<int> colorList) {
    recurse(colorList, 0);
}

void MainWindow::recurse(std::vector<int> colorList, int currentColor) {
    if (currentColor > colorList.size()) {
        // Call model method to start listening for computer presses
        return;
    }

    glowButton(colorList[currentColor]);

    QTimer::singleShot(model.getTime(), this, [=](){wait(colorList, currentColor + 1);});
}

void MainWindow::wait(std::vector<int> colorList, int currentColor) {
    resetColors();
    QTimer::singleShot(model.getTime(), this, [=](){recurse(colorList, currentColor + 1);});
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
    model.start();
}

