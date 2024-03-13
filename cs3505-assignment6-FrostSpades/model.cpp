#include "model.h"
#include <vector>
#include <random>
#include <QTimer>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

Model::Model() {

}

Model::~Model() {

}

void Model::start() {
    moves.clear();
    gameIsOver = false;
    currentPlayerMove = 0;
    currentDemoColor = 0;
    isPlayersTurn = false;
    performComputerMove();
    cout<< "game started" << endl;
    emit setStartButtonName(QString("Playing"));
    emit setProgressBarPercentage(0);
    emit hideGameOverScreen();
    emit disableStart();
}

double Model::getTime() {
    return 300+500*pow(.4, moves.size());
}

bool Model::validatePlayerMove(int move)
{
    emit lightUpButton(move, getTime());

    // If it's game over, don't register the click
    if (!gameIsOver)
    {
        emit turnOffButtons();
        if(currentPlayerMove < moves.size())
        {
            // see if its the right move
            if(move == moves[currentPlayerMove])
            {
                // update progress
                cout<< "correct move" << endl;
                currentPlayerMove++;
                int n = (int)(((double)(currentPlayerMove)/moves.size())*100);
                emit setProgressBarPercentage(n);
                emit playersTurn();
            }
            else
            {
                // emit gameover and show graphic
                cout<< "wrong move, gameover" << endl;
                //currentPlayerMove++;
                gameIsOver = true;
                gameOver();
            }
        }

        if(currentPlayerMove == moves.size())
        {
            cout<< "correct sequence, computers turn now" << endl;
            isPlayersTurn = false;
            currentPlayerMove = 0;
            emit turnOffButtons();
            QTimer::singleShot(1000, this, [this](){this->performComputerMove();});
        }
    }

    else {
        emit turnOffButtons();
    }
}

void Model::gameOver() {
    // emit game over screen
    // enable start button
    emit showGameOverScreen();
    emit enableStart();
    emit setStartButtonName(QString("Restart"));
}

void Model::performComputerMove()
{
    emit setProgressBarPercentage(0);
    int moveAdded = rand() % 2;
    cout<< "adding "<< moveAdded << " to sequence (0=red, 1=blue)" << endl;
    moves.push_back(moveAdded);
    emit turnOffButtons();

    for (int i = 0; i < moves.size(); i++) {
        QTimer::singleShot(2*i*getTime(), this, [this, i](){emit this->lightUpButton(moves[i], getTime());});
    }

    currentPlayerMove = 0;
    QTimer::singleShot((2*moves.size() - 1)*getTime(), this, [this](){emit this->playersTurn();});
}








