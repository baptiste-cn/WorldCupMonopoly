#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "board.hh"
#include "player.hh"

enum BoxType
{
    StartBoxType,
    PropertyBox,
    PenaltyBoxType,
    FreeParkBox,
    RedCardBoxType,
    LotteryBoxType,
    TaxBoxType,
    RepairBoxType,
    VisitBoxType
};

class Box
{
    static unsigned int cpt;

protected:
    int _price;
    int _priceupgrade;
    int _boxId;
    std::string _boxName = "none";
    std::string _owner = "none";
    int _boxNumber;
    int _boxType;
    double _mortgagePrice; // prix hypothèque
    bool _isBought;
    int _rent;
    int _nbUpgrades = 0; //0 : pas de stand, 1 : 1 stand, 2 : 2 stands, 3 : 3 stands, 4 : 4 stands, 5 : 1 hotel

public:
    // constructors
    Box();
    Box(std::string name) { setBoxName(name); }
    ~Box(){};

    // getters
    int getBoxNumber() const { return _boxNumber; }
    std::string getBoxName() const { return _boxName; }
    int getBoxId() const { return _boxId; }
    int getBoxType() const { return _boxType; }
    int getPrice() { return _price; } // pas de const : on va modifier le prix des cases
    double getMortgagePrice() const { return _mortgagePrice; }
    bool getIsBought() const { return _isBought; }
    int getRent() const { return _rent; }
    int getPriceUpgrade() const { return _priceupgrade; }
    std::string getOwner() const { return _owner; }
    int getNbUpgrades() {return _nbUpgrades;}

    // setters
    void setBoxNumber(int boxNumber) { _boxNumber = boxNumber; }
    void setBoxName(std::string name) { _boxName = name; }
    void setBoxId(int boxId) { _boxId = boxId; }
    void setBoxType(BoxType boxType) { _boxType = boxType; }
    void setPrice(int price) { _price = price; }
    void setMortgagePrice(double mortgagePrice) { _mortgagePrice = mortgagePrice; }
    void setIsBought(bool bought) { _isBought = bought; }
    void setRent(int rent) { _rent = rent; }
    void setPriceUpgrade(int priceupgrade) { _priceupgrade = priceupgrade; }
    void setOwner(std::string owner) { std::cout << "Owner mis à jour" << std::endl; _owner = owner; }
    void setNbUpgrades(int nbUpgrades) {_nbUpgrades = nbUpgrades;}

    void addTaxMoney(Board &board) { board.addTaxMoney(200); }

