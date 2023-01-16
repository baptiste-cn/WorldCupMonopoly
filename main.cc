#include <stdio.h>
#include <stdlib.h>
#include "game.hh"
#include "board.hh"
#include "player.hh"
#include "box.hh"


int main(){

    Board *board = new Board();  
    //boucle pour rentrer les joueurs et le nombre total de joueurs
    std::cout << "Welcome to Monopoly!" << std::endl;
    std::cout << "How many players are there?" << std::endl;
    std::cin >> board->nbPlayers;
    std::cout << "Enter the name of each player:" << std::endl;
    for(int i = 0; i < board->nbPlayers; i++){
        std::string name;
        std::cin >> name;
        Player player(name);
        board->addPlayer(player);
    }

    std::cout << "The game will start with " << board->nbPlayers << " players." << std::endl;
    std::cout << "Their names are: " << std::endl;
    for(auto& player: board->getPlayers()){
        std::cout << player.getName() << std::endl;
    }

    std::cout << "Let's start the game!" << std::endl;
    board->throwDice();


    // FrenchStadiums FrenchStads;
    // std::cout << "ID DEUXIEME CASE =" + FrenchStads.getFrenchStadiums().at(0).getBoxId() << std::endl;
    // std::cout << FrenchStads.getFrenchStadiums().at(0);
    // std::cout << FrenchStads.getFrenchStadiums().at(0).getBoxNumber() << std::endl;
    // std::cout << FrenchStads.getFrenchStadiums().at(1).getBoxId() << std::endl;
    // std::cout << FrenchStads.getFrenchStadiums().at(1);
    // std::cout << FrenchStads.getFrenchStadiums().at(1).getBoxNumber() << std::endl;

    for(auto& box: board->getBoxes()){
        std::cout << box.getBoxName() << std::endl;
        std::cout << box.getBoxNumber() << std::endl;
    }
    

    // while(1){
    //     //game loop
    // }
    return 0;
}






































