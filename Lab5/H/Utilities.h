//
// Created by 12539 on 11/3/2020.
//

#ifndef LAB5_UTILITIES_H
#define LAB5_UTILITIES_H
#include "Insect.h"
#include "Game.h"
#include "../H/Harvester.h"
#include <vector>

class Utilities {
public:
    Utilities();
    Insect antCreator(int select, int bank);
    Insect beeCreator();

    int check_and_convert_input(const std::string input);
    int antCost(int selection, int bank);
};


#endif //LAB5_UTILITIES_H
