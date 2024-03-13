#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <QObject>

class Model : public QObject{
    Q_OBJECT
private:
    int currentMove;
    std::vector<int> moves;
    bool validatePlayerMove(int move);

public:
    Model();
    ~Model();
    void clearMoves();
    bool processMove(int move);
    double getTime();

signals:
    void createdSequence(std::vector<int> colorList);
    void start();
};

#endif // MODEL_H
