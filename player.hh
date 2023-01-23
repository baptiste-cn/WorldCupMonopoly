#pragma once

#include <vector>
#include "board.hh" 

class Box;

class Player{
    public:
        int diceTurn;

        //constructor(s)
        Player(){_name = "Player"; _actualPosition=0; _money = 200;}
        Player(std::string name){_name = name;}
        ~Player(){};

        //setters
        void setActualPosition(int newPos){_actualPosition = newPos;}

        //others
        void addMoney(int amount){_money = amount;}

        //getters
        int getMoney() const {return _money;}
        int getActualPosition() const {return _actualPosition;}
        std::vector<Box> getOwnedBoxes() const {return _ownedBoxes;}
        bool getIsEjected() const {return _isEjected;}
        bool getIsBankrupt() const {return _isBankrupt;}
        bool getIsPlaying() const {return _isPlaying;}
        bool getIsWinner() const {return _isWinner;}
        bool getIsJailed() const {return _isJailed;}
        std::string getName() const {return _name;}

        //others
        std::string _name;
        
    protected:
        //int _daysInJail;
        int _money;
        int _actualPosition;
        std::vector <Box> _ownedBoxes;
        bool _isEjected = 0;
        bool _isBankrupt = 0;
        bool _isPlaying;
        bool _isWinner = 0;
        bool _isJailed = 0;
};