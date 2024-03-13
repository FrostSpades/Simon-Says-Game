#include "model.h"
#include <vector>
#include <random>

Model::Model() {

}

Model::~Model() {

}

void Model::start() {
    moves.clear();
    gameIsOver = false;
    currentPlayerMove = 0;
    currentDemoColor = 0;
    performComputerMove();
    // disable start button
}

double Model::getTime() {
    return 1000;
}

bool Model::validatePlayerMove(int move)
{
    if(currentPlayerMove < moves.size())
    {
        // see if its the right move
        if(move == moves[currentPlayerMove])
        {
            // update progress
            currentPlayerMove++;
        }
        else
        {
            // emit gameover and show graphic
            currentPlayerMove++;
            gameIsOver = true;
            emit gameOver();
            // display graphic
        }
    }

    if(currentPlayerMove == moves.size())
    {
        emit turnOffButtons();
        currentPlayerMove = 0;
        //
        performComputerMove();
    }
}

void Model::performComputerMove()
{
    moves.push_back(rand() % 2);
    currentDemoColor = 0;
    lightNextButton();
}

void Model::lightNextButton()
{
    if(!gameIsOver)
    {
        if(currentDemoColor < moves.size())
        {
            emit lightUpButton(moves[currentDemoColor], getTime());
            currentDemoColor++;
        }
        else
        {
            // computer demo is done, user turn
            currentPlayerMove = 0;
            emit playersTurn();
        }
    }

}






