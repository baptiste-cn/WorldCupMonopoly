#include "box.hh"
#include "player.hh"

void interaction(FrenchStadiums* box, Player &player) {
    std::cout << "Vous êtes sur la case " << box->getName() << std::endl;
    std::cout << "Que voulez vous faire ?" << std::endl;
    std::cout << "1. Acheter le stade" << std::endl;
    std::cout << "2. Ne rien faire" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            if (player.getMoney() >= box->getPrice()) {
                player.addBox(*box);
                player.setMoney(player.getMoney() - box->getPrice());
                std::cout << "Vous avez acheté le stade " << box->getName() << std::endl;
            } else {
                std::cout << "Vous n'avez pas assez d'argent pour acheter ce stade" << std::endl;
            }
            break;
        case 2:
            std::cout << "Vous ne faites rien" << std::endl;
            break;
        default:
            std::cout << "Vous ne faites rien" << std::endl;
            break;
    }
}
