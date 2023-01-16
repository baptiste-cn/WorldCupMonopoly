#pragma once

#include <vector>
#include "game.hh"
#include "board.hh" 

class Box;

class Player: public Board{
    public:
        //constructor(s)
        Player(){_name = "Player";};
        Player(std::string name){_name = name;}
        ~Player(){};

        //setters
        void addMoney(int amount){_money += amount;}

        //getters
        int getMoney() const {return _money;}
        std::string getName() const {return _name;}

        //others
        std::string _name;
        
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