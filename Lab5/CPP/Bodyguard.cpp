//
// Created by 12539 on 11/3/2020.
//

#include "../H/Bodyguard.h"

Bodyguard::Bodyguard() : Insect(){
    cost = 4;
    armor = 2;
    canMove = false;
    name = "Bodyguard";
    canAttack = false;
    attack = 0;
    type = "Ant";
    passable = false;
}

