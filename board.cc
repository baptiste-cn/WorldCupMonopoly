#include "board.hh"
#include "box.hh"
#include <map>

//On démarre le jeu donc on initialise le plateau
Board::Board(){
    nbPlayers = 0;
    _whosPlaying = 0;
    _taxMoney = 0;

    // On ajoute les cases au plateau
    // cases spéciales uniques
    _boxes.push_back(new StartBox());
    _boxes.push_back(new JailBox());
    _boxes.push_back(new VisitBox());
    _boxes.push_back(new FreePark());
    _boxes.push_back(new RedCardBox());
    
    // cases spéciales en plusieurs exemplaires
    _boxes.push_back(new TaxBoxes(_boxes));
    _boxes.push_back(new VideoBoxes(_boxes));
    _boxes.push_back(new LotteryBoxes(_boxes));
    _boxes.push_back(new RepairBoxes(_boxes));

    // cases propriétés
    _boxes.push_back(new SouthAfricanStadiums(_boxes));
    _boxes.push_back(new RussianStadiums(_boxes));
    _boxes.push_back(new ArgentinianStadiums(_boxes));
    _boxes.push_back(new DeutchStadiums(_boxes));
    _boxes.push_back(new EnglishStadiums(_boxes));
    _boxes.push_back(new BrazilianStadiums(_boxes));
    _boxes.push_back(new SpanishStadiums(_boxes));
    _boxes.push_back(new FrenchStadiums(_boxes));


    //ajout des cases générées dans un map
    for(auto &box: _boxes){
        _boxesMap[box->getBoxNumber()] = *box;
    }
}