#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "board.hh"
#include "player.hh"

enum BoxType {
    FrenchStadium,
    SpanishStadium,
    BrazilianStadium,
    EnglishStadium,
    DeutchStadium,
    ArgentinianStadium,
    RussianStadium,
    SouthAfricanStadium,
    VideoBoxType,
    RepairBoxType,
    StartBoxType,
    FreeParkBoxType,
    JailBoxType,
    RedCardBoxType,
    LotteryBoxType,
    TaxBoxType,
    VisitBoxType
};

class Box{
    static unsigned int cpt;
    protected:
        int _boxId;
        std::string _boxName;
        int _boxNumber;
        BoxType _boxType;

    public:
        //constructors
        Box(); 
        Box(std::string name){setBoxName(name);}
        ~Box(){};

        //getters
        int getBoxNumber() const {return _boxNumber;}
        std::string getBoxName() const {return _boxName;}
        int getBoxId() const {return _boxId;}    
        BoxType getBoxType(){return _boxType;}
        
        //setters
        void setBoxNumber(int boxNumber){_boxNumber = boxNumber;}
        void setBoxName(std::string name){_boxName = name;}
        void setBoxType(BoxType type){_boxType = type;}
        
        
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

        virtual void interaction(Player &player) = 0;

        //getters
        double getPrice() const {return _price;}
        double getMortgagePrice() const {return _mortgagePrice;}
        bool getIsBought() {return _isBought;} //pas de const car on peut acheter une propriété
        int getRent() const {return _rent;}

        //setters
        void setPrice(double price){_price = price;}
        void setMortgagePrice(double mortgagePrice){_mortgagePrice = mortgagePrice;}
        void setIsBought(bool bought){_isBought = bought;}
        void setRent(int rent){_rent = rent;}
}; 

class FrenchStadiums: public PropertyBox{
    public:
        //constructors
        FrenchStadiums(){};
        FrenchStadiums(std::vector<Box*> &boxes);
        ~FrenchStadiums(){};

        void interaction(Player &player){
            if(getIsBought() == 0){
                std::cout << "Do you want to buy this stadium ? (y/n)" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'y'){
                    player.addMoney(-getPrice());
                    setIsBought(1);
                    player.getOwnedBoxes().push_back(*this);
                }
            }
            else{
                std::cout << "You have to pay " << getRent() << " to the owner" << std::endl;
                player.addMoney(-getRent());
                
            }
        };

        //getters
        std::vector<Box> getFrenchStadiums() const {return _frenchStadiums;}
        

        //setters
        

    protected:
        std::vector<Box>_frenchStadiums;
        
};

class SpanishStadiums: public PropertyBox{
    public:
        //constructors
        SpanishStadiums(){};
        SpanishStadiums(std::vector<Box*> &boxes);
        ~SpanishStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getSpanishStadiums() const {return _spanishStadiums;}

    protected:
        std::vector<Box>_spanishStadiums;
};

class BrazilianStadiums: public PropertyBox{
    public:
        //constructors
        BrazilianStadiums(){};
        BrazilianStadiums(std::vector<Box*> &boxes);
        ~BrazilianStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getBrazilianStadiums() const {return _brazilianStadiums;}

    protected:
        std::vector<Box>_brazilianStadiums;
};

class EnglishStadiums: public PropertyBox{
    public:
        //constructors
        EnglishStadiums(){};
        EnglishStadiums(std::vector<Box*> &boxes);
        ~EnglishStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getEnglishStadiums() const {return _englishStadiums;}

    protected:
        std::vector<Box>_englishStadiums;
};

class DeutchStadiums: public PropertyBox{
    public:
        //constructors
        DeutchStadiums(){};
        DeutchStadiums(std::vector<Box*> &boxes);
        ~DeutchStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getDeutchStadiums() const {return _deutchStadiums;}

    protected:
        std::vector<Box>_deutchStadiums;
};

class ArgentinianStadiums: public PropertyBox{
    public:
        //constructors
        ArgentinianStadiums(){};
        ArgentinianStadiums(std::vector<Box*> &boxes);
        ~ArgentinianStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getArgentinianStadiums() const {return _argentinianStadiums;}

