#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "player.hh"

class Box{
    static unsigned int cpt;
    protected:
        int _boxId;
        std::string boxName;
        int _boxNumber;

    public:
        //constructors
        Box(){}; 
        ~Box(){};
        //pure virtual function
        virtual void addMoney(Player &player) = 0;

        //getters
        int getBoxNumber() const {return _boxNumber;}
        std::string getBoxName() const {return boxName;}
        int getBoxId() const {return _boxId;}    
        
        //setters
        void setBoxNumber(int boxNumber){_boxNumber = boxNumber;}
        void setBoxName(std::string name){boxName = name;}
        
};

class PropertyBox: public Box{
    protected:
        double _price;
        double _mortgagePrice;  //prix hypothèque
        bool isBought;

    public:
        //constructors
        PropertyBox(){};
        ~PropertyBox(){};

        //getters
        double getPrice() const {return _price;}
        double getMortgagePrice() const {return _mortgagePrice;}
        bool getIsBought() const {return isBought;}

        //setters
        void setPrice(double price){_price = price;}
        void setMortgagePrice(double mortgagePrice){_mortgagePrice = mortgagePrice;}
        void setIsBought(bool bought){isBought = bought;}
}; 

class StadiumBox: public PropertyBox{
    protected:
        int _nbStands = 0;  //nb de stands (maisons) posées sur la carte (max 4) (0 par défaut)
        int _nbHotels = 0;  //nb d'hôtels posés sur la carte (max 1) (0 par défaut)
        int _rent;

    public:
        //constructors
        StadiumBox(){}; //{_boxId = cpt++;};
        StadiumBox(std::string name); //{setBoxName(name); _boxId = cpt++;}

        void addMoney(Player &player){player.addMoney(player.getMoney() + _rent);}

        //getters
        //setters
        void setRent(int rent){_rent = rent;}

};

class FrenchStadiums: public StadiumBox{
    public:
        //constructors
        FrenchStadiums(){};// { StadiumBox("Parc des Princes"); StadiumBox("Stade de France"); }
        ~FrenchStadiums() {};
};

class SpanishStadiums: public StadiumBox{
    public:
        //constructors
        SpanishStadiums() {StadiumBox("Camp Nou"); StadiumBox("Santiago Bernabeu"); StadiumBox("Benito-Vallamarin");}
        ~SpanishStadiums() {};
};

class EnglishStadiums: public StadiumBox{
    public:
        //constructors
        EnglishStadiums() {StadiumBox("Wembley"); StadiumBox("Old Trafford"); StadiumBox("Anfield");}
        ~EnglishStadiums() {};
};


/*cases similaires aux gares : si on tombe dessus on doit payer pour regarder des archives de matches. 
Il y a 4 cases vidéos : en avoir n multiplie par n le loyer si un joueur tombe sur une des 4
*/
class VideoBox: public PropertyBox{  
    protected:
        int _rent;

    public:
        //setters
        void setRent(int rent){_rent = rent;}
};

class ElectrcityBox: public PropertyBox{
    protected:
        int _rent;

    public:
        //setters
        void setRent(int rent){_rent = rent;}
};

class WaterBox: public PropertyBox{
    protected:
        int _rent;

    public:
        //setters
        void setRent(int rent){_rent = rent;}
};

class HappeningBox: public Box{
    public:

    protected:

};

class StartBox: public HappeningBox{
    public:
        //constructors
        StartBox() {setBoxName("Start Box"); setBoxNumber(0);}
        ~StartBox() {};
};

class FreePark: public HappeningBox{
    public:
        //constructors
        FreePark() {setBoxName("Free Park"); setBoxNumber(10);}
        ~FreePark() {};
};

class JailBox: public HappeningBox{
    public:
        //constructors
        JailBox() {setBoxName("Jail Box"); setBoxNumber(11);}
        ~JailBox() {};
};

class RedCardBox: public HappeningBox{
    public:
        //constructors
        RedCardBox() {setBoxName("Red Card Box"); setBoxNumber(31);}
        ~RedCardBox() {};
};