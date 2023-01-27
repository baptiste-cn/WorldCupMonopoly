#include "box.hh"

unsigned int Box::cpt = 0;

Box::Box(){
    _boxId = cpt++;
}

VideoBox::VideoBox(std::string name){
    setBoxName(name);
}

TaxBox::TaxBox(std::string name){
    setBoxName(name);
}

LotteryBox::LotteryBox(std::string name){
    setBoxName(name);
}

RepairBox::RepairBox(std::string name){
    setBoxName(name);
}

SouthAfricanStadiums::SouthAfricanStadiums(){
    _southAfricanStadiums.push_back(Box("FNB Stadium"));
    _southAfricanStadiums.push_back(Box("Cape Town Stadium"));
    
    _southAfricanStadiums[0].setBoxNumber(1);
    _southAfricanStadiums[0].setBoxType(PropertyBox);
    _southAfricanStadiums[0].setIsBought(false);
    _southAfricanStadiums[0].setPrice(60);
    _southAfricanStadiums[0].setRent(2);
    _southAfricanStadiums[0].setPriceUpgrade(30);

    _southAfricanStadiums[1].setBoxNumber(3);
    _southAfricanStadiums[1].setBoxType(PropertyBox);
    _southAfricanStadiums[1].setIsBought(false);
    _southAfricanStadiums[1].setPrice(60);
    _southAfricanStadiums[1].setRent(4);
    _southAfricanStadiums[1].setPriceUpgrade(30);
}

RussianStadiums::RussianStadiums(){
    _russianStadiums.push_back(Box("Luzhniki Stadium"));
    _russianStadiums.push_back(Box("Krestovsky Stadium"));
    _russianStadiums.push_back(Box("Otkrytiye Arena"));

    _russianStadiums[0].setBoxNumber(6);
    _russianStadiums[0].setBoxType(PropertyBox);
    _russianStadiums[0].setIsBought(false);
    _russianStadiums[0].setPrice(100);
    _russianStadiums[0].setRent(6);
    _russianStadiums[0].setPriceUpgrade(50);

    _russianStadiums[1].setBoxNumber(8);
    _russianStadiums[1].setBoxType(PropertyBox);
    _russianStadiums[1].setIsBought(false);
    _russianStadiums[1].setPrice(100);
    _russianStadiums[1].setRent(6);
    _russianStadiums[1].setPriceUpgrade(50);

    _russianStadiums[2].setBoxNumber(9);
    _russianStadiums[2].setBoxType(PropertyBox);
    _russianStadiums[2].setIsBought(false);
    _russianStadiums[2].setPrice(120);
    _russianStadiums[2].setRent(8);
    _russianStadiums[2].setPriceUpgrade(60);
}

ArgentinianStadiums::ArgentinianStadiums(){
    _argentinianStadiums.push_back(Box("Estadio Monumental"));
    _argentinianStadiums.push_back(Box("Estadio La Bombonera"));
    _argentinianStadiums.push_back(Box("Estadio Ciudad de La Plata"));

    _argentinianStadiums[0].setBoxNumber(11);
    _argentinianStadiums[0].setBoxType(PropertyBox);
    _argentinianStadiums[0].setIsBought(false);
    _argentinianStadiums[0].setPrice(140);
    _argentinianStadiums[0].setRent(10);
    _argentinianStadiums[0].setPriceUpgrade(70);

    _argentinianStadiums[1].setBoxNumber(13);
    _argentinianStadiums[1].setBoxType(PropertyBox);
    _argentinianStadiums[1].setIsBought(false);
    _argentinianStadiums[1].setPrice(150);
    _argentinianStadiums[1].setRent(10);
    _argentinianStadiums[1].setPriceUpgrade(70);

    _argentinianStadiums[2].setBoxNumber(14);
    _argentinianStadiums[2].setBoxType(PropertyBox);
    _argentinianStadiums[2].setIsBought(false);
    _argentinianStadiums[2].setPrice(160);
    _argentinianStadiums[2].setRent(12);
    _argentinianStadiums[2].setPriceUpgrade(80);
}

