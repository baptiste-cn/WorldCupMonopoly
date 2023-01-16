#include "box.hh"

unsigned int Box::cpt = 0;

Box::Box(){
    _boxId = cpt++;
}

StadiumBox::StadiumBox(std::string name){
    setBoxName(name);
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
    _southAfricanStadiums.push_back(StadiumBox("FNB Stadium"));
    _southAfricanStadiums.push_back(StadiumBox("Cape Town Stadium"));
    
    //std::cout << getSouthAfricanStadiums()[0].getBoxName() << std::endl;
    _southAfricanStadiums[0].setBoxNumber(1);
    _southAfricanStadiums[1].setBoxNumber(3);
}

RussianStadiums::RussianStadiums(){
    _russianStadiums.push_back(StadiumBox("Luzhniki Stadium"));
    _russianStadiums.push_back(StadiumBox("Krestovsky Stadium"));
    _russianStadiums.push_back(StadiumBox("Otkrytiye Arena"));

    _russianStadiums[0].setBoxNumber(6);
    _russianStadiums[1].setBoxNumber(8);
    _russianStadiums[2].setBoxNumber(9);
}

ArgentinianStadiums::ArgentinianStadiums(){
    _argentinianStadiums.push_back(StadiumBox("Estadio Monumental"));
    _argentinianStadiums.push_back(StadiumBox("Estadio La Bombonera"));
    _argentinianStadiums.push_back(StadiumBox("Estadio Ciudad de La Plata"));

    _argentinianStadiums[0].setBoxNumber(12);
    _argentinianStadiums[1].setBoxNumber(14);
    _argentinianStadiums[2].setBoxNumber(15);
}

DeutchStadiums::DeutchStadiums(){
    _deutchStadiums.push_back(StadiumBox("Allianz Arena"));
    _deutchStadiums.push_back(StadiumBox("Signal Iduna Park"));
    _deutchStadiums.push_back(StadiumBox("Olympiastadion"));

    _deutchStadiums[0].setBoxNumber(17);
    _deutchStadiums[1].setBoxNumber(19);
    _deutchStadiums[2].setBoxNumber(20);
}

EnglishStadiums::EnglishStadiums(){
    _englishStadiums.push_back(StadiumBox("Wembley"));
    _englishStadiums.push_back(StadiumBox("Old Trafford"));
    _englishStadiums.push_back(StadiumBox("Anfield"));

    _englishStadiums[0].setBoxNumber(22);
    _englishStadiums[1].setBoxNumber(24);
    _englishStadiums[2].setBoxNumber(25);
}

BrazilianStadiums::BrazilianStadiums(){
    _brazilianStadiums.push_back(StadiumBox("Maracana"));
    _brazilianStadiums.push_back(StadiumBox("Mineirao"));
    _brazilianStadiums.push_back(StadiumBox("Arena do Gremio"));

    _brazilianStadiums[0].setBoxNumber(27);
    _brazilianStadiums[1].setBoxNumber(28);
    _brazilianStadiums[2].setBoxNumber(30);
}

SpanishStadiums::SpanishStadiums(){
    _spanishStadiums.push_back(StadiumBox("Camp Nou"));
    _spanishStadiums.push_back(StadiumBox("Santiago Bernabeu"));
    _spanishStadiums.push_back(StadiumBox("Benito Villamarin"));

    _spanishStadiums[0].setBoxNumber(32);
    _spanishStadiums[1].setBoxNumber(33);
    _spanishStadiums[2].setBoxNumber(35);
}

FrenchStadiums::FrenchStadiums(){
    _frenchStadiums.push_back(StadiumBox("Parc des Princes"));
    _frenchStadiums.push_back(StadiumBox("Stade de France"));
    
    _frenchStadiums[0].setBoxNumber(38);
    _frenchStadiums[1].setBoxNumber(40);
}

// std::ostream& operator<<(std::ostream& os, const StadiumBox& stadiumBox){
//     os << "Nom du stade : " << stadiumBox.getBoxName() << std::endl;
//     os << "Numéro de la case : " << stadiumBox.getBoxNumber() << std::endl;
//     os << "ID de la case : " << stadiumBox.getBoxId() << std::endl;
//     return os;
// }

VideoBoxes::VideoBoxes(){
    _videoBoxes.push_back(VideoBox("Finale 1998"));
    _videoBoxes.push_back(VideoBox("Finale 2014"));
    _videoBoxes.push_back(VideoBox("Finale 2018"));
    _videoBoxes.push_back(VideoBox("Finale 2022"));

    _videoBoxes[0].setBoxNumber(5);
    _videoBoxes[1].setBoxNumber(16);
    _videoBoxes[2].setBoxNumber(26);
    _videoBoxes[3].setBoxNumber(36);
};

TaxBoxes::TaxBoxes(){
    _taxBoxes.push_back(TaxBox("Tax Box 1"));
    _taxBoxes.push_back(TaxBox("Tax Box 2"));

    _taxBoxes[0].setBoxNumber(4);
    _taxBoxes[1].setBoxNumber(39);
}

LotteryBoxes::LotteryBoxes(){
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 1"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 2"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 3"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 4"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 5"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 6"));

    _lotteryBoxes[0].setBoxNumber(2);
    _lotteryBoxes[1].setBoxNumber(7);
    _lotteryBoxes[2].setBoxNumber(18);
    _lotteryBoxes[3].setBoxNumber(23);
    _lotteryBoxes[4].setBoxNumber(34);
    _lotteryBoxes[5].setBoxNumber(37);
}

RepairBoxes::RepairBoxes(){
    _repairBoxes.push_back(RepairBox("Electricity Box"));
    _repairBoxes.push_back(RepairBox("Water Box"));

    _repairBoxes[0].setBoxNumber(13);
    _repairBoxes[1].setBoxNumber(29);
}