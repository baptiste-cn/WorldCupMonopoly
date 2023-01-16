#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "board.hh"
#include "player.hh"

class Box{
    static unsigned int cpt;
    protected:
        int _boxId;
        std::string _boxName;
        int _boxNumber;

    public:
        //constructors
        Box(); 
        ~Box(){};
        //pure virtual function
        //virtual void addMoney(Player &player) = 0;

        //getters
        int getBoxNumber() const {return _boxNumber;}
        std::string getBoxName() const {return _boxName;}
        int getBoxId() const {return _boxId;}    
        
        //setters
        void setBoxNumber(int boxNumber){_boxNumber = boxNumber;}
        void setBoxName(std::string name){_boxName = name;}
        
        
};

class PropertyBox: public Box{
    protected:
        double _price;
        double _mortgagePrice;  //prix hypothèque
        bool _isBought;
        int _rent;

    public:
        //constructors
        PropertyBox(){};
        ~PropertyBox(){};

        virtual void addMoney(Player &player) = 0;

        //getters
        double getPrice() const {return _price;}
        double getMortgagePrice() const {return _mortgagePrice;}
        bool getIsBought() const {return _isBought;}
        int getRent() const {return _rent;}

        //setters
        void setPrice(double price){_price = price;}
        void setMortgagePrice(double mortgagePrice){_mortgagePrice = mortgagePrice;}
        void setIsBought(bool bought){_isBought = bought;}
        void setRent(int rent){_rent = rent;}
}; 

class StadiumBox: public PropertyBox{
    protected:
        int _nbStands = 0;  //nb de stands (maisons) posées sur la carte (max 4) (0 par défaut)
        int _nbHotels = 0;  //nb d'hôtels posés sur la carte (max 1) (0 par défaut)
        
    public:
        //constructors
        StadiumBox(){}; //{_boxId = cpt++;};
        StadiumBox(std::string name); //{setBoxName(name); _boxId = cpt++;}

        virtual void addMoney(Player &player){};//{player.addMoney(player.getMoney() + getRent());}
        
        //getters
        //setters
        

};

//redfining operator << for StadiumBox
inline std::ostream& operator<<(std::ostream& os, const StadiumBox& stadiumBox){
    os << stadiumBox.getBoxName() << std::endl;
    return os;
};

class FrenchStadiums: public StadiumBox{
    public:
        //constructors
        FrenchStadiums();
        ~FrenchStadiums(){};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getFrenchStadiums() const {return _frenchStadiums;}

    protected:
        std::vector<StadiumBox>_frenchStadiums;
};

class SpanishStadiums: public StadiumBox{
    public:
        //constructors
        SpanishStadiums();
        ~SpanishStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getSpanishStadiums() const {return _spanishStadiums;}

    protected:
        std::vector<StadiumBox>_spanishStadiums;
};

class BrazilianStadiums: public StadiumBox{
    public:
        //constructors
        BrazilianStadiums();
        ~BrazilianStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getBrazilianStadiums() const {return _brazilianStadiums;}

    protected:
        std::vector<StadiumBox>_brazilianStadiums;
};

class EnglishStadiums: public StadiumBox{
    public:
        //constructors
        EnglishStadiums();
        ~EnglishStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getEnglishStadiums() const {return _englishStadiums;}

    protected:
        std::vector<StadiumBox>_englishStadiums;
};

class DeutchStadiums: public StadiumBox{
    public:
        //constructors
        DeutchStadiums();
        ~DeutchStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getDeutchStadiums() const {return _deutchStadiums;}

    protected:
        std::vector<StadiumBox>_deutchStadiums;
};

class ArgentinianStadiums: public StadiumBox{
    public:
        //constructors
        ArgentinianStadiums();
        ~ArgentinianStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getArgentinianStadiums() const {return _argentinianStadiums;}

    protected:
        std::vector<StadiumBox>_argentinianStadiums;
};

