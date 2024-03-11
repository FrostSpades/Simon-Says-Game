#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <QObject>

class Model : public QObject{
private:
    int currentMove;
    std::vector<int> moves;

public:
    Model();
    ~Model();
    void clearMoves();
    void addMove();
    bool processMove(int move);
};

#endif // MODEL_H
