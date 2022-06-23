//
// Created by 12539 on 11/3/2020.
//

#include "../H/Fire.h"

Fire::Fire() : Insect(){
    cost = 4;
    armor = 1;
    canMove = false;
    name = "Fire";
    canAttack = false;
    attack = 0;
    type = "Ant";
    passable = false;
}

