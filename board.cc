#include "board.hh"

//On démarre le jeu donc on initialise le plateau
Board::Board(){
    _nbPlayers = 0;
    _whosPlaying = 0;
    _taxMoney = 0;
    
    //On crée les cases du plateau
    //cases spéciales
    StartBox start;
    FreePark freePark;
    RedCardBox redCardBox;
    JailBox jail;

    VideoBoxes videoBoxes;

    //cases propriétés
    SouthAfricanStadiums SouthAfrStads;
    RussianStadiums RussianStads;
    ArgentinianStadiums ArgentinianStads;
    DeutchStadiums DeutchStads;
    EnglishStadiums EnglishStads;
    BrazilianStadiums BrazilianStads;
    SpanishStadiums SpanishStads;
    FrenchStadiums FrenchStads;

    //On ajoute les cases au plateau
    //cases spéciales
    _boxes.push_back(start);
    _boxes.push_back(freePark);
    _boxes.push_back(redCardBox);
    _boxes.push_back(jail);

    for(auto& box: videoBoxes.getVideoBoxes()){
        _boxes.push_back(box);
    }

    //cases propriétés
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