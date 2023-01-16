#include "board.hh"
#include "box.hh"

//On démarre le jeu donc on initialise le plateau
Board::Board(){
    nbPlayers = 0;
    _whosPlaying = 0;
    _taxMoney = 0;
    
    // On crée les cases du plateau
    // cases spéciales uniques
    StartBox start;
    JailBox jail;
    VisitBox visitBox;
    FreePark freePark;
    RedCardBox redCardBox;
    
    // cases spéciales en plusieurs exemplaires
    TaxBoxes taxBoxes;
    VideoBoxes videoBoxes;
    LotteryBoxes lotteryBoxes;
    RepairBoxes repairBoxes;
    
    // cases propriétés
    SouthAfricanStadiums SouthAfrStads;
    RussianStadiums RussianStads;
    ArgentinianStadiums ArgentinianStads;
    DeutchStadiums DeutchStads;
    EnglishStadiums EnglishStads;
    BrazilianStadiums BrazilianStads;
    SpanishStadiums SpanishStads;
    FrenchStadiums FrenchStads;

    // On ajoute les cases au plateau
    // cases spéciales uniques
    _boxes.push_back(start);
    _boxes.push_back(jail);
    _boxes.push_back(visitBox);
    _boxes.push_back(freePark);
    _boxes.push_back(redCardBox);
    
    // cases spéciales en plusieurs exemplaires
    for(auto& box: taxBoxes.getTaxBoxes()){
        _boxes.push_back(box);
    }
    for(auto& box: videoBoxes.getVideoBoxes()){
        _boxes.push_back(box);
    }
    for(auto& box: repairBoxes.getRepairBoxes()){
        _boxes.push_back(box);
    }

    // cases propriétés
    for(auto& box: SouthAfrStads.getSouthAfricanStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: RussianStads.getRussianStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: ArgentinianStads.getArgentinianStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: DeutchStads.getDeutchStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: EnglishStads.getEnglishStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: BrazilianStads.getBrazilianStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: SpanishStads.getSpanishStadiums()){
        _boxes.push_back(box);
    }
    for(auto& box: FrenchStads.getFrenchStadiums()){
        _boxes.push_back(box);
    }
}