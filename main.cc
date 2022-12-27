#include <stdio.h>
#include <stdlib.h>
#include "game.hh"
#include "board.hh"
#include "player.hh"
#include "box.hh"


int main(){
    //Game();
    
    Board *board = new Board();  
    board->throwDice();
    FrenchStadiums FrenchStads;
    std::cout << "ID DEUXIEME CASE =" + FrenchStads.getFrenchStadiums().at(0).getBoxId() << std::endl;
    std::cout << FrenchStads.getFrenchStadiums().at(0);
    std::cout << FrenchStads.getFrenchStadiums().at(0).getBoxNumber() << std::endl;
    std::cout << FrenchStads.getFrenchStadiums().at(1).getBoxId() << std::endl;
    std::cout << FrenchStads.getFrenchStadiums().at(1);
    std::cout << FrenchStads.getFrenchStadiums().at(1).getBoxNumber() << std::endl;
    

    // while(1){
    //     //game loop
    // }
    return 0;
}






































