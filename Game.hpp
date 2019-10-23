//
//  Game.hpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/18.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
#include "Card.hpp"
#include "CardRlue.hpp"
#include "Player.hpp"
#include "Util.hpp"

#define CARD_COUNT 54
#define LANDLORD_CARD_COUNT 3
#define PLAYER_COUNT 3

Card pokers[CARD_COUNT];
vector<Card *> landlordCard;
vector<Card *> lastCards;
CardType *lastType;
CardRlue rlue;

char *getCardName(Card *card);

/**
    开始游戏
 */
void start();

/**
 *  重新开始
 */
void restart();

/**
    创建角色
 */
void createPlayer();

/**
    创建一副牌
 */
void createPoker();

/**
    洗牌
 */
Card **shufflePoker(Card *pokers);

/**
    发牌
 */
void displayPoker(Card **pokers);

/**
    抢地主
 */
void grabLandlord();

/**
 *  抢到地主
 */
void grabLandlorded(Player *curPlayer);

/**
    开始出牌
 */
void play();

/**
    出牌
 */
bool popCards(Player *player, vector<int> popCardIndexs);

/**
    玩牌结束
 */
void gameOver(Player *player);

/**
    打印玩家手中的牌
 */
void printPlayerCards();

#endif /* Game_hpp */
