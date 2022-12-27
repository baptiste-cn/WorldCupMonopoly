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
        ~Board(){};
        void throwDice(){
            int dice = rand() % 6 + 1;
            std::cout << "Dice: " << dice << std::endl;
        };

        //getters
        int getNbPlayers() const {return _nbPlayers;};
        int getWhosPlaying() const {return _whosPlaying;};
        int getTaxMoney() const {return _taxMoney;};
        std::vector<Box> getBoxes() const {return _boxes;};
};