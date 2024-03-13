#include "model.h"
#include <vector>
#include <random>

Model::Model() {

}

Model::~Model() {

}

void Model::start() {
    moves.clear();
    moves.push_back(rand() % 2);
    currentDemoColor = 0;

    emit createdSequence(moves);
}

double Model::getTime() {
    return 500;
}


bool Model::validatePlayerMove(int move)
{
    // validate the move
}

void Model::lightNextButton()
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






