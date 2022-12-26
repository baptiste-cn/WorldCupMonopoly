#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "box.hh"

class Board{
    protected:
        std::vector<Box> _boxes;
        int _nbPlayers;
        int _whosPlaying;  //à qui le tour
        int _taxMoney;  //argent des taxes

    public:
        Board();
        ~Board();
        void throwDice(){
            int dice = rand() % 6 + 1;
            std::cout << "Dice: " << dice << std::endl;
        };
};