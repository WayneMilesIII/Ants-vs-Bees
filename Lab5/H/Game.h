//
// Created by 12539 on 11/3/2020.
//

#ifndef LAB5_GAME_H
#define LAB5_GAME_H
#include <vector>
#include "Insect.h"
#include "../H/Utilities.h"
#include "Utilities.h"

using namespace std;

class Game {
protected:
    int bank;
    bool gameLoop = false;
    vector<vector<Insect> > board;
public:
    Game();
    void game_Loop();
    void setGameLoop(bool sentinel);
    bool getGameLoop();
    void antPlacement( int selection, int position, int bank);
    void antAction();
    void beeMove (vector<vector<Insect>> board);
    void beeAttack(int i, int j);

};


#endif //LAB5_GAME_H
