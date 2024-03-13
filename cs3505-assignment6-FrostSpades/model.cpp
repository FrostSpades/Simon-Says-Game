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


    emit createdSequence(moves);
}

double Model::getTime() {
    return 500;
}


bool Model::validatePlayerMove(int move) {

}
