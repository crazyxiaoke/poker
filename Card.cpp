//
//  Card.cpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#include "Card.hpp"

Card::Card(){
    
}

Card::Card(CardWeight _value,Suit _suit){
    value=_value;
    suit=_suit;
}

void Card::setValue(CardWeight value){
    this->value=value;
}

CardWeight Card::getValue(){
    return value;
}

void Card::setSuit(Suit suit){
    this->suit=suit;
}

Suit Card::getSuit(){
    return suit;
}

