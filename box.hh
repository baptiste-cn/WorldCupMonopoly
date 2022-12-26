#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "player.hh"

class Box{
    static int boxId;
    protected:
        std::string boxName;
        int _boxNumber;

    public:
        virtual ~Box() = 0;	//virtual destructor

        //getters
        int getBoxNumber() const {return _boxNumber;}
        std::string getBoxName() const {return boxName;}
        int getBoxId() const {return boxId;}    
        
        //setters
        
};

class PropertyBox: public Box{
    protected:
        double _price;
        double _mortgagePrice;  //prix hypothèque
        bool isBought;
}; 

class StadiumBox: public PropertyBox{
    protected:
        int _nbStands = 0;  //nb de stands (maisons) posées sur la carte (max 4) (0 par défaut)
        int _nbHotels = 0;  //nb d'hôtels posés sur la carte (max 1) (0 par défaut)
        int _rent;

    public:
        //setters
        void setRent(int rent){_rent = rent;}

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
        virtual ~HappeningBox() = 0;

    protected:

};

class StartBox: public HappeningBox{
    
};

template<class Player>
class FreePark: public HappeningBox{
    public:

    protected:
        void addMoney(){_money += money;}
};