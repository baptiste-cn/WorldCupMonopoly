#pragma once

#include "game.hh"
#include "box.hh"

class Player: public Game{
    public:
        //constructor(s)
        Player();
        ~Player();
        
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