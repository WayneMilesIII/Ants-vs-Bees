//
// Created by 12539 on 11/2/2020.
//
#include <string>
#ifndef LAB5_INSECT_H
#define LAB5_INSECT_H
//
// Created by 12539 on 11/2/2020.
//

class Insect{
protected:
    int cost;
    int armor;
    std::string name;
    bool canMove;
    bool canAttack;
    int attack;
    std::string type;
    bool passable;
public:
     int getArmor();
     int getCost();
     std::string getName();
     bool getCanMove();
     bool getCanAttack();
     int getAttack();
     void setArmor(int newArmor);
     std::string getType();
     bool getPassable();
     //virtual void attackPattern() = 0;

};


#endif //LAB5_INSECT_H
