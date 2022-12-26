#pragma once

#include <vector>
#include "game.hh"

class Box;

class Player: public Game{
    public:
        //constructor(s)
        Player();
        ~Player();

        //setters
        void addMoney(int amount){_money += amount;}

        //getters
        int getMoney() const {return _money;}

        
    protected:
        int _daysInJail;
        int _money;
        int _actualPosition;
        std::vector <Box> _ownedBoxes;
        bool _isEjected;
        bool _isBankrupt;
        bool _isPlaying;
        bool _isWinner;
        bool _isJailed;
};