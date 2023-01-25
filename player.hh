#pragma once

#include <vector>
#include "game.hh"
#include "board.hh" 

class Box;

class Player: public Board{
    public:
        //constructor(s)
        Player(){_name = "Player";};
        Player(std::string name){_name = name; setActualPosition(0);}
        ~Player(){};

        //setters
        void addMoney(int amount){_money = amount;}
        void setMoney(int amount){_money = amount;}
        void setActualPosition(int position){_actualPosition = position;}


        //getters
        int getMoney() const {return _money;}
        std::string getName() const {return _name;}
        int getActualPosition() const {return _actualPosition;}

        //others
        std::string _name;
        void addBox(Box &box){_ownedBoxes.push_back(&box);}
        
    protected:
        int _daysInJail;
        double _money;
        int _actualPosition;
        std::vector <Box*> _ownedBoxes;
        bool _isEjected;
        bool _isBankrupt;
        bool _isPlaying;
        bool _isWinner;
        bool _isJailed;
};