    protected:
        std::vector<Box>_argentinianStadiums;
};

class RussianStadiums: public PropertyBox{
    public:
        //constructors
        RussianStadiums(){};
        RussianStadiums(std::vector<Box*> &boxes);
        ~RussianStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getRussianStadiums() const {return _russianStadiums;}

    protected:
        std::vector<Box>_russianStadiums;
};

class SouthAfricanStadiums: public PropertyBox{
    public:
        //constructors
        SouthAfricanStadiums(){};
        SouthAfricanStadiums(std::vector<Box*> &boxes);
        ~SouthAfricanStadiums() {};

        void interaction(Player &player){};

        //getters
        std::vector<Box> getSouthAfricanStadiums() const {return _southAfricanStadiums;}

    protected:
        std::vector<Box>_southAfricanStadiums;
};


/*cases similaires aux gares : si on tombe dessus on doit payer pour regarder des archives de matches. 
Il y a 4 cases vidéos : en avoir n multiplie par n le loyer si un joueur tombe sur une des 4
*/

class VideoBox: public PropertyBox{  
    public:
        //constructors
        VideoBox(){}; //{_boxId = cpt++;};
        VideoBox(std::string name); //{setBoxName(name); _boxId = cpt++;}
        
        void interaction(Player &player){};        
};

class VideoBoxes: public VideoBox{
    public:
        //constructors
        VideoBoxes(){};
        VideoBoxes(std::vector<Box*> &boxes); //{_boxId = cpt++;};

        void interaction(Player &player){};  

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

        void interaction(Player &player){};
};



class RepairBoxes: public RepairBox{
    public:
        //constructors
        RepairBoxes(){};
        RepairBoxes(std::vector<Box*> &boxes);

        void interaction(Player &player){}

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
        StartBox() {setBoxName("Start Box"); setBoxNumber(0); setBoxType(StartBoxType);}
        ~StartBox() {};

        void interaction(Player &player){player.addMoney(player.getMoney() + 200);}
};

class FreePark: public HappeningBox{
    public:
        //constructors
        FreePark() {setBoxName("Free Park"); setBoxNumber(20); setBoxType(FreeParkBoxType);}
        ~FreePark() {};

        void interaction(Player &player){player.addMoney(player.getMoney() );}
};

class JailBox: public HappeningBox{
    public:
        //constructors
        JailBox() {setBoxName("Jail Box"); setBoxNumber(99); setBoxType(JailBoxType);}
        ~JailBox() {};

        void interaction(Player &player){}
};

class RedCardBox: public HappeningBox{
    public:
        //constructors
        RedCardBox() {setBoxName("Red Card Box"); setBoxNumber(30); setBoxType(RedCardBoxType);}
        ~RedCardBox() {};

        void interaction(Player &player){};
};

class LotteryBox: public HappeningBox{
    public: 
        //constructors
        LotteryBox(){}
        LotteryBox(std::string name);

        void interaction(Player &player){}
};

class LotteryBoxes: public LotteryBox{
    public:
        //constructors
        LotteryBoxes(){};
        LotteryBoxes(std::vector<Box*> &boxes);

        void interaction(Player &player){}

        //getters
        std::vector<LotteryBox> getLotteryBoxes() const {return _lotteryBoxes;}

    protected:
        std::vector<LotteryBox>_lotteryBoxes;
};

class TaxBox: public HappeningBox{
    public:
        //constructors
        TaxBox(){}
        TaxBox(std::string name);

        void interaction(Player &player){}
};

class TaxBoxes: public TaxBox{
    public:
        //constructors
        TaxBoxes(){};
        TaxBoxes(std::vector<Box*> &boxes);

        void interaction(Player &player){player.addMoney(-200);}
        void addTaxMoney(Board &board){board.addTaxMoney(200);}

        //getters
        std::vector<TaxBox> getTaxBoxes() const {return _taxBoxes;}

    protected:
        std::vector<TaxBox>_taxBoxes;
};

class VisitBox: public Box{
    public:
        //constructors
        VisitBox(){setBoxName("Visit Box"); setBoxNumber(10); setBoxType(VisitBoxType);}
        ~VisitBox(){}

        void interaction(Player &player){}
};