    int interaction(Player &player, Board &board)
    {
        std::cout << "Vous êtes sur la case " << this->getBoxName() << std::endl;
        // std::cout << "Que voulez vous faire ?" << std::endl;
        // std::cout << "1. Acheter le stade" << std::endl;
        // std::cout << "2. Ne rien faire" << std::endl;

        if (this->getOwner() == player.getName() && this->getBoxType() == PropertyBox) // Si le joueur est propriétaire du stade essayer de l'upgrader
        {                                                                              // chercher dans le vecteur de box du joueur
            std::cout << "Vous êtes propriétaire de ce stade" << std::endl;
            if (player.getMoney() >= this->getPriceUpgrade() && this->getNbUpgrades() <= 5)
            { // méthode du prix de l'upgrade
                std::cout << "Vous pouvez upgrader le stade " << this->getBoxName() << " pour " << this->getPriceUpgrade() << " M" << std::endl;
                return 3;
            }
            else
            {
                std::cout << "Vous ne pouvez pas upgrader le stade " << std::endl;
                return 1;
            }
        }
        else if (player.getMoney() >= this->getPrice() && this->getIsBought() == false && this->getBoxType() == PropertyBox) // Acheter un stade
        {
            std::cout << "Vous pouvez acheter le terrain " << this->getBoxName() << " pour " << this->getPrice() << " M" << std::endl;
            return 2;
        }
        else if (this->getIsBought() == true && this->getOwner() != player.getName() && this->getBoxType() == PropertyBox) //Payer un stade
        { // Payer l'autre joueur pour un stade
        
            board.setMessage("Vous etes sur la case");
            board.setMessage2("de "+this->getOwner());
            board.setMessage3("Vous payez donc " + std::to_string(this->getRent()*(this->getNbUpgrades()*7+1)) + " M");
            std::cout << "Vous êtes sur la case " << this->getBoxName() << " qui appartient à " << this->getOwner() << std::endl;
            std::cout << "Vous payez donc " << this->getRent()*(this->getNbUpgrades()*7+1) << " M" << std::endl;
            player.setMoney(player.getMoney() - this->getRent()*(this->getNbUpgrades()*7+1));
            return 4;
        }
        else if (player.getMoney() >= this->getPrice() && this->getIsBought() == false && this->getBoxType() == RepairBoxType) // Acheter la case water ou electricity
        {
            std::cout << "Vous pouvez acheter le terrain " << this->getBoxName() << " pour " << this->getPrice() << " M" << std::endl;
            return 2;
        }
        else if (this->getIsBought() == true && this->getBoxType() == RepairBoxType && this->getOwner() != player.getName()) // Payer la case water ou electricity à l'autre joueur
        {
            
            board.setMessage("Vous etes sur la case");
            board.setMessage2("de "+this->getOwner());
            board.setMessage3("Vous payez donc " + std::to_string(this->getRent() * (board.dice1 + board.dice2) ) + " M");
            std::cout << "Vous êtes sur la case " << this->getBoxName() << " qui appartient à " << this->getOwner() << std::endl;
            std::cout << "Vous payez donc " << this->getRent() * (board.dice1 + board.dice2) << " M" << std::endl;
            player.setMoney(player.getMoney() - (this->getRent() * (board.dice1 + board.dice2)));
            return 4;
        }
        else if (this->getBoxType() == StartBoxType)
        {
            std::cout << "Vous êtes sur la case départ, vous empochez donc 200 M" << std::endl;
            player.setMoney(player.getMoney() + 200);
            return 1;
        }
        else if (this->getBoxType() == VisitBoxType)
        {
            std::cout << "Vous êtes sur la case visite" << std::endl;
            return 1;
        }
        else if (this->getBoxType() == FreeParkBox)
        {
            board.setMessage("Vous etes sur la Terrain Libre,");
            board.setMessage2("vous empochez l'argent du plateau,");
            board.setMessage3("soit :" + std::to_string(board.getTaxMoney()) + " M");
            std::cout << "Vous êtes sur la case parc gratuit, vous empochez l'argent du plateau, soit " << board.getTaxMoney() << " M" << std::endl;
            player.setMoney(player.getMoney() + board.getTaxMoney());
            return 4;
        }
        else if (this->getBoxType() == TaxBoxType)
        {
            std::cout << "Vous êtes sur la case taxe, vous perdez 100 M" << std::endl;
            player.setMoney(player.getMoney() - 100);
            board.addTaxMoney(100);
            return 1;
        }
        else if (this->getBoxType() == LotteryBoxType)
        {
            std::cout << "Vous participez aux festivités locales !" << std::endl;
            int random = rand() % 4 + 1;
            if (random == 0)
            {
                board.setMessage("Vous devez cotiser pour");
                board.setMessage2("l'entretien du terrain : -50 M");
                board.setMessage3(" ");
                std::cout << "Vous devez cotiser pour l'entretien du terrain : -50 M" << std::endl;
                player.setMoney(player.getMoney() - 50);
            }
            else if (random == 1)
            {
                board.setMessage("Felicitations ! Vous avez gagne");
                board.setMessage2(" le concours de dribble : + 30 M");
                board.setMessage3(" ");
                std::cout << "Félicitations ! Vous avez gagné le concours de dribble : + 30 M" << std::endl;
                player.setMoney(player.getMoney() + 30);
            }
            else if (random == 2)
            {
                board.setMessage("Vous recuperez vos gains sur");
                board.setMessage2("le pari du match en cours : +20 M");
                board.setMessage3(" ");
                std::cout << "Vous récupérez vos gains sur le pari du match en cours : +20 M" << std::endl;
                player.setMoney(player.getMoney() + 20);
            }
            else if (random == 3)
            {
                board.setMessage("Le tacle par derriere deux pieds");
                board.setMessage2("decolles n'a jamais ete un ");
                board.setMessage3("geste technique... Carton rouge !");
                std::cout << "Le tacle par derrière deux pieds décollés n'a jamais été un geste technique... Carton rouge !" << std::endl;
                player.setActualPosition(99);
                player.setIsJailed(true);
                player.setDaysInJail(3);
            }
            else if (random == 4)
            {
                board.setMessage("Quelle faute lamentable ! Vous");
                board.setMessage2("alliez de marquer... Direction la ");
                board.setMessage3("case depart pour vous retablir");
                player.setMoney(player.getMoney() + 200);
                std::cout << "Quelle faute lamentable ! Vous étiez sur le point de marquer... Direction la case départ pour vous rétablir" << std::endl;
                player.setActualPosition(0);
            }
            return 4;
        }
        else if (this->getBoxType() == PenaltyBoxType)
        {
            
            board.setMessage("Vous avez recu");
            board.setMessage2("un Carton rouge !");
            board.setMessage3(" ");
            std::cout << "Vous avez reçu un carton rouge, direction la prison !" << std::endl;
            player.setIsJailed(true);
            player.setActualPosition(99);
            player.setDaysInJail(3);
            return 4;
        }
        else if (this->getBoxType() == RedCardBoxType)
        {
            board.setMessage("Vous etes toujours en prison !");
            board.setMessage2("Vous sortez dans ");
            board.setMessage3(std::to_string(player.getDaysInJail()) + " tours.");
            std::cout << "Vous êtes toujours en prison ! Vous sortez dans " << player.getDaysInJail() << " tours." << std::endl;
            return 4;
        }
        else
        {
            std::cout << "Vous ne pouvez pas acheter le terrain " << std::endl;
            return 1;
        }

        // Argent négatif
        int i = player.getOwnedBoxes().size();

        if (i)
        { // on regarde si le joueur possède des propriétés
            std::cout << "Plus d'argent" << std::endl;
            while (player.getMoney() < 0)
            {
                if (player.getOwnedBoxes()[i]->getNbUpgrades()) // si oui, on regarde s'il possède des upgrades
                {
                    player.getOwnedBoxes()[i]->setNbUpgrades(player.getOwnedBoxes()[i]->getNbUpgrades() - 1);
                    player.setMoney(player.getMoney() + (player.getOwnedBoxes()[i]->getPriceUpgrade()) / 2); // on lui revend (à moitié prix) ensuite toutes ses upgrades jusqu'à ce qu'il puisse payer
                }

                player.getOwnedBoxes()[i]->setIsBought(false); // on lui revend (à moitié prix) ensuite toutes ses propriétés jusqu'à ce qu'il puisse payer
                player.setMoney(player.getMoney() + (player.getOwnedBoxes()[i]->getPrice() / 2));

                if (!i)
                { // si le joueur ne peut plus rien vendre et ne peut toujours pas payer
                    player.setBankrupt(true);
                }
            }
        }

        return 1;
    }
    void acheter(Player &player)
    {
        player.addBox(*this);
        this->setIsBought(true);
        this->setOwner(player.getName());
        std::cout << "Le propriétaire est " << this->getOwner() << std::endl;
        player.setMoney(player.getMoney() - this->getPrice());
        std::cout << "Vous avez acheté le terrain " << this->getBoxName() << std::boolalpha << this->getIsBought() << std::endl;
        std::cout << "Il vous reste " << player.getMoney() << std::endl;
    }

