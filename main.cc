#include <stdio.h>
#include <stdlib.h>
#include "game.hh"
#include "board.hh"
#include "player.hh"
#include "box.hh"
#include "interaction.hh"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

Board *board = new Board();
int quit = 0;
SDL_Event event;
SDL_Event event2;
int mx, my;
char sendBuffer[256];
SDL_Surface *monopolyboard;
SDL_Texture *texture_monopolyboard;
SDL_Surface *p1;
SDL_Texture *texture_p1;
SDL_Surface *p2;
SDL_Texture *texture_p2;
SDL_Surface *p3;
SDL_Texture *texture_p3;
SDL_Surface *p4;
SDL_Texture *texture_p4;
SDL_Surface *gray;
SDL_Texture *texture_gray;
SDL_Surface *passerlamain;
SDL_Texture *texture_passerlamain;
SDL_Surface *acheterpropriete;
SDL_Texture *texture_acheterpropriete;
SDL_Surface *acheterstands;
SDL_Texture *texture_acheterstands;
TTF_Font *Sans;
char word[40];
int cptWord;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Rect PosP1 = {960, 30, 64, 64};
SDL_Rect PosP2 = {250, 300, 64, 64};
SDL_Rect PosP3 = {960, 30, 64, 64};
SDL_Rect PosP4 = {250, 300, 64, 64};
int affichage_interactions = 0; // 0 = lancer les dés | 1=passeer la main | 2=acheterlapropriété et passer la main | 3 = upgrade et passer la main

void init_sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window = SDL_CreateWindow("SDL2 LINQ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 1000, 0);

    renderer = SDL_CreateRenderer(window, -1, 0);
    monopolyboard = IMG_Load("boardmonopoly.png");
    texture_monopolyboard = SDL_CreateTextureFromSurface(renderer, monopolyboard);
    p1 = IMG_Load("p1.png");
    texture_p1 = SDL_CreateTextureFromSurface(renderer, p1);
    p2 = IMG_Load("p2.png");
    texture_p2 = SDL_CreateTextureFromSurface(renderer, p2);
    p3 = IMG_Load("p3.png");
    texture_p3 = SDL_CreateTextureFromSurface(renderer, p3);
    p4 = IMG_Load("p4.png");
    texture_p4 = SDL_CreateTextureFromSurface(renderer, p4);
    gray = IMG_Load("gray.png");
    texture_gray = SDL_CreateTextureFromSurface(renderer, gray);
    passerlamain = IMG_Load("passerlamain.png");
    texture_passerlamain = SDL_CreateTextureFromSurface(renderer, passerlamain);
    acheterpropriete = IMG_Load("acheterpropriete.png");
    texture_acheterpropriete = SDL_CreateTextureFromSurface(renderer, acheterpropriete);
    acheterstands = IMG_Load("acheterstands.png");
    texture_acheterstands = SDL_CreateTextureFromSurface(renderer, acheterstands);
    Sans = TTF_OpenFont("sans.ttf", 30);
}

void myRenderText(const char *m, int x, int y)
{
    SDL_Color col1 = {221, 184, 26};
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, m, col1);
    SDL_Texture *Message =
        SDL_CreateTextureFromSurface(renderer,
                                     surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = surfaceMessage->w;
    Message_rect.h = surfaceMessage->h;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
}

void myRenderText2(const char *m, int x, int y)
{
    SDL_Color col1 = {134, 134, 134};
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, m, col1);
    SDL_Texture *Message =
        SDL_CreateTextureFromSurface(renderer,
                                     surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = surfaceMessage->w;
    Message_rect.h = surfaceMessage->h;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
}

