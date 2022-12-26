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
    std::cout << FrenchStads.getFrenchStadiums().at(0);
    //FrenchStads.getFrenchStadiums()[0];
    

    // while(1){
    //     //game loop
    // }
    return 0;
}






































