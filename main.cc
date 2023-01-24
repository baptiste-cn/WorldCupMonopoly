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
    std::cout << "How many players are there? (2-4)" << std::endl;
    std::cin >> board->nbPlayers;

    while(board->nbPlayers<2){
        std::cout << "There must be at least 2 players." << std::endl;
        std::cout << "How many players are there? (2-4)" << std::endl;
        std::cin >> board->nbPlayers;
    }
    while(board->nbPlayers>4){
        std::cout << "There must be at most 4 players." << std::endl;
        std::cout << "How many players are there? (2-4)" << std::endl;
        std::cin >> board->nbPlayers;
    }

    std::cout << "Enter the name of each player:" << std::endl;
    for(int i = 0; i < board->nbPlayers; i++){
        std::string name;
        std::cin >> name;
        Player* player = new Player(name);
        board->addPlayer(*player);
    }

    std::cout << "The game will start with " << board->nbPlayers << " players." << std::endl;
    std::cout << "Their names are: " << std::endl;
    for(auto& player: board->getPlayers()){
        std::cout << player.getName() << std::endl;
    }

    std::cout << "Let's start the game!" << std::endl;
    std::cout << "To determine the order of play, each player will roll the dice." << std::endl;
    std::cout << "The player with the highest roll will go first." << std::endl;
    std::cout << "The player with the lowest roll will go last." << std::endl;
    std::cout << "The other players will go in between." << std::endl;

    std::cin.ignore();
    int dices[board->nbPlayers];
    for(int index = 0; index < board->nbPlayers; index++){
        std::cout << board->getPlayers()[index].getName() << ", press enter to roll the dice." << std::endl;
        std::cin.ignore();
        board->throwDices(board->getPlayers()[index]);
        std::cout << "You rolled a " << board->dice1 << " and a " << board->dice2 << std::endl;
        dices[index] = board->dice1 + board->dice2;
    }

    //création d'un multimap pour stocker les joueurs et leur score
    std::multimap<int, std::string> playersAndScores;
    for(int i = 0; i < board->nbPlayers; i++){
        playersAndScores.insert(std::pair<int, std::string>(dices[i], board->getPlayers()[i].getName()));
    }

    //affichage des joueurs et de leur score dans l'ordre décroissant
    std::cout << "The order of play is: " << std::endl;
    for(auto it = playersAndScores.rbegin(); it != playersAndScores.rend(); ++it){
        std::cout << it->second << " with a roll of " << it->first << std::endl;
    }

    ////////////////////////////////////////////////////////////////////

    //création d'un vecteur d'itérateurs pour stocker les joueurs
    std::vector<std::vector<Player>::iterator> players_iterators;
    for (auto it = board->getPlayers().begin(); it != board->getPlayers().end(); ++it) {
        players_iterators.push_back(it);
    }
    while(1){
    for(auto it = players_iterators.begin(); it != players_iterators.end(); ++it) {
        std::cout << (*it)->getName() << ", press enter to roll the dice." << std::endl;
        std::cin.ignore();
        board->throwDices(**it);
        std::cout << "You rolled a " << board->dice1 << " and a " << board->dice2 << std::endl;
        (*it)->setActualPosition(((*it)->getActualPosition() + board->dice1 + board->dice2) % 40);  //modulo 40 afin de reset la position du joueur s'il passe un tour de plateau
        std::cout << "You are now on " << board->getBoxesMap()[(*it)->getActualPosition()].getBoxName() << std::endl;
        std::cout << board->getBoxesMap()[(*it)->getActualPosition()].getBoxNumber() << std::endl;
        //use of interaction function
        switch (board->getBoxes()[(*it)->getActualPosition()]->getBoxType()) {
            case FrenchStadium:
                static_cast<FrenchStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case SpanishStadium:
                static_cast<SpanishStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case BrazilianStadium:
                static_cast<BrazilianStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case EnglishStadium:
                static_cast<EnglishStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case DeutchStadium:
                static_cast<DeutchStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case ArgentinianStadium:
                static_cast<ArgentinianStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case RussianStadium:
                static_cast<RussianStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case SouthAfricanStadium:
                static_cast<SouthAfricanStadiums*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case VideoBoxType:
                static_cast<VideoBoxes*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case RepairBoxType:
                static_cast<RepairBoxes*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case StartBoxType:
                static_cast<StartBox*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case FreeParkBoxType:
                static_cast<FreePark*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case JailBoxType:
                static_cast<JailBox*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case RedCardBoxType:
                static_cast<RedCardBox*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case LotteryBoxType:
                static_cast<LotteryBoxes*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case TaxBoxType:
                static_cast<TaxBoxes*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
            case VisitBoxType:
                static_cast<VisitBox*>(board->getBoxes()[(*it)->getActualPosition()])->interaction(**it);
                break;
        }


        std::cout << "-------------------------------------------" << std::endl;
    }
}


    // for(auto& box: board->getBoxes()){
    //     std::cout << box.getBoxName() << std::endl;
    //     std::cout << box.getBoxNumber() << std::endl;
    // }
    
    return 0;
}