//
// Created by 12539 on 11/3/2020.
//

#include "../H/ShortThrower.h"

ShortThrower::ShortThrower() : Insect(){
    cost = 3;
    armor = 1;
    name = "Short Thrower";
    canMove = false;
    canAttack = true;
    attack = 1;
    type = "Ant";
}
