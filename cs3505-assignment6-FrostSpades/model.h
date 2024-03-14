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

    /**
     * @brief gameOver controls the view's actions in the event of a wrong input, displays game over screen, and switches replay button on
     */
    void gameOver();

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
    void playersTurn();

    /**
     * @brief turnOffButtons
     * Sends signal to the view to turn off the game buttons.
     */
    void turnOffButtons();

    /**
     * @brief disableStart
     * Sends signal to disable the start button.
     */
    void disableStart();

    /**
     * @brief enableStart
     * Sends signal to enable the start button.
     */
    void enableStart();

    /**
     * @brief showGameOverScreen
     * Sends signal to show the game over screen.
     */
    void showGameOverScreen();

    /**
     * @brief hideGameOverScreen
     * Sends signal to hide the game over screen.
     */
    void hideGameOverScreen();

    /**
     * @brief setStartButtonName
     * Sets the start button name
     * @param newName the new name to set it to
     */
    void setStartButtonName(QString newName);

    /**
     * @brief setProgressBarPercentage
     * Sets the percentage of the progress bar.
     * @param newPercentage the new percentage to set it to.
     */
    void setProgressBarPercentage(int newPercentage);

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
