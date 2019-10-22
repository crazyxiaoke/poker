//
//  Card.hpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>

typedef enum Suit{
     spade,
     heart,
     club,
     diamond,
     smallJoker,
     bigJoker

}Suit;

typedef enum CardWeight{
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    Two,
    SJoker,
    LJoker
}CardWeight;


class Card{
public:
    Card();
    Card(CardWeight value,Suit suit);
    void setValue(CardWeight value);
    void setSuit(Suit suit);
    CardWeight getValue();
    Suit getSuit();
private:
    CardWeight value;
    Suit suit;
};

#endif /* Card_hpp */
