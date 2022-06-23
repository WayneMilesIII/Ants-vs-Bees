//
// Created by 12539 on 11/3/2020.
//
#include "../H/Utilities.h"
#include <vector>
#include <iostream>
#include "../H/Insect.h"
#include "../H/QueenAnt.h"



using namespace std;

    Game :: Game() {
    bank = 50;
    gameLoop = true;
}

    void Game::game_Loop() {
        int c;
       Utilities utils;
       cout << "Welcome to the War of Insects!" << endl;
       cout << "We will see if your tactical skills are enough to help the ants defeat the bees!" << endl;
       cout << "" << endl;


   for (int i = 0; i < 10 ; ++i)
   {
       vector<Insect> spaces(1);
       board.push_back(spaces);
   }

        board.at(0).push_back(QueenAnt());


        cout << "         The board has been set!" << endl;
        cout << "               GAME START!               " << endl;
        cout << "-----------------------------------------" << endl;
    while (gameLoop == true)
    {
        string selection;
        string placement;


        cout << "A new bee has appeared!" << endl;
        board.at(9).push_back(utils.beeCreator());


        cout << "Which ant do you want to create?" << endl;
        cout << "Please use 1 - 8 to select the Ants!" << endl;
        cout << "" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "|| 1 - Harvester Ant     || 2 - Thrower Ant  || 3 - Fire Ant   || 4 - Long Thrower Ant ||" << endl;
        cout << "|| 5 - Short Thrower Ant || 6 - Wall Ant     || 7 - Ninja Ant  || 8 - Bodyguard Ant    ||" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cin >> selection;
        cout << "You chose " + selection << ". Where do you want to place it? Choose a number between 0 - 9" << endl;
        cin >> placement;
        int valid_placement = utils.check_and_convert_input(placement);
        int valid_selection = utils.check_and_convert_input(selection);
        if (valid_selection >= 0 || valid_selection <= 9 && valid_placement >= 1 || valid_placement <= 8 )
        {
            antPlacement(valid_selection, valid_placement, bank);
            bank = bank - utils.antCost(valid_selection, bank);
        }

        cout << "" << endl;
        cout << "Here's how your ants are doing!" << endl;
        cout << "---------------------------------------------------------" << endl;
        for ( int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board.at(i).at(j).getType() == "Ant") {
                    cout << "The type of ant space " << i  << " is a " << board.at(i).at(j).getName() << "." << endl;
                    cout << "Your ant at space "<< i << " has " << board.at(i).at(j).getArmor()<< " armor." << endl;
                }
            }
        }
        cout << "Ants are performing their actions!" << endl;
        antAction();


        cout << "The bees are on the move!" << endl;
        beeMove(board);

        if (board.at(0).at(0).getName() == "Bee" || board.at(0).at(1).getName() == "Bee")
        {
            cout << "The bees have reached the queen!" << endl;
            cout << "Queen? QUEEN? QUEEEEEEEEN!!!!" << endl;
            gameLoop = false;
        }
        for (int i = 0; i < board.size(); i++){


            for (int j = 0; j < board[i].size(); j++ ) {
                if (board.at(i).at(j).getType() == "Bee") {
                    c++;
                }
            }
        }
        if (c != 0)
        {
            cout << "The Game SHALL CONTINUE" << endl;
        }
        else if (c == 0)
        {
            cout << "The BEES SHALL BE VANQUISHED" << endl;
        }
    }


}

    void Game::antPlacement( int selection, int placement, int bank) {
    Utilities utils;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {

            if (board[placement].at(j).getType() == "Ant" && board[placement].at(j).getType() != "Bodyguard") {
                cout << "You can't place it here!" << endl;
            } else {
                for (i = 0; i < board.size(); i++) {
                    for (j = 0; j < board.at(i).size(); j++) {
                        if (i == placement && (placement >= 0 && placement <= 9)) {
                            if (board[placement].at(0).getType() != "Ant" ||
                                board[placement].at(0).getType() == "Bodyguard") {
                                board.at(i).push_back(utils.antCreator(selection, bank));
                                break;
                            }
                        }
                    }
                }
            }
        }


    }
}

    void Game::antAction() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                if (board.at(i).at(j).getType() == "Ant") {
                    if (board.at(i).at(j).getName() == "Harvester") {
                        cout << "The Harvester at space " << i << " will add food to your food storage!" << endl;
                        bank++;
                    }

                    if (board.at(i).at(j).getName() == "Thrower") {
                        cout << "The thrower will deal damage!" << endl;
                        board[i].at(j).setArmor(board[i].at(j).getArmor() - 1);
                    }

                    if (board.at(i).at(j).getName() == "Fire") {
                        if (board.at(i).at(j).getArmor() == 0) {
                            cout << "The Fire ant will now NUKE the square!" << endl;
                            for (int j; j < board[i].size(); j++)
                            {
                                board.at(i).at(j).setArmor(0);
                            }
                        }
                    }

                    if (board.at(i).at(j).getName() == "Long Thrower") {
                        cout << "The Long Thrower will now throw the LONGEST it's ever thrown!" << endl;
                        while (i < 5) {
                            if (board.at(i + 4).at(j).getType() == "Bee") {
                                cout << "The Ant will begin its attack!" << endl;
                                board.at(i + 4).at(j).setArmor(board.at(i + 4).at(j).getArmor() - 1);
                            }
                        }
                        cout << "There were no targets! :'( " << endl;
                    }


                    if (board.at(i).at(j).getName() == "Short Thrower") {
                        cout
                                << "The Short Thrower will now throw, you guessed it, the SHORTEST throw. He tries his best <3"
                                << endl;
                        while (i != 7) {
                            if (board.at(i + 2).at(j).getType() == "Bee") {
                                for (i = 0; j < board[i].size(); i++) {
                                    cout << "The ant will begin its attack!" << endl;
                                    board.at(i + 2).at(j).setArmor(board.at(i + 2).at(j).getArmor() - 1);
                                }

                            }
                        }
                    }

                    if (board.at(i).at(j).getName() == "Wall") {
                        cout << "The wall shan't be passed!" << endl;
                    }

                    if (board.at(i).at(j).getName() == "Ninja") {
                        cout << "The Ninja will be silent, but will strike when they least expect it!" << endl;
                    }

                    if (board.at(i).at(j).getName() == "Bodyguard") {
                        cout << "The Bodyguard will protect the ants!" << endl;
                    }

                }
            }
        }
    }

    void Game::beeMove(vector<vector<Insect>> board) {
            Utilities utils;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (board.at(i).at(j).getType() == "Ant")
                    {
                        cout << "There is an Ant here!" << endl;
                        cout << "The bees will attack the ants!" << endl;
                        board.at(i).at(j).setArmor(board.at(i).at(j).getArmor()-board.at(i).at(j).getAttack());
                    }
                    else if(board.at(i).at(j).getType() == "Bee")
                    {
                        cout << "There is a Bee here!" << endl;
                        for(int k = 0; k < board[i].size(); k++) {
                            if (board.at(i).at(k).getName() != "Wall") {
                                board.at(i-1).push_back(utils.beeCreator());
                                board.at(i).pop_back();
                                for (k = 0; k < board[i].size(); k++){
                                    if (board.at(i).at(k).getName() == "Ninja");
                                    board.at(i-1).at(k).setArmor(board.at(i-1).at(k).getArmor() - board.at(i-1).at(k).getAttack());
                                }
                            }
                        }
                    }
                }
                }
            }