#include "box.hh"
#include "player.hh"
#include <algorithm>

int interaction(FrenchStadiums *box, Player &player)
{
    std::cout << "Vous êtes sur la case " << box->getBoxName() << std::endl;
    // std::cout << "Que voulez vous faire ?" << std::endl;
    // std::cout << "1. Acheter le stade" << std::endl;
    // std::cout << "2. Ne rien faire" << std::endl;
    if (player.getMoney() >= box->getPrice() && box->getIsBought() == false)
    {
        std::cout << "Vous pouvez acheter le stade " << box->getBoxName() << " pour " << box->getPrice() << " M" << std::endl;
        return 2;
    }
    else
    {
        std::cout << "Vous ne pouvez pas acheter le stade " << box->getBoxName() << " pour " << box->getPrice() << " M" << std::endl;
        return 1;
    }
    if (std::find(player.getOwnedBoxes().begin(), player.getOwnedBoxes().end(), box) != player.getOwnedBoxes().end())
    { // chercher dans le vecteur de box du joueur
        std::cout << "Vous êtes propriétaire de ce stade" << std::endl;
        if (player.getMoney() >= box->getPriceUpgrade())
        { // méthode du prix de l'upgrade
            std::cout << "Vous pouvez upgrader le stade " << box->getBoxName() << " pour " << box->getPriceUpgrade() << " M" << std::endl;
            return 3;
        }
        else
        {
            std::cout << "Vous ne pouvez pas upgrader le stade " << std::endl;
            return 1;
        }
    }
    return 1;
}
    void acheter(FrenchStadiums * box, Player & player)
    {
        player.addBox(*box);
        player.setMoney(player.getMoney() - box->getPrice());
        std::cout << "Vous avez acheté le stade " << box->getBoxName() << std::endl;
    }

    void upgrader(FrenchStadiums * box, Player & player)
    {
        player.setMoney(player.getMoney() - box->getPriceUpgrade());
        box->setPriceUpgrade(box->getPriceUpgrade() * 2); // modifier les coefs comme sur le vrai monopoly
        box->setPrice(box->getPrice() * 2);               // modifier les coefs comme sur le vrai monopoly
        std::cout << "Vous avez upgradé le stade " << box->getBoxName() << std::endl;
    }