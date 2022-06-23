//
// Created by 12539 on 11/2/2020.
//
#include <string>
#include "../H/Insect.h"


int Insect::getCost() {
    return cost;
}

int Insect::getArmor(){
    return armor;
}

std::string Insect::getType() {
    return type;
}

bool Insect::getCanAttack() {
    return canAttack;
}

int Insect::getAttack() {
    return attack;
}

std::string Insect::getName() {
    return name;
}

bool Insect::getCanMove() {
    return canMove;
}

void Insect::setArmor(int newArmor) {
    armor = newArmor;
}

bool Insect::getPassable() {
    return passable;
}