    void upgrader(Player &player)
    {
        player.setMoney(player.getMoney() - this->getPriceUpgrade());
        this->setNbUpgrades(this->getNbUpgrades() + 1);
        std::cout << "Vous avez upgradé le terrain " << this->getBoxName() << std::endl;
    }
};

class FrenchStadiums : public Box
{
public:
    // constructors
    FrenchStadiums();
    ~FrenchStadiums(){};

    // getters
    std::vector<Box> getFrenchStadiums() const { return _frenchStadiums; }

protected:
    std::vector<Box> _frenchStadiums;
};

class SpanishStadiums : public Box
{
public:
    // constructors
    SpanishStadiums();
    ~SpanishStadiums(){};

    // getters
    std::vector<Box> getSpanishStadiums() const { return _spanishStadiums; }

protected:
    std::vector<Box> _spanishStadiums;
};

class BrazilianStadiums : public Box
{
public:
    // constructors
    BrazilianStadiums();
    ~BrazilianStadiums(){};

    // getters
    std::vector<Box> getBrazilianStadiums() const { return _brazilianStadiums; }

protected:
    std::vector<Box> _brazilianStadiums;
};

class EnglishStadiums : public Box
{
public:
    // constructors
    EnglishStadiums();
    ~EnglishStadiums(){};

