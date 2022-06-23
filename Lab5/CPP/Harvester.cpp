//
// Created by 12539 on 11/2/2020.
//

#include "../H/Harvester.h"

Harvester::Harvester() : Insect(){
    cost = 2;
    armor = 1;
    name = "Harvester";
    canMove = false;
    canAttack = false;
    attack = 0;
    type = "Ant";
    passable = false;
}