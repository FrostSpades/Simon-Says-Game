/*
 * Model header file for the model of the Qt Simon Game
 * CS3505
 * @date 03/13/2024
 * @author Ethan Andrews
 * @author Vasil Vassilev
*/
#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <QObject>

class Model : public QObject{
    Q_OBJECT
private:
    // index used to keep track of where the computer is in the demo sequence
    int currentDemoColor;
    // index used to keep track of the player's current progress through the sequence
    int currentPlayerMove;
    // vector used to maintain the sequence of buttons
    std::vector<int> moves;
    /**
     * @brief performComputerMove adds a move to the sequence and displays the sequence
     */
    void performComputerMove();
    // boolean flag for whether the game has ended due to player miscllick
    bool gameIsOver;
    // boolean flag for whether it is the player's turn
    bool isPlayersTurn;
    /**
     * @brief gameOver controls the view's actions in the event of a wrong input, displays game over screen, and switches replay button on
     */
    void gameOver();

public:
    /**
     * @brief Model
     */
    Model();
    ~Model();
    void clearMoves();
    bool processMove(int move);
    double getTime();

signals:
    void lightUpButton(int buttonId, int timeToBeLit);
    void playersTurn();
    void computersTurn();
    void turnOffButtons();

    void pauseBetweenTurns();
    void disableStart();
    void enableStart();
    void showGameOverScreen();
    void hideGameOverScreen();
    void setStartButtonName(QString newName);
    void setProgressBarPercentage(int newPercentage);

public slots:
    //void lightNextButton();
    bool validatePlayerMove(int move);
    void start();
};

#endif // MODEL_H
