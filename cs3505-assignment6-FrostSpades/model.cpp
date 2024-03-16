/*
 * Implementation of model class. Represents the model
 * of the simon game.
 *
 * CS3505
 * @date 03/13/2024
 * @author Ethan Andrews
 * @author Vasil Vassilev
 */

#include "model.h"
#include <vector>
#include <QTimer>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

Model::Model() {}

Model::~Model() {}

void Model::start() {
    // Reset the model
    moves.clear();
    currentPlayerMove = 0;
    currentDemoColor = 0;
    isPlayersTurn = false;
    gameIsOver = false;

    // Start showing the computer moves
    performComputerMove();

    // Tell view game has started
    emit gameStarted();
}

double Model::getTime() {
    return 300+500*pow(.4, moves.size());
}

void Model::validatePlayerMove(int move)
{
    emit lightUpButton(move, getTime());

    // If it's game over, don't register the click
    if (!gameIsOver)
    {
        // Turn off the buttons
        emit turnOffButtons();

        // Check if it is the last move
        if((unsigned long long)currentPlayerMove < moves.size())
        {
            // see if its the right move
            if(move == moves[currentPlayerMove])
            {
                // update progress
                currentPlayerMove++;
                int newPercentage = (int)(((double)(currentPlayerMove)/moves.size())*100);

                //emit setProgressBarPercentage(newPercentage);
                emit playersTurn(newPercentage);
            }

            // Trigger game over if not right move
            else
            {
                gameIsOver = true;
                emit triggerGameOver();
            }
        }

        // If last move, add move and show player
        if((unsigned long long)currentPlayerMove == moves.size())
        {
            isPlayersTurn = false;
            currentPlayerMove = 0;

            // Disable the buttons
            emit turnOffButtons();

            // Display computer moves after 1 second has passed
            QTimer::singleShot(1000, this, [this](){this->performComputerMove();});
        }
    }

    else {
        emit turnOffButtons();
    }
}


void Model::performComputerMove()
{
    // Add a new move
    int moveAdded = rand() % 2;
    moves.push_back(moveAdded);

    // Set view
    emit computersTurn();

    // Trigger events for lighting up buttons
    for (int i = 0; (unsigned long long)i < moves.size(); i++) {
        QTimer::singleShot(2*i*getTime(), this, [this, i](){emit this->lightUpButton(moves[i], getTime());});
    }

    currentPlayerMove = 0;

    // Emit players turn after all events are finished
    QTimer::singleShot((2*moves.size() - 1)*getTime(), this, [this](){emit this->turnOnButtons();});
}








