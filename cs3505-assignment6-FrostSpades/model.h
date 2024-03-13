#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <QObject>

class Model : public QObject{
    Q_OBJECT
private:
    int currentDemoColor;
    int currentPlayerMove;
    std::vector<int> moves;
    void performComputerMove();
    bool gameIsOver;
    bool isPlayersTurn;

public:
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
    void gameOver();
    void pauseBetweenTurns();
public slots:
    //void lightNextButton();
    bool validatePlayerMove(int move);
    void start();
};

#endif // MODEL_H
