#include "box.hh"

unsigned int Box::cpt = 0;

Box::Box(){
    _boxId = cpt++;
}

StadiumBox::StadiumBox(std::string name){
    setBoxName(name);
}

FrenchStadiums::FrenchStadiums(){
    _frenchStadiums.push_back(StadiumBox("Parc des Princes"));
    _frenchStadiums.push_back(StadiumBox("Stade de France"));
    
    //std::cout << getFrenchStadiums()[0].getBoxName() << std::endl;
    //getFrenchStadiums()[0].setBoxNumber(1);
    //getFrenchStadiums()[1].setBoxNumber(3);


}