void manageRedraw()
{
    int cntplayer = 0;
    for (auto it = board->getPlayers().begin(); it != board->getPlayers().end(); ++it) // Met à jour la position des joueurs
    {
        cntplayer++;
        int pos = (it)->getActualPosition();
        int x = 0;
        int y = 0;
        switch (pos)
        {
        case 0:
            x = 50;
            y = 880;
            break;
        case 1:
            x = 50;
            y = 780;
            break;
        case 2:
            x = 50;
            y = 700;
            break;
        case 3:
            x = 50;
            y = 625;
            break;
        case 4:
            x = 50;
            y = 550;
            break;
        case 5:
            x = 50;
            y = 470;
            break;
        case 6:
            x = 50;
            y = 390;
            break;
        case 7:
            x = 50;
            y = 310;
            break;
        case 8:
            x = 50;
            y = 235;
            break;
        case 9:
            x = 50;
            y = 160;
            break;
        case 10: // Case prison visite
            x = 20;
            y = 20;
            break;
        case 11:
            x = 160;
            y = 50;
            break;
        case 12:
            x = 235;
            y = 50;
            break;
        case 13:
            x = 315;
            y = 50;
            break;
        case 14:
            x = 390;
            y = 50;
            break;
        case 15:
            x = 470;
            y = 50;
            break;
        case 16:
            x = 545;
            y = 50;
            break;
        case 17:
            x = 625;
            y = 50;
            break;
        case 18:
            x = 704;
            y = 50;
            break;
        case 19:
            x = 779;
            y = 50;
            break;
        case 20: // Terrain Libre
            x = 885;
            y = 50;
            break;
        case 21:
            x = 885;
            y = 159;
            break;
        case 22:
            x = 885;
            y = 235;
            break;
        case 23:
            x = 885;
            y = 313;
            break;
        case 24:
            x = 885;
            y = 390;
            break;
        case 25:
            x = 885;
            y = 469;
            break;
        case 26:
            x = 885;
            y = 546;
            break;
        case 27:
            x = 885;
            y = 625;
            break;
        case 28:
            x = 885;
            y = 703;
            break;
        case 29:
            x = 885;
            y = 778;
            break;
        case 30: // Carton jaune
            x = 885;
            y = 880;
            break;
        case 31:
            x = 779;
            y = 880;
            break;
        case 32:
            x = 704;
            y = 880;
            break;
        case 33:
            x = 625;
            y = 880;
            break;
        case 34:
            x = 547;
            y = 880;
            break;
        case 35:
            x = 470;
            y = 880;
            break;
        case 36:
            x = 392;
            y = 880;
            break;
        case 37:
            x = 314;
            y = 880;
            break;
        case 38:
            x = 236;
            y = 880;
            break;
        case 39:
            x = 159;
            y = 880;
            break;
        case 99:
            x = 88;
            y = 88;
            break;
        }
        switch (cntplayer)
        {
        case 1:
            PosP1 = {x, y, 64, 64};
            break;
        case 2:
            PosP2 = {x, y, 64, 64};
            break;
        case 3:
            PosP3 = {x, y, 64, 64};
            break;
        case 4:
            PosP4 = {x, y, 64, 64};
            break;
        }
    }
    // Affiche les textures
    SDL_RenderCopy(renderer, texture_monopolyboard, NULL, NULL);
    SDL_RenderCopy(renderer, texture_p1, NULL, &PosP1);
    SDL_RenderCopy(renderer, texture_p2, NULL, &PosP2);
    if (board->nbPlayers > 2)
    {
        SDL_RenderCopy(renderer, texture_p3, NULL, &PosP3);
        if (board->nbPlayers > 3)
        {
            SDL_RenderCopy(renderer, texture_p4, NULL, &PosP4);
        }
    }
    // Affichage des interactions:
    if (affichage_interactions == 1)
        SDL_RenderCopy(renderer, texture_passerlamain, NULL, NULL);
    if (affichage_interactions == 2)
        SDL_RenderCopy(renderer, texture_acheterpropriete, NULL, NULL);
    if (affichage_interactions == 3)
        SDL_RenderCopy(renderer, texture_acheterstands, NULL, NULL);
    if (affichage_interactions == 4){
        SDL_RenderCopy(renderer, texture_passerlamain, NULL, NULL);
        SDL_RenderCopy(renderer, texture_gray, NULL, NULL);
        myRenderText((board->getMessage()).c_str(), 225, 450);
        myRenderText((board->getMessage2()).c_str(), 225, 490);
        myRenderText((board->getMessage3()).c_str(), 225, 530);
    }
    // Affiche les textes
    myRenderText((std::to_string(board->getPlayers()[board->getWhosPlaying()].getMoney())+" M").c_str(), 1198, 163);
    myRenderText(board->getPlayers()[board->getWhosPlaying()].getName().c_str(), 1291, 227);
    int xcnt = 1008;
    int ycnt = 325;
    for (int i = 0; i < 40; i++)
    {
        if (board->getBoxesMap()[i].getOwner() == board->getPlayers()[board->getWhosPlaying()].getName())
        {
            myRenderText((board->getBoxesMap()[i].getBoxName()).c_str(), xcnt, ycnt);
            ycnt += 25;
        }
    }
    // Render Properties infos
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == PropertyBox)
    {
        int id = board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxId();
        if (id == 5 || id == 15 || id == 25 || id == 35)
        {
        }
        else
        {
            myRenderText(board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxName().c_str(), 1010, 790);
            // Attrubutes names:
            myRenderText2("Price:", 1010, 820);
            myRenderText2("Rent:", 1010, 850);
            myRenderText2("Price for Upgrades:", 1010, 880);
            // attributes values:
            myRenderText((std::to_string(board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getPrice()) + " M").c_str(), 1120, 820);
            myRenderText((std::to_string((board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getRent())*(board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getNbUpgrades()*7+1)) + " M").c_str(), 1110, 850);
            myRenderText((std::to_string(board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getPriceUpgrade()) + " M").c_str(), 1360, 880);
        }
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == StartBoxType)
    {
        myRenderText("Start: Recevez 200 M lorsque", 1010, 780);
        myRenderText("vous passez par cette case", 1010, 810);
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == PenaltyBoxType && board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxId() == 30)
    {
        myRenderText("Simple Visite", 1010, 780); // Indiquer le nombre de cartons jaunes
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == PenaltyBoxType && board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxId() == 99)
    {
        myRenderText("TUUUT Carton rouge", 1010, 780); // Indiquer le nombre de cartons jaunes
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == RedCardBoxType)
    {
        myRenderText("Carton Rouge", 1010, 780); // ajouter le nb de tours
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == FreeParkBox)
    {
        myRenderText("Terrain Libre: Recuperez tout ce ", 1010, 780); // ajouter l'argent reçu
        myRenderText("que vous trouvez sur le terrain", 1010, 810);   // ajouter l'argent reçu
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == LotteryBoxType)
    {
        myRenderText("Lotterie", 1010, 780); // ajouter l'evenement
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == TaxBoxType)
    {
        myRenderText("Ouch ! Vous payez des taxes", 1010, 780); // ajouter l'argent retiré
    }
    if (board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxType() == VisitBoxType)
    {
        myRenderText("Simple Visite", 1010, 780); // ajouter l'argent retiré
    }
    // Show what was drawn
    std::cout << "Render" << std::endl;
    SDL_RenderPresent(renderer);
}

