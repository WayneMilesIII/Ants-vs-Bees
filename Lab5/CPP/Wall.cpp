//
// Created by 12539 on 11/3/2020.
//

#include "../H/Wall.h"

Wall::Wall() : Insect(){
    cost = 4;
    armor = 4;
    name = "Wall";
    canMove = false;
    canAttack = false;
    attack = 0;
    type = "Ant";
}