    // getters
    std::vector<Box> getEnglishStadiums() const { return _englishStadiums; }

protected:
    std::vector<Box> _englishStadiums;
};

class DeutchStadiums : public Box
{
public:
    // constructors
    DeutchStadiums();
    ~DeutchStadiums(){};

    // getters
    std::vector<Box> getDeutchStadiums() const { return _deutchStadiums; }

protected:
    std::vector<Box> _deutchStadiums;
};

class ArgentinianStadiums : public Box
{
public:
    // constructors
    ArgentinianStadiums();
    ~ArgentinianStadiums(){};

    // getters
    std::vector<Box> getArgentinianStadiums() const { return _argentinianStadiums; }

protected:
    std::vector<Box> _argentinianStadiums;
};

class RussianStadiums : public Box
{
public:
    // constructors
    RussianStadiums();
    ~RussianStadiums(){};

    // getters
    std::vector<Box> getRussianStadiums() const { return _russianStadiums; }

protected:
    std::vector<Box> _russianStadiums;
};

class SouthAfricanStadiums : public Box
{
public:
    // constructors
    SouthAfricanStadiums();
    ~SouthAfricanStadiums(){};

    // getters
    std::vector<Box> getSouthAfricanStadiums() const { return _southAfricanStadiums; }

protected:
    std::vector<Box> _southAfricanStadiums;
};

/*cases similaires aux gares : si on tombe dessus on doit payer pour regarder des archives de matches.
Il y a 4 cases vidéos : en avoir n multiplie par n le loyer si un joueur tombe sur une des 4
*/

class VideoBox : public Box
{
public:
    // constructors
    VideoBox(){};               //{_boxId = cpt++;};
    VideoBox(std::string name); //{setBoxName(name); _boxId = cpt++;}
};

class VideoBoxes : public VideoBox
{
public:
    // constructors
    VideoBoxes(); //{_boxId = cpt++;};

    // getters
    std::vector<VideoBox> getVideoBoxes() const { return _videoBoxes; }

protected:
    std::vector<VideoBox> _videoBoxes;
};

class RepairBox : public Box
{
public:
    // constructors
    RepairBox(){};
    RepairBox(std::string name);
};

class RepairBoxes : public RepairBox
{
public:
    // constructors
    RepairBoxes();

    // getters
    std::vector<RepairBox> getRepairBoxes() const { return _repairBoxes; }

protected:
    std::vector<RepairBox> _repairBoxes;
};

class StartBox : public Box
{
public:
    // constructors
    StartBox()
    {
        setBoxName("Start Box");
        setBoxNumber(0);
        setBoxType(StartBoxType);
    }
    ~StartBox(){};
};

class FreePark : public Box
{
public:
    // constructors
    FreePark()
    {
        setBoxName("Free Park");
        setBoxNumber(20);
        setBoxType(FreeParkBox);
    }
    ~FreePark(){};
};

class RedCardBox : public Box
{
public:
    // constructors
    RedCardBox()
    {
        setBoxName("Red Card Box");
        setBoxNumber(99);
        setBoxType(RedCardBoxType);
    }
    ~RedCardBox(){};
};

class LotteryBox : public Box
{
public:
    // constructors
    LotteryBox() {}
    LotteryBox(std::string name);
};

class PenaltyBox : public Box
{
public:
    // constructors
    PenaltyBox()
    {
        setBoxName("Penalty Box");
        setBoxNumber(30);
        setBoxType(PenaltyBoxType);
    }
    ~PenaltyBox(){};
};

class LotteryBoxes : public LotteryBox
{
public:
    // constructors
    LotteryBoxes();

    // getters
    std::vector<LotteryBox> getLotteryBoxes() const { return _lotteryBoxes; }

protected:
    std::vector<LotteryBox> _lotteryBoxes;
};

class TaxBox : public Box
{
public:
    // constructors
    TaxBox() {}
    TaxBox(std::string name);
};

class TaxBoxes : public TaxBox
{
public:
    // constructors
    TaxBoxes();

    // getters
    std::vector<TaxBox> getTaxBoxes() const { return _taxBoxes; }

protected:
    std::vector<TaxBox> _taxBoxes;
};

class VisitBox : public Box
{
public:
    // constructors
    VisitBox()
    {
        setBoxName("Visit Box");
        setBoxNumber(10);
        setBoxType(VisitBoxType);
    }
    ~VisitBox() {}
};