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
    // boolean flag for whether the game has ended due to player miscllick
    bool gameIsOver;
    // boolean flag for whether it is the player's turn
    bool isPlayersTurn;

    /**
     * @brief performComputerMove adds a move to the sequence and displays the sequence
     */
    void performComputerMove();

public:
    /**
     * @brief Model
     * default constructor for the model
     */
    Model();

    /**
     * Default deconstructor
    */
    ~Model();

    /**
     * @brief getTime
     * returns the current delay for the buttons
     * @return the current time delay for the buttons
     */
    double getTime();

signals:
    /**
     * @brief lightUpButton
     * Sends signal to light up the buttons
     * @param buttonId the button to be lit
     * @param timeToBeLit the amount of time to be lit
     */
    void lightUpButton(int buttonId, int timeToBeLit);

    /**
     * @brief playersTurn
     * Sends signal to the view that it is the players turn
     */
    void playersTurn(int playerMovePercentage);

    /**
     * @brief turnOffButtons
     * Sends signal to the view to turn off the game buttons.
     */
    void turnOffButtons();

    /**
     * @brief gameStarted
     * Sends signal that game has started.
     */
    void gameStarted();

    /**
     * @brief turnOnButtons
     * Sends signal to turn on the game buttons.
     */
    void turnOnButtons();

    /**
     * @brief triggerGameOver
     * Sends signal that the game is over.
     */
    void triggerGameOver();

    /**
     * @brief computersTurn
     * Sends signal that it is the computers turn.
     */
    void computersTurn();

public slots:
    /**
     * @brief validatePlayerMove
     * Validates the player move given a move
     * @param move the move to validate
     */
    void validatePlayerMove(int move);

    /**
     * @brief start
     * Starts the game process.
     */
    void start();
};

#endif // MODEL_H