class RussianStadiums: public StadiumBox{
    public:
        //constructors
        RussianStadiums();
        ~RussianStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getRussianStadiums() const {return _russianStadiums;}

    protected:
        std::vector<StadiumBox>_russianStadiums;
};

class SouthAfricanStadiums: public StadiumBox{
    public:
        //constructors
        SouthAfricanStadiums();
        ~SouthAfricanStadiums() {};

        void addMoney(Player &player){};

        //getters
        std::vector<StadiumBox> getSouthAfricanStadiums() const {return _southAfricanStadiums;}

    protected:
        std::vector<StadiumBox>_southAfricanStadiums;
};


/*cases similaires aux gares : si on tombe dessus on doit payer pour regarder des archives de matches. 
Il y a 4 cases vidéos : en avoir n multiplie par n le loyer si un joueur tombe sur une des 4
*/

class VideoBox: public PropertyBox{  
    public:
        //constructors
        VideoBox(){}; //{_boxId = cpt++;};
        VideoBox(std::string name); //{setBoxName(name); _boxId = cpt++;}
        
        void addMoney(Player &player){};        
};

class VideoBoxes: public VideoBox{
    public:
        //constructors
        VideoBoxes(); //{_boxId = cpt++;};

        void addMoney(Player &player){};  

        //getters
        std::vector<VideoBox> getVideoBoxes() const {return _videoBoxes;}

    protected:
        std::vector<VideoBox>_videoBoxes;      
};

class RepairBox: public PropertyBox{
    public:
        //constructors
        RepairBox(){};
        RepairBox(std::string name);

        void addMoney(Player &player){};
};



class RepairBoxes: public RepairBox{
    public:
        //constructors
        RepairBoxes();

        void addMoney(Player &player){}

        //getters
        std::vector<RepairBox> getRepairBoxes() const {return _repairBoxes;}

    protected:
        std::vector<RepairBox>_repairBoxes;
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

        void addMoney(Player &player){player.addMoney(player.getMoney() + 200);}
};

class FreePark: public HappeningBox{
    public:
        //constructors
        FreePark() {setBoxName("Free Park"); setBoxNumber(21);}
        ~FreePark() {};

        void addMoney(Player &player){player.addMoney(player.getMoney());}
};

class JailBox: public HappeningBox{
    public:
        //constructors
        JailBox() {setBoxName("Jail Box"); setBoxNumber(11);}
        ~JailBox() {};

        void addMoney(Player &player){}
};

class RedCardBox: public HappeningBox{
    public:
        //constructors
        RedCardBox() {setBoxName("Red Card Box"); setBoxNumber(31);}
        ~RedCardBox() {};

        void addMoney(Player &player){};
};

class LotteryBox: public HappeningBox{
    public: 
        //constructors
        LotteryBox(){}
        LotteryBox(std::string name);

        void addMoney(Player &player){}
};

class LotteryBoxes: public LotteryBox{
    public:
        //constructors
        LotteryBoxes();

        void addMoney(Player &player){}

        //getters
        std::vector<LotteryBox> getTaxBoxes() const {return _lotteryBoxes;}

    protected:
        std::vector<LotteryBox>_lotteryBoxes;
};

class TaxBox: public HappeningBox{
    public:
        //constructors
        TaxBox(){}
        TaxBox(std::string name);

        void addMoney(Player &player){}
};

class TaxBoxes: public TaxBox{
    public:
        //constructors
        TaxBoxes();

        void addMoney(Player &player){player.addMoney(-200);}
        void addTaxMoney(Board &board){board.addTaxMoney(200);}

        //getters
        std::vector<TaxBox> getTaxBoxes() const {return _taxBoxes;}

    protected:
        std::vector<TaxBox>_taxBoxes;
};

class VisitBox: public Box{
    public:
        //constructors
        VisitBox(){setBoxName("Visit Box"); setBoxNumber(10);}
        ~VisitBox(){}

        void addMoney(Player &player){}
};