DeutchStadiums::DeutchStadiums(){
    _deutchStadiums.push_back(Box("Allianz Arena"));
    _deutchStadiums.push_back(Box("Signal Iduna Park"));
    _deutchStadiums.push_back(Box("Olympiastadion"));

    _deutchStadiums[0].setBoxNumber(16);
    _deutchStadiums[0].setBoxType(PropertyBox);
    _deutchStadiums[0].setIsBought(false);
    _deutchStadiums[0].setPrice(180);
    _deutchStadiums[0].setRent(14);
    _deutchStadiums[0].setPriceUpgrade(90);

    _deutchStadiums[1].setBoxNumber(18);
    _deutchStadiums[1].setBoxType(PropertyBox);
    _deutchStadiums[1].setIsBought(false);
    _deutchStadiums[1].setPrice(180);
    _deutchStadiums[1].setRent(14);
    _deutchStadiums[1].setPriceUpgrade(90);

    _deutchStadiums[2].setBoxNumber(19);
    _deutchStadiums[2].setBoxType(PropertyBox);
    _deutchStadiums[2].setIsBought(false);
    _deutchStadiums[2].setPrice(200);
    _deutchStadiums[2].setRent(16);
    _deutchStadiums[2].setPriceUpgrade(90);
}

EnglishStadiums::EnglishStadiums(){
    _englishStadiums.push_back(Box("Wembley"));
    _englishStadiums.push_back(Box("Old Trafford"));
    _englishStadiums.push_back(Box("Anfield"));

    _englishStadiums[0].setBoxNumber(21);
    _englishStadiums[0].setBoxType(PropertyBox);
    _englishStadiums[0].setIsBought(false);
    _englishStadiums[0].setPrice(220);
    _englishStadiums[0].setRent(18);
    _englishStadiums[0].setPriceUpgrade(110);

    _englishStadiums[1].setBoxNumber(23);
    _englishStadiums[1].setBoxType(PropertyBox);
    _englishStadiums[1].setIsBought(false);
    _englishStadiums[1].setPrice(220);
    _englishStadiums[1].setRent(18);
    _englishStadiums[1].setPriceUpgrade(110);

    _englishStadiums[2].setBoxNumber(24);
    _englishStadiums[2].setBoxType(PropertyBox);
    _englishStadiums[2].setIsBought(false);
    _englishStadiums[2].setPrice(240);
    _englishStadiums[2].setRent(20);
    _englishStadiums[2].setPriceUpgrade(110);
}

BrazilianStadiums::BrazilianStadiums(){
    _brazilianStadiums.push_back(Box("Maracana"));
    _brazilianStadiums.push_back(Box("Mineirao"));
    _brazilianStadiums.push_back(Box("Arena do Gremio"));

    _brazilianStadiums[0].setBoxNumber(26);
    _brazilianStadiums[0].setBoxType(PropertyBox);
    _brazilianStadiums[0].setIsBought(false);
    _brazilianStadiums[0].setPrice(260);
    _brazilianStadiums[0].setRent(22);
    _brazilianStadiums[0].setPriceUpgrade(130);

    _brazilianStadiums[1].setBoxNumber(27);
    _brazilianStadiums[1].setBoxType(PropertyBox);
    _brazilianStadiums[1].setIsBought(false);
    _brazilianStadiums[1].setPrice(260);
    _brazilianStadiums[1].setRent(22);
    _brazilianStadiums[1].setPriceUpgrade(130);

    _brazilianStadiums[2].setBoxNumber(29);
    _brazilianStadiums[2].setBoxType(PropertyBox);
    _brazilianStadiums[2].setIsBought(false);
    _brazilianStadiums[2].setPrice(280);
    _brazilianStadiums[2].setRent(22);
    _brazilianStadiums[2].setPriceUpgrade(130);
}

SpanishStadiums::SpanishStadiums(){
    _spanishStadiums.push_back(Box("Camp Nou"));
    _spanishStadiums.push_back(Box("Santiago Bernabeu"));
    _spanishStadiums.push_back(Box("Benito Villamarin"));

    _spanishStadiums[0].setBoxNumber(31);
    _spanishStadiums[0].setBoxType(PropertyBox);
    _spanishStadiums[0].setIsBought(false);
    _spanishStadiums[0].setPrice(300);
    _spanishStadiums[0].setRent(26);
    _spanishStadiums[0].setPriceUpgrade(150);

    _spanishStadiums[1].setBoxNumber(32);
    _spanishStadiums[1].setBoxType(PropertyBox);
    _spanishStadiums[1].setIsBought(false);
    _spanishStadiums[1].setPrice(300);
    _spanishStadiums[1].setRent(26);
    _spanishStadiums[1].setPriceUpgrade(150);

    _spanishStadiums[2].setBoxNumber(34);
    _spanishStadiums[2].setBoxType(PropertyBox);
    _spanishStadiums[2].setIsBought(false);
    _spanishStadiums[2].setPrice(320);
    _spanishStadiums[2].setRent(28);
    _spanishStadiums[2].setPriceUpgrade(150);
}

