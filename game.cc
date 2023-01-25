#include "game.hh"

//default constructor
Game::Game(){
    //initialize the random number generator
    srand(time(NULL));

    //initialize the game board
    std::cout << "Hello there and welcome to the game of xxx !" << std::endl;
    std::cout << "How many players are we playing with ? (2-4)" << std::endl;
    std::cin >> numPlayers;
    while(numPlayers < 2 || numPlayers > 4){
        std::cout << "Please enter a number between 2 and 4" << std::endl;
        std::cin >> numPlayers;
    }
    std::cout << "Great! We will be playing with " << numPlayers << " players." << std::endl;
    
}

//destructor
Game::~Game(){
    std::cout << "Thanks for playing!" << std::endl;
}