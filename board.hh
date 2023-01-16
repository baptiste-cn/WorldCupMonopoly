#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

class Player;
class Box;

class Board{
    protected:
        std::vector<Box> _boxes;
        int _whosPlaying;  //à qui le tour
        int _taxMoney;  //argent des taxes
        std::vector<Player> _players;  //joueurs

    public:
        int nbPlayers;

        Board();
        ~Board(){};
        void throwDice(){
            int dice = rand() % 6 + 1;
            std::cout << "Dice: " << dice << std::endl;
        };

        //getters
        int getNbPlayers() const {return nbPlayers;}
        int getWhosPlaying() const {return _whosPlaying;}
        int getTaxMoney() const {return _taxMoney;}
        std::vector<Box> getBoxes() const {return _boxes;}
        std::vector<Player> getPlayers() const {return _players;}

        //setters
        void setNbPlayers(int nbPlayers){nbPlayers = nbPlayers;}
        void setWhosPlaying(int whosPlaying){_whosPlaying = whosPlaying;}
        

        //others
        void addTaxMoney(double amount) {_taxMoney+=amount;}
        void addPlayer(Player &player){_players.push_back(player);}

};

//operators
inline std::ostream& operator<<(std::ostream& os, const Board& board){
    os << "Nombre de joueurs: " << board.getNbPlayers() << std::endl;
    return os;
};

inline std::istream& operator>>(std::istream& is, Board& board){
    is >> board.nbPlayers;
    return is;
};
