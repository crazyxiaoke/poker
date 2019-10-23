//
//  Player.cpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#include "Player.hpp"
Player::Player()
{
  name = new char[1];
  name[0] = '\0';
  cardsCount = 0;
  playerType = Farmer;
}

Player::Player(const char *_name, int _cardsCount)
{
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  cardsCount = _cardsCount;
  playerType = Farmer;
}

char *Player::getName()
{
  return name;
}

void Player::addCards(Card *card)
{
  cards.push_back(card);
  cardsCount++;
}

void Player::removeCards(Card *card)
{
  if (cards.size() > 0)
  {
    for (int i = 0; i < cards.size(); i++)
    {
      if (cards[i]->getValue() == card->getValue() &&
          cards[i]->getSuit() == card->getSuit())
      {
        cards.erase(cards.begin() + i);
        cardsCount--;
        return;
      }
    }
  }
}

vector<Card *> &Player::getCards()
{
  return cards;
}

int Player::getCardsCount()
{
  return cardsCount;
}

void Player::setPlayerType(PlayerType playerType)
{
  this->playerType = playerType;
}

PlayerType Player::getPlayerType()
{
  return this->playerType;
}

void Player::clearCards()
{
  this->cards.clear();
  cardsCount = 0;
}