int main()
{

    // boucle pour rentrer les joueurs et le nombre total de joueurs
    std::cout << "Welcome to Monopoly!" << std::endl;
    std::cout << "How many players are there? (2-4)" << std::endl;
    std::cin >> board->nbPlayers;

    while (board->nbPlayers < 2)
    {
        std::cout << "There must be at least 2 players." << std::endl;
        std::cout << "How many players are there? (2-4)" << std::endl;
        std::cin >> board->nbPlayers;
    }
    while (board->nbPlayers > 4)
    {
        std::cout << "There must be at least 2 players." << std::endl;
        std::cout << "How many players are there? (2-4)" << std::endl;
        std::cin >> board->nbPlayers;
    }

    std::cout << "Enter the name of each player:" << std::endl;
    for (int i = 0; i < board->nbPlayers; i++)
    {
        std::string name;
        std::cin >> name;
        Player *player = new Player(name);
        board->addPlayer(*player);
    }

    std::cout << "The game will start with " << board->nbPlayers << " players." << std::endl;
    std::cout << "Their names are: " << std::endl;
    for (auto &player : board->getPlayers())
    {
        std::cout << player.getName() << std::endl;
    }

    std::cout << "Let's start the game!" << std::endl;
    std::cout << "To determine the order of play, each player will roll the dice." << std::endl;
    std::cout << "The player with the highest roll will go first." << std::endl;
    std::cout << "The player with the lowest roll will go last." << std::endl;
    std::cout << "The other players will go in between." << std::endl;

    std::cin.ignore();
    int dices[board->nbPlayers];
    for (int index = 0; index < board->nbPlayers; index++)
    {
        std::cout << board->getPlayers()[index].getName() << ", press enter to roll the dice." << std::endl;
        std::cin.ignore();
        board->throwDices(board->getPlayers()[index]);
        std::cout << "You rolled a " << board->dice1 << " and a " << board->dice2 << std::endl;
        dices[index] = board->dice1 + board->dice2;
    }

    // création d'un multimap pour stocker les joueurs et leur score
    std::multimap<int, std::string> playersAndScores;
    for (int i = 0; i < board->nbPlayers; i++)
    {
        playersAndScores.insert(std::pair<int, std::string>(dices[i], board->getPlayers()[i].getName()));
    }

    // affichage des joueurs et de leur score dans l'ordre décroissant
    std::cout << "The order of play is: " << std::endl;
    for (auto it = playersAndScores.rbegin(); it != playersAndScores.rend(); ++it)
    {
        std::cout << it->second << " with a roll of " << it->first << std::endl;
    }

    ////////////////////////////////////////////////////////////////////

    // création d'un vecteur d'itérateurs pour stocker les joueurs
    std::vector<std::vector<Player>::iterator> players_iterators;
    for (auto it = board->getPlayers().begin(); it != board->getPlayers().end(); ++it)
    {
        players_iterators.push_back(it);
    }
    // Initialisation de l'image
    init_sdl();

    // ==================================TO REMOVE==================================
    board->getPlayers()[0].addMoney(1500);
    board->getPlayers()[1].addMoney(1500);
    // ==============================================================================
    manageRedraw();
    while (!quit)
    {
        SDL_PumpEvents();
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                manageRedraw();
                SDL_GetMouseState(&mx, &my);
                if (affichage_interactions == 0)
                {
                    if ((mx > 1036 && mx < 1600) && (my < 150)) // Bouton lancer les dés
                    {
                        if((board->getPlayers()[board->getWhosPlaying()]).getIsJailed()==true){
                            board->getPlayers()[board->getWhosPlaying()].setDaysInJail(board->getPlayers()[board->getWhosPlaying()].getDaysInJail()-1);
                            if(board->getPlayers()[board->getWhosPlaying()].getDaysInJail() == 0){
                                board->getPlayers()[board->getWhosPlaying()].setIsJailed(false);
                                board->getPlayers()[board->getWhosPlaying()].setActualPosition(10);
                            }
                            affichage_interactions = board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()].interaction(board->getPlayers()[board->getWhosPlaying()],*board);
                        }
                        else{
                        board->throwDices(board->getPlayers()[board->getWhosPlaying()]);
                        std::cout << "You rolled a " << board->dice1 << " and a " << board->dice2 << std::endl;
                        (board->getPlayers()[board->getWhosPlaying()]).setActualPosition(((board->getPlayers()[board->getWhosPlaying()]).getActualPosition() + board->dice1 + board->dice2) % 40); // modulo 40 afin de reset la position du joueur s'il passe un tour de plateau
                        std::cout << "You are now on " << board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxName() << std::endl;
                        std::cout << board->getBoxesMap()[(board->getPlayers()[board->getWhosPlaying()]).getActualPosition()].getBoxNumber() << std::endl;
                        affichage_interactions = board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()].interaction(board->getPlayers()[board->getWhosPlaying()],*board);
                        }
                        std::cout << "-------------------------------------------" << std::endl;
                        manageRedraw();
                    }
                }
                else
                {
                    if ((mx > 1037 && mx < 1270) && (my < 150)) // Bouton Acheter Propriete/upgrader
                    {
                        if (affichage_interactions == 2)
                        {
                            std::cout << board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()].getBoxNumber() << std::endl;
                            std::cout << board->getPlayers()[board->getWhosPlaying()].getActualPosition() << std::endl;
                            board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()];
                            (board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()]).acheter(board->getPlayers()[board->getWhosPlaying()]);
                            std::cout << "le proprietaire est " << board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()].getOwner() << std::endl;
                        }
                        else if (affichage_interactions == 3)
                        {
                            board->getBoxesMap()[board->getPlayers()[board->getWhosPlaying()].getActualPosition()].upgrader(board->getPlayers()[board->getWhosPlaying()]);
                        }
                        // Ajouter un delay pour confirmer achat et affichage
                        board->setWhosPlaying((board->getWhosPlaying() + 1) % board->getPlayers().size());
                        std::cout << "Acheter/Upgrader" << std::endl;
                        affichage_interactions = 0;
                    }
                    if ((mx > 1329 && mx < 1600) && (my < 150)) // Bouton lancer les dés
                    {
                        board->setWhosPlaying((board->getWhosPlaying() + 1) % board->getPlayers().size());
                        std::cout << "Passer la main" << std::endl;
                        affichage_interactions = 0;
                    }
                }
                manageRedraw();
                break;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}



/*
Affichage des cases water et electrecity
Afficahge différents des cases vidéo et pauement
Afficher les propriétés d'un joueur de la couleur du joueur
Afficher les dés

Modifier box.hh et Box.cc pour faire payer et mettre le prix proportionel au nb de cases vidéos


*/