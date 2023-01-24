#include "box.hh"

unsigned int Box::cpt = 0;

Box::Box(){
    _boxId = cpt++;
}

// StadiumBox::StadiumBox(std::string name){
//     setBoxName(name);
// }

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

SouthAfricanStadiums::SouthAfricanStadiums(std::vector<Box*> &boxes){
    _southAfricanStadiums.push_back(Box("FNB Stadium"));
    _southAfricanStadiums.push_back(Box("Cape Town Stadium"));
    
    _southAfricanStadiums[0].setBoxNumber(1);
    _southAfricanStadiums[0].setBoxType(SouthAfricanStadium);

    _southAfricanStadiums[1].setBoxNumber(3);
    _southAfricanStadiums[1].setBoxType(SouthAfricanStadium);

    for (auto &box : _southAfricanStadiums){
        boxes.push_back(&box);
    }
}

RussianStadiums::RussianStadiums(std::vector<Box*> &boxes){
    _russianStadiums.push_back(Box("Luzhniki Stadium"));
    _russianStadiums.push_back(Box("Krestovsky Stadium"));
    _russianStadiums.push_back(Box("Otkrytiye Arena"));

    _russianStadiums[0].setBoxNumber(6);
    _russianStadiums[0].setBoxType(RussianStadium);

    _russianStadiums[1].setBoxNumber(8);
    _russianStadiums[1].setBoxType(RussianStadium);

    _russianStadiums[2].setBoxNumber(9);
    _russianStadiums[2].setBoxType(RussianStadium);

    for (auto &box : _russianStadiums){
        boxes.push_back(&box);
    }
}

ArgentinianStadiums::ArgentinianStadiums(std::vector<Box*> &boxes){
    _argentinianStadiums.push_back(Box("Estadio Monumental"));
    _argentinianStadiums.push_back(Box("Estadio La Bombonera"));
    _argentinianStadiums.push_back(Box("Estadio Ciudad de La Plata"));

    _argentinianStadiums[0].setBoxNumber(11);
    _argentinianStadiums[0].setBoxType(ArgentinianStadium);

    _argentinianStadiums[1].setBoxNumber(13);
    _argentinianStadiums[1].setBoxType(ArgentinianStadium);

    _argentinianStadiums[2].setBoxNumber(14);
    _argentinianStadiums[3].setBoxType(ArgentinianStadium);

    for (auto &box : _argentinianStadiums){
        boxes.push_back(&box);
    }
}

DeutchStadiums::DeutchStadiums(std::vector<Box*> &boxes){
    _deutchStadiums.push_back(Box("Allianz Arena"));
    _deutchStadiums.push_back(Box("Signal Iduna Park"));
    _deutchStadiums.push_back(Box("Olympiastadion"));

    _deutchStadiums[0].setBoxNumber(16);
    _deutchStadiums[0].setBoxType(DeutchStadium);

    _deutchStadiums[1].setBoxNumber(18);
    _deutchStadiums[1].setBoxType(DeutchStadium);

    _deutchStadiums[2].setBoxNumber(19);
    _deutchStadiums[2].setBoxType(DeutchStadium);

    for (auto &box : _deutchStadiums){
        boxes.push_back(&box);
    }
}

EnglishStadiums::EnglishStadiums(std::vector<Box*> &boxes){
    _englishStadiums.push_back(Box("Wembley"));
    _englishStadiums.push_back(Box("Old Trafford"));
    _englishStadiums.push_back(Box("Anfield"));

    _englishStadiums[0].setBoxNumber(21);
    _englishStadiums[0].setBoxType(EnglishStadium);

    _englishStadiums[1].setBoxNumber(23);
    _englishStadiums[1].setBoxType(EnglishStadium);

    _englishStadiums[2].setBoxNumber(24);
    _englishStadiums[2].setBoxType(EnglishStadium);

    for (auto &box : _englishStadiums){
        boxes.push_back(&box);
    }
}

BrazilianStadiums::BrazilianStadiums(std::vector<Box*> &boxes){
    _brazilianStadiums.push_back(Box("Maracana"));
    _brazilianStadiums.push_back(Box("Mineirao"));
    _brazilianStadiums.push_back(Box("Arena do Gremio"));

    _brazilianStadiums[0].setBoxNumber(26);
    _brazilianStadiums[0].setBoxType(BrazilianStadium);

    _brazilianStadiums[1].setBoxNumber(27);
    _brazilianStadiums[1].setBoxType(BrazilianStadium);

    _brazilianStadiums[2].setBoxNumber(29);
    _brazilianStadiums[2].setBoxType(BrazilianStadium);

    for (auto &box : _brazilianStadiums){
        boxes.push_back(&box);
    }
}

