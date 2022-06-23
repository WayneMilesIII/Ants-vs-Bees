//
// Created by 12539 on 11/3/2020.
//

#include "../H/Utilities.h"
#include "../H/Insect.h"
#include "../H/Thrower.h"
#include "../H/Fire.h"
#include "../H/LongThrower.h"
#include "../H/ShortThrower.h"
#include "../H/Wall.h"
#include "../H/Ninja.h"
#include "../H/Bodyguard.h"
#include "../H/Bee.h"
#include <string>
#include <iostream>
Utilities::Utilities() {
}

Insect Utilities::antCreator(int select, int bank) {
    switch (select) {
        case 1:
        {
            if (bank >= 2 )
            {
                return Harvester();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 2:
        {
            if (bank >= 4 ) {
                return Thrower();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 3:
        {
            if (bank >= 4 ) {
                return Fire();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 4:
        {
            if (bank >= 3 ) {
                return LongThrower();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 5:
        {
            if (bank >= 3 ) {
                return ShortThrower();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 6:
        {
            if (bank >= 4 ) {
                return Wall();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 7:
        {
            if (bank >= 6 ) {
                return Ninja();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 8:
        {
            if (bank >= 4 ) {
                return Bodyguard();
            }
            cout << "Not enough money!" << endl;
            break;
        }
    }
    cout << "You didn't chose the right a number in bounds! I'll help you out and give you a Harvester!" << endl;
    return  Harvester();

}

Insect Utilities::beeCreator() {
    Bee bee = Bee();
    return bee;
}

int Utilities::check_and_convert_input(const string input) {
    int i = std::stoi(input);
    if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9) {
        return i;
    } else {
        std::cout << "The entry " << input << " entered was not a number accepted. :(" << endl;
        return i;
    }
}

int Utilities::antCost(int selection, int bank){
    switch (selection) {
        case 1:
        {
            if (bank >= Harvester().getCost() )
            {
                cout << "A " << Harvester().getName() << " will cost you " << Harvester().getCost() << " food!" << endl;
                return Harvester().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 2:
        {
            if (bank >= 4 ) {
                cout << "A " << Thrower().getName() << " will cost you " << Thrower().getCost() << " food!" << endl;
                return Thrower().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 3:
        {
            if (bank >= 4 ) {
                cout << "A " << Fire().getName() << " will cost you " << Fire().getCost() << " food!" << endl;
                return Fire().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 4:
        {
            if (bank >= 3 ) {
                cout << "A " << LongThrower().getName() << " will cost you " << LongThrower().getCost() << " food!" << endl;
                return LongThrower().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 5:
        {
            if (bank >= 3 ) {
                cout << "A " << ShortThrower().getName() << " will cost you " << ShortThrower().getCost() << " food!" << endl;
                return ShortThrower().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 6:
        {
            if (bank >= 4 ) {
                cout << "A " << Wall().getName() << " will cost you " << Wall().getCost() << " food!" << endl;
                return Wall().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 7:
        {
            if (bank >= Ninja().getCost() ) {
                cout << "A " << Ninja().getName() << " will cost you " << Ninja().getCost() << " food!" << endl;
                return Ninja().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
        case 8:
        {
            if (bank >=  Bodyguard().getCost() ) {
                cout << "A " << Bodyguard().getName() << " will cost you " << Bodyguard().getCost() << " food!" << endl;
                return Bodyguard().getCost();
            }
            cout << "Not enough money!" << endl;
            break;
        }
    }
    cout << "A " << Harvester().getName() << " will cost you " << Harvester().getCost() << " food!" << endl;
    return  Harvester().getCost();
}
