#include <stdio.h>
#include <stdlib.h>
#include "game.hh"
#include "board.hh"
#include "player.hh"
#include "box.hh"
// #include "interaction.hh"

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

    //boucle pour jouer
    while(1){
        for(auto it = playersAndScores.rbegin(); it != playersAndScores.rend(); ++it){
            for(int i = 0; i < board->nbPlayers; i++){
                if(it->second == board->getPlayers()[i].getName()){
                    std::cout << "It's " << board->getPlayers()[i].getName() << "'s turn." << std::endl;
                    std::cout << "You are on " << board->getBoxesMap()[board->getPlayers()[i].getActualPosition()].getBoxName() << "." << std::endl;
                    std::cout << "Press enter to roll the dice." << std::endl;
                    std::cin.ignore();
                    board->throwDices(board->getPlayers()[i]);
                    std::cout << "You rolled a " << board->dice1 << " and a " << board->dice2 << "." << std::endl;
                    board->getPlayers()[i].setActualPosition((board->getPlayers()[i].getActualPosition() + board->dice1 + board->dice2) % 40);  //modulo 40 afin de reset la position du joueur s'il passe un tour de plateau
                    std::cout << "You are now on " << board->getBoxesMap()[board->getPlayers()[i].getActualPosition()].getBoxName() << "." << std::endl;
                    std::cout << "Press enter to continue." << std::endl;
                    board->getBoxesMap()[board->getPlayers()[i].getActualPosition()].interaction(board->getPlayers()[i]);
                    std::cout << "-------------------------------------------" << std::endl;
                    std::cin.ignore();
                }
            }
        }
    }
    return 0;
}