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
    PenaltyBox,
    FreeParkBox,
    JailBoxType,
    RedCardBoxType,
    LotteryBoxType,
    TaxBoxType,
    VisitBoxType
};

class Box
{
    static unsigned int cpt;
    std::string _owner; 

protected:
    double _price;
    int _priceupgrade;
    int _boxId;
    std::string _boxName;
    int _boxNumber;
    int _boxType;
    double _mortgagePrice; // prix hypothèque
    bool _isBought;
    int _rent;
    int _nbStands = 0; // nb de stands (maisons) posées sur la carte (max 4) (0 par défaut)
    int _nbHotels = 0; // nb d'hôtels posés sur la carte (max 1) (0 par défaut)

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
    double getPrice() { return _price; } // pas de const : on va modifier le prix des cases
    double getMortgagePrice() const { return _mortgagePrice; }
    bool getIsBought() const { return _isBought; }
    int getRent() const { return _rent; }
    int getPriceUpgrade() const { return _priceupgrade; }
    std::string getOwner() const { return _owner; }

    // setters
    void setBoxNumber(int boxNumber) { _boxNumber = boxNumber; }
    void setBoxName(std::string name) { _boxName = name; }
    void setBoxId(int boxId) { _boxId = boxId; }
    void setBoxType(BoxType boxType) { _boxType = boxType; }
    void setPrice(double price) { _price = price; }
    void setMortgagePrice(double mortgagePrice) { _mortgagePrice = mortgagePrice; }
    void setIsBought(bool bought) { _isBought = bought; }
    void setRent(int rent) { _rent = rent; }
    void setPriceUpgrade(int priceupgrade) { _priceupgrade = priceupgrade; }
    void setOwner(std::string owner) { _owner = owner; }

    int interaction(Player &player)
    {
        std::cout << "Vous êtes sur la case " << this->getBoxName() << std::endl;
        // std::cout << "Que voulez vous faire ?" << std::endl;
        // std::cout << "1. Acheter le stade" << std::endl;
        // std::cout << "2. Ne rien faire" << std::endl;
        if (player.getMoney() >= this->getPrice() && this->getIsBought() == false)
        {
            std::cout << "Vous pouvez acheter le stade " << this->getBoxName() << " pour " << this->getPrice() << " M" << std::endl;
            return 2;
        }
        else
        {
            std::cout << "Vous ne pouvez pas acheter le stade " << this->getBoxName() << " pour " << this->getPrice() << " M" << std::endl;
            return 1;
        }
        if (this->getOwner() == player.getName())
        { // chercher dans le vecteur de box du joueur
            std::cout << "Vous êtes propriétaire de ce stade" << std::endl;
            if (player.getMoney() >= this->getPriceUpgrade())
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
        return 1;
    }
    void acheter(Player & player)
    {
        player.addBox(*this);
        this->setIsBought(true);
        this->setOwner(player.getName());
        player.setMoney(player.getMoney() - this->getPrice());
        std::cout << "Vous avez acheté le stade " << this->getBoxName() << std::endl;
        std::cout << "Il vous reste " << player.getMoney() << std::endl;
    }

    void upgrader(Player & player)
    {
        player.setMoney(player.getMoney() - this->getPriceUpgrade());
        this->setPriceUpgrade(this->getPriceUpgrade() * 2); // modifier les coefs comme sur le vrai monopoly
        this->setPrice(this->getPrice() * 2);               // modifier les coefs comme sur le vrai monopoly
        std::cout << "Vous avez upgradé le stade " << this->getBoxName() << std::endl;
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

class JailBox : public Box
{
public:
    // constructors
    JailBox()
    {
        setBoxName("Jail Box");
        setBoxNumber(99);
        setBoxType(JailBoxType);
    }
    ~JailBox(){};
};

class RedCardBox : public Box
{
public:
    // constructors
    RedCardBox()
    {
        setBoxName("Red Card Box");
        setBoxNumber(30);
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

    void addTaxMoney(Board &board) { board.addTaxMoney(200); }

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