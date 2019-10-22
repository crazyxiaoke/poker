//
//  CardRlue.hpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#ifndef CardRlue_hpp
#define CardRlue_hpp
#include <iostream>
#include <vector>
#include <map>
#include "Card.hpp"
#include "Util.hpp"
using namespace std;
typedef enum CardType{
    None,
    Single,
    Double,
    MThree,
    MThreeToOne,
    MThreeToTwo,
    Straight,
    DoubleStraight,
    ThreeStraight,
    ThreeStraightToOne,
    ThreeStraightToTwo,
    FourToOne,
    FourToTwo,
    Boom,
    JokerBoom,
    Error
}CardType;
class CardRlue{
protected:
    /**
        获取三张牌的集合
     */
    vector<int> getIsThreeCardValue(vector<Card*> cards);
    /**
        获取四张牌的集合
     */
    vector<int> getIsFourCardValue(vector<Card*> cards);
    /**
        单牌
     */
    bool isSingle(vector<Card*> cards);
    /**
        对子
     */
    bool isDouble(vector<Card*> cards);
    /**
        三张牌
     */
    bool isThree(vector<Card*> cards);
    
    /**
        顺子
     */
    bool isStraight(vector<Card*> cards);
    /**
        连对
     */
    bool isDoubleStraight(vector<Card*> cards);
    /**
        飞机（不带）
     */
    bool isThreeStraight(vector<Card*> cards);
    
    /**
        飞机（带一张）
     */
    bool isThreeStraightToOne(vector<Card*> cards);
    
    /**
        飞机（带对子）
     */
    bool isThreeStraightToTwo(vector<Card*> cards);
    
    /**
        三带一
     */
    bool isThreeToOne(vector<Card*> cards);
    
    /**
        三带二
     */
    bool isThreeToTwo(vector<Card*> cards);
    /**
        炸弹
     */
    bool isBoom(vector<Card*> cards);
    
    /**
        四带一
     */
    bool isFourToOne(vector<Card*> cards);
    /**
        四带二
     */
    bool isFourToTwo(vector<Card*> cards);
    /**
        王炸
     */
    bool isJokerBoom(vector<Card*> cards);
    
    /**
        获取牌的类型
     */
    CardType getCardsType(vector<Card*> cards);
    
    
public:
    /**
        比大小
     */
    bool compareCards(vector<Card*> cards1,vector<Card*> cards2,CardType* lastType);
    
    /**
        获取出牌的类型
     */
    char* getCardsTypeName(CardType type);
};

#endif /* CardRlue_hpp */