SpanishStadiums::SpanishStadiums(std::vector<Box*> &boxes){
    _spanishStadiums.push_back(Box("Camp Nou"));
    _spanishStadiums.push_back(Box("Santiago Bernabeu"));
    _spanishStadiums.push_back(Box("Benito Villamarin"));

    _spanishStadiums[0].setBoxNumber(31);
    _spanishStadiums[0].setBoxType(SpanishStadium);

    _spanishStadiums[1].setBoxNumber(32);
    _spanishStadiums[1].setBoxType(SpanishStadium);

    _spanishStadiums[2].setBoxNumber(34);
    _spanishStadiums[2].setBoxType(SpanishStadium);

    for (auto &box : _spanishStadiums){
        boxes.push_back(&box);
    }
}

FrenchStadiums::FrenchStadiums(std::vector<Box*> &boxes){
    _frenchStadiums.push_back(Box("Parc des Princes"));
    _frenchStadiums.push_back(Box("Stade de France"));
    
    _frenchStadiums[0].setBoxNumber(37);
    _frenchStadiums[0].setBoxType(FrenchStadium);

    _frenchStadiums[1].setBoxNumber(39);
    _frenchStadiums[1].setBoxType(FrenchStadium);

    for (auto &box : _frenchStadiums){
        boxes.push_back(&box);
    }
}

// std::ostream& operator<<(std::ostream& os, const StadiumBox& stadiumBox){
//     os << "Nom du stade : " << stadiumBox.getBoxName() << std::endl;
//     os << "Numéro de la case : " << stadiumBox.getBoxNumber() << std::endl;
//     os << "ID de la case : " << stadiumBox.getBoxId() << std::endl;
//     return os;
// }

VideoBoxes::VideoBoxes(std::vector<Box*> &boxes){
    _videoBoxes.push_back(VideoBox("Finale 1998"));
    _videoBoxes.push_back(VideoBox("Finale 2014"));
    _videoBoxes.push_back(VideoBox("Finale 2018"));
    _videoBoxes.push_back(VideoBox("Finale 2022"));

    _videoBoxes[0].setBoxNumber(5);
    _videoBoxes[0].setBoxType(VideoBoxType);

    _videoBoxes[1].setBoxNumber(15);
    _videoBoxes[1].setBoxType(VideoBoxType);

    _videoBoxes[2].setBoxNumber(25);
    _videoBoxes[2].setBoxType(VideoBoxType);

    _videoBoxes[3].setBoxNumber(35);
    _videoBoxes[3].setBoxType(VideoBoxType);

    for (auto &box : _videoBoxes){
        boxes.push_back(&box);
    }
};

TaxBoxes::TaxBoxes(std::vector<Box*> &boxes){
    _taxBoxes.push_back(TaxBox("Tax Box 1"));
    _taxBoxes.push_back(TaxBox("Tax Box 2"));

    _taxBoxes[0].setBoxNumber(4);
    _taxBoxes[0].setBoxType(TaxBoxType);

    _taxBoxes[1].setBoxNumber(38);
    _taxBoxes[1].setBoxType(TaxBoxType);

    for (auto &box : _taxBoxes){
        boxes.push_back(&box);
    }
}

LotteryBoxes::LotteryBoxes(std::vector<Box*> &boxes){
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 1"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 2"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 3"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 4"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 5"));
    _lotteryBoxes.push_back(LotteryBox("Lottery Box 6"));

    _lotteryBoxes[0].setBoxNumber(2);
    _lotteryBoxes[0].setBoxType(LotteryBoxType);

    _lotteryBoxes[1].setBoxNumber(7);
    _lotteryBoxes[1].setBoxType(LotteryBoxType);

    _lotteryBoxes[2].setBoxNumber(17);
    _lotteryBoxes[2].setBoxType(LotteryBoxType);

    _lotteryBoxes[3].setBoxNumber(22);
    _lotteryBoxes[3].setBoxType(LotteryBoxType);

    _lotteryBoxes[4].setBoxNumber(33);
    _lotteryBoxes[4].setBoxType(LotteryBoxType);

    _lotteryBoxes[5].setBoxNumber(36);
    _lotteryBoxes[5].setBoxType(LotteryBoxType);

    for (auto &box : _lotteryBoxes){
        boxes.push_back(&box);
    }
}

RepairBoxes::RepairBoxes(std::vector<Box*> &boxes){
    _repairBoxes.push_back(RepairBox("Electricity Box"));
    _repairBoxes.push_back(RepairBox("Water Box"));

    _repairBoxes[0].setBoxNumber(12);
    _repairBoxes[0].setBoxType(RepairBoxType);

    _repairBoxes[1].setBoxNumber(28);
    _repairBoxes[1].setBoxType(RepairBoxType);
    
    for (auto &box : _repairBoxes){
        boxes.push_back(&box);
    }
}