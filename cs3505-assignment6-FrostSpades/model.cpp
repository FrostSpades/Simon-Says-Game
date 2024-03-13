#include "model.h"
#include <vector>
#include <random>
#include <QTimer>
#include <iostream>
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
    // disable start button
}

double Model::getTime() {
    return 500;
}

bool Model::validatePlayerMove(int move)
{
    emit lightUpButton(move, getTime());

    if(currentPlayerMove < moves.size())
    {
        // see if its the right move
        if(move == moves[currentPlayerMove])
        {
            // update progress
            cout<< "correct move" << endl;
            currentPlayerMove++;
        }
        else
        {
            // emit gameover and show graphic
            cout<< "wrong move, gameover" << endl;
            //currentPlayerMove++;
            gameIsOver = true;
            emit gameOver();
            // display graphic
        }
    }

    if(currentPlayerMove == moves.size())
    {
        cout<< "correct sequence, computers turn now" << endl;
        isPlayersTurn = false;
        emit turnOffButtons();
        currentPlayerMove = 0;
        QTimer::singleShot(1000, this, [=](){performComputerMove();});
    }
}

void Model::performComputerMove()
{
    int moveAdded = rand() % 2;
    cout<< "adding "<< moveAdded << " to sequence (0=red, 1=blue)" << endl;
    moves.push_back(moveAdded);
    for (int i = 0; i < moves.size(); i++) {
        QTimer::singleShot(2*i*getTime(), this, [=](){emit lightUpButton(moves[i], getTime());});
    }

    currentPlayerMove = 0;
    emit playersTurn();
}