FrenchStadiums::FrenchStadiums(){
    _frenchStadiums.push_back(Box("Parc des Princes"));
    _frenchStadiums.push_back(Box("Stade de France"));
    
    _frenchStadiums[0].setBoxNumber(37);
    _frenchStadiums[0].setBoxType(PropertyBox);
    _frenchStadiums[0].setIsBought(false);
    _frenchStadiums[0].setPrice(350);
    _frenchStadiums[0].setRent(35);
    _frenchStadiums[0].setPriceUpgrade(175);

    _frenchStadiums[1].setBoxNumber(39);
    _frenchStadiums[1].setBoxType(PropertyBox);
    _frenchStadiums[1].setIsBought(false);
    _frenchStadiums[1].setPrice(400);
    _frenchStadiums[1].setRent(50);
    _frenchStadiums[1].setPriceUpgrade(175);
}

VideoBoxes::VideoBoxes(){
    _videoBoxes.push_back(VideoBox("Finale 1998"));
    _videoBoxes.push_back(VideoBox("Finale 2014"));
    _videoBoxes.push_back(VideoBox("Finale 2018"));
    _videoBoxes.push_back(VideoBox("Finale 2022"));

    _videoBoxes[0].setBoxNumber(5);
    _videoBoxes[0].setBoxType(PropertyBox);
    _videoBoxes[0].setIsBought(false);
    _videoBoxes[0].setPrice(200);

    _videoBoxes[1].setBoxNumber(15);
    _videoBoxes[1].setBoxType(PropertyBox);
    _videoBoxes[1].setIsBought(false);
    _videoBoxes[1].setPrice(200);

    _videoBoxes[2].setBoxNumber(25);
    _videoBoxes[2].setBoxType(PropertyBox);
    _videoBoxes[2].setIsBought(false);
    _videoBoxes[2].setPrice(200);

    _videoBoxes[3].setBoxNumber(35);
    _videoBoxes[3].setBoxType(PropertyBox);
    _videoBoxes[3].setIsBought(false);
    _videoBoxes[3].setPrice(200);
};

TaxBoxes::TaxBoxes(){
    _taxBoxes.push_back(TaxBox("Tax Box 1"));
    _taxBoxes.push_back(TaxBox("Tax Box 2"));

    _taxBoxes[0].setBoxNumber(4);
    _taxBoxes[0].setBoxType(TaxBoxType);
    _taxBoxes[0].setIsBought(false);

    _taxBoxes[1].setBoxNumber(38);
    _taxBoxes[1].setBoxType(TaxBoxType);
    _taxBoxes[1].setIsBought(false);
}

LotteryBoxes::LotteryBoxes(){
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 1"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 2"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 3"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 4"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 5"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 6"));

    _lotteryBoxes[0].setBoxNumber(2);
    _lotteryBoxes[0].setBoxType(LotteryBoxType);
    _lotteryBoxes[0].setIsBought(false);

    _lotteryBoxes[1].setBoxNumber(7);
    _lotteryBoxes[1].setBoxType(LotteryBoxType);
    _lotteryBoxes[1].setIsBought(false);

    _lotteryBoxes[2].setBoxNumber(17);
    _lotteryBoxes[2].setBoxType(LotteryBoxType);
    _lotteryBoxes[2].setIsBought(false);

    _lotteryBoxes[3].setBoxNumber(22);
    _lotteryBoxes[3].setBoxType(LotteryBoxType);
    _lotteryBoxes[3].setIsBought(false);

    _lotteryBoxes[4].setBoxNumber(33);
    _lotteryBoxes[4].setBoxType(LotteryBoxType);
    _lotteryBoxes[4].setIsBought(false);

    _lotteryBoxes[5].setBoxNumber(36);
    _lotteryBoxes[5].setBoxType(LotteryBoxType);
    _lotteryBoxes[5].setIsBought(false);
}

RepairBoxes::RepairBoxes(){
    _repairBoxes.push_back(RepairBox("Electricity Box"));
    _repairBoxes.push_back(RepairBox("Water Box"));

    _repairBoxes[0].setBoxNumber(12);
    _repairBoxes[0].setBoxType(RepairBoxType);
    _repairBoxes[0].setIsBought(false);
    _repairBoxes[0].setPrice(150);
    _repairBoxes[0].setRent(4);

    _repairBoxes[1].setBoxNumber(28);
    _repairBoxes[1].setBoxType(RepairBoxType);
    _repairBoxes[1].setIsBought(false);
    _repairBoxes[1].setPrice(150);
    _repairBoxes[1].setRent(10);
}
