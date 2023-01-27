#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Player;
class Box;

class Board{
    protected:
        std::vector<Box> _boxes;
        std::map<int, Box> _boxesMap;
        int _whosPlaying;  //à qui le tour
        int _taxMoney;  //argent des taxes
        std::string _Message;  //message à afficher
        std::string _Message2;  //message à afficher
        std::string _Message3;  //message à afficher
        std::vector<Player> _players;  //joueurs

    public:
        int nbPlayers;
        int dice1;
        int dice2;

        Board();
        ~Board(){
            std::cout << "Destruction de Board" << std::endl;
        };
        void throwDices(Player &player){
            //réinitialisation du rand
            srand(time(NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            while(dice1 == dice2){
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;
            }
        };

        //getters
        int getNbPlayers() const {return nbPlayers;}
        int getWhosPlaying() const {return _whosPlaying;}
        int getTaxMoney() const {return _taxMoney;}
        std::string getMessage() const {return _Message;}
        std::string getMessage2() const {return _Message2;}
        std::string getMessage3() const {return _Message3;}
        std::vector<Box> getBoxes() const {return _boxes;}
        std::vector<Player>& getPlayers() {return _players;} //pas de const car on modifie le vecteur
        std::map<int, Box>& getBoxesMap()  {return _boxesMap;}

        //setters
        void setNbPlayers(int nbPlayers){nbPlayers = nbPlayers;}
        void setWhosPlaying(int whosPlaying){_whosPlaying = whosPlaying;}
        void setMessage(std::string message){_Message = message;}
        void setMessage2(std::string message){_Message2 = message;}
        void setMessage3(std::string message){_Message3 = message;}
        

        //others
        void addTaxMoney(double amount) {_taxMoney+=amount;}
        void addPlayer(Player &player){_players.push_back(player);}

};

//surcharge d'opérateurs
inline std::ostream& operator<<(std::ostream& os, const Board& board){
    os << "Nombre de joueurs: " << board.getNbPlayers() << std::endl;
    return os;
};

inline std::istream& operator>>(std::istream& is, Board& board){
    is >> board.nbPlayers;
    return is;
};
