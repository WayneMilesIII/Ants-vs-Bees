//
// Created by 12539 on 11/3/2020.
//

#ifndef LAB5_QUEENANT_H
#define LAB5_QUEENANT_H


#include "Insect.h"

class QueenAnt : public Insect {
protected:
    bool beeAtQueen;
    bool canBeCreated;
public:
    QueenAnt();
    bool getBeeAtQueen();
    void setBeeAtQueen(bool reached);
};


#endif //LAB5_QUEENANT_H
