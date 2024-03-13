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
    return 1000;
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
        performComputerMove();
    }
}

void Model::performComputerMove()
{
    int moveAdded = rand() % 2;
    cout<< "adding "<< moveAdded << " to sequence (0=red, 1=blue)" << endl;
    moves.push_back(moveAdded);
    currentDemoColor = 0;
    lightNextButton();
}

void Model::lightNextButton()
{
    if (!gameIsOver && !isPlayersTurn)
    {
        if (currentDemoColor < moves.size())
        {
            int buttonID = moves[currentDemoColor];
            emit lightUpButton(buttonID, getTime());

            // Schedule the next button to be lit after a delay
            QTimer::singleShot(getTime(), this, [=]() {
                currentDemoColor++;
                lightNextButton(); // Call recursively to proceed to the next button
            });
        }
        else
        {
            // Computer demo is done, switch to player's turn
            currentPlayerMove = 0;
            currentDemoColor = 0;
            isPlayersTurn = true;
            emit playersTurn();
        }
    }
}







