//
//  Player.hpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <cstring>
#include <iostream>
#include <vector>
#include "Card.hpp"

using namespace std;

typedef enum PlayerType{
    Landlord,
    Farmer
}PlayerType;

class Player{
public:
    Player();
    Player(const char* name,int cardsCount);
    char* getName();
    int getCardsCount();
    void addCards(Card* card);
    void removeCards(Card* card);
    vector<Card*>& getCards();
    void setPlayerType(PlayerType playerType);
    PlayerType getPlayerType();
private:
    char* name;
    vector<Card*> cards;
    int cardsCount;
    PlayerType playerType;

};

#endif /* Player_hpp */
