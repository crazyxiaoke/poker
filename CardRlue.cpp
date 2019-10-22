//
//  CardRlue.cpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/17.
//  Copyright © 2019 郑晓克. All rights reserved.
//
#include "CardRlue.hpp"

vector<int> CardRlue::getIsThreeCardValue(vector<Card *> cards)
{
  vector<int> threeCards;
  map<int, int> cardsMap;
  for (int i = 0; i < cards.size(); i++)
  {
    if (cardsMap.count(cards[i]->getValue()) == 0)
    {
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), 1));
    }
    else
    {
      int count = cardsMap[cards[i]->getValue()] + 1;
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), count));
    }
  }

  for (map<int, int>::iterator it = cardsMap.begin(); it != cardsMap.end(); it++)
  {
    if (it->second == 3)
    {
      threeCards.push_back(it->first);
    }
  }
  if (threeCards.size() > 1)
  {
    mutil::myQuickSort(threeCards, 0, (unsigned)threeCards.size() - 1);
  }
  return threeCards;
}

vector<int> CardRlue::getIsFourCardValue(vector<Card *> cards)
{
  vector<int> fourCards;
  map<int, int> cardsMap;
  for (int i = 0; i < cards.size(); i++)
  {
    if (cardsMap.count(cards[i]->getValue()) == 0)
    {
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), 1));
    }
    else
    {
      int count = cardsMap[cards[i]->getValue()] + 1;
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), count));
    }
  }

  for (map<int, int>::iterator it = cardsMap.begin(); it != cardsMap.end(); it++)
  {
    if (it->second == 4)
    {
      fourCards.push_back(it->first);
    }
  }
  if (fourCards.size() > 1)
  {
    mutil::myQuickSort(fourCards, 0, (unsigned)fourCards.size() - 1);
  }
  return fourCards;
}

bool CardRlue::isSingle(vector<Card *> cards)
{
  if (cards.size() == 1)
  {
    return true;
  }
  return false;
}

bool CardRlue::isDouble(vector<Card *> cards)
{
  if (cards.size() == 2)
  {
    if (cards[0]->getValue() == cards[1]->getValue())
    {
      return true;
    }
  }
  return false;
}

bool CardRlue::isThree(vector<Card *> cards)
{
  if (cards.size() == 3)
  {
    if (cards[0]->getValue() == cards[1]->getValue() && cards[1]->getValue() == cards[2]->getValue())
    {
      return true;
    }
  }
  return false;
}

bool CardRlue::isBoom(vector<Card *> cards)
{
  if (cards.size() == 4)
  {
    for (int i = 0; i < cards.size() - 1; i++)
    {
      if (cards[i]->getValue() != cards[i + 1]->getValue())
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool CardRlue::isStraight(vector<Card *> cards)
{
  if (cards.size() >= 5 && cards.size() <= 12)
  {
    for (int i = 0; i < cards.size() - 1; i++)
    {
      cout << cards[i]->getValue() << endl;
      //如果两张牌之间的差大于一，则出牌不合法
      if (cards[i + 1]->getValue() - cards[i]->getValue() != 1)
      {
        return false;
      }
      //牌不能超过Ace
      if (cards[i]->getValue() > Ace || cards[i + 1]->getValue() > Ace)
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool CardRlue::isDoubleStraight(vector<Card *> cards)
{
  if (cards.size() < 6 || cards.size() % 2 != 0)
  {
    return false;
  }
  for (int i = 0; i < cards.size() - 2; i += 2)
  {
    if (cards[i]->getValue() != cards[i + 1]->getValue() || cards[i + 2]->getValue() - cards[i]->getValue() != 1)
    {
      return false;
    }
    if (cards[i]->getValue() > Ace || cards[i + 2]->getValue() > Ace)
    {
      return false;
    }
  }
  return true;
}

bool CardRlue::isThreeStraight(vector<Card *> cards)
{
  if (cards.size() < 6 || cards.size() % 3 != 0)
  {
    return false;
  }
  for (int i = 0; i < cards.size() - 2; i += 3)
  {
    if (cards[i]->getValue() != cards[i + 1]->getValue())
    {
      return false;
    }
    if (cards[i + 1]->getValue() != cards[i + 2]->getValue())
    {
      return false;
    }
    if (i < cards.size() - 2)
    {
      if (cards[i + 2]->getValue() - cards[i]->getValue() != 1)
      {
        return false;
      }
    }
    if (cards[i]->getValue() > Ace)
    {
      return false;
    }
  }
  return true;
}

bool CardRlue::isThreeToOne(vector<Card *> cards)
{
  if (cards.size() != 4)
  {
    return false;
  }
  cout << "三带一" << endl;
  cout << cards[0]->getValue() << " " << cards[1]->getValue() << " " << cards[2]->getValue() << " " << cards[3]->getValue() << endl;
  cout << (cards[0]->getValue() == cards[1]->getValue() && cards[1]->getValue() == cards[2]->getValue()) << endl;
  if (cards[0]->getValue() == cards[1]->getValue() && cards[1]->getValue() == cards[2]->getValue())
  {
    return true;
  }
  cout << (cards[1]->getValue() == cards[2]->getValue() && cards[1]->getValue() == cards[3]->getValue()) << endl;
  if (cards[1]->getValue() == cards[2]->getValue() && cards[2]->getValue() == cards[3]->getValue())
  {
    return true;
  }
  return false;
}

bool CardRlue::isThreeToTwo(vector<Card *> cards)
{
  if (cards.size() != 5)
  {
    return false;
  }
  if (cards[0]->getValue() == cards[1]->getValue() == cards[2]->getValue() && cards[3]->getValue() == cards[4]->getValue())
  {
    return true;
  }
  if (cards[2]->getValue() == cards[3]->getValue() == cards[4]->getValue() && cards[0]->getValue() == cards[1]->getValue())
  {
    return true;
  }
  return false;
}

bool CardRlue::isJokerBoom(vector<Card *> cards)
{
  if (cards.size() != 2)
  {
    return false;
  }
  if (cards[0]->getValue() == SJoker && cards[1]->getValue() == LJoker)
  {
    return true;
  }
  else if (cards[0]->getValue() == LJoker && cards[1]->getValue() == SJoker)
  {
    return true;
  }
  return false;
}

bool CardRlue::isThreeStraightToOne(vector<Card *> cards)
{
  if (cards.size() < 8 || cards.size() % 2 != 0)
  {
    return false;
  }
  vector<int> threeCards;
  int threeCardsCount = 0;
  int oneCardsCount = 0;
  map<int, int> cardsMap;

  for (int i = 0; i < cards.size(); i++)
  {
    if (cardsMap.count(cards[i]->getValue()) == 0)
    {
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), 1));
    }
    else
    {
      int count = cardsMap[cards[i]->getValue()] + 1;
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), count));
    }
  }

  for (map<int, int>::iterator it = cardsMap.begin(); it != cardsMap.end(); it++)
  {
    if (it->second > 3)
    {
      return false;
    }
    if (it->second == 3)
    {
      threeCards.push_back(it->first);
      threeCardsCount++;
    }
    else
    {
      oneCardsCount += it->second;
    }
  }

  mutil::myQuickSort(threeCards, 0, (unsigned)threeCards.size() - 1);
  for (int i = 0; i < threeCards.size() - 1; i++)
  {
    if (threeCards[i + 1] - threeCards[i] != 1)
    {
      oneCardsCount += 3;
      threeCardsCount--;
    }
    if (threeCards[i + 1] > Ace || threeCards[i] > Ace)
    {
      threeCardsCount--;
      oneCardsCount += 3;
    }
  }

  if (threeCardsCount != oneCardsCount)
  {
    return false;
  }

  return true;
}

bool CardRlue::isThreeStraightToTwo(vector<Card *> cards)
{
  if (cards.size() < 10 || cards.size() % 5 != 0)
  {
    return false;
  }
  vector<int> threeCards;
  map<int, int> cardsMap;
  int threeCardsCount = 0;
  int twoCardsCount = 0;

  for (int i = 0; i < cards.size(); i++)
  {
    if (cardsMap.count(cards[i]->getValue()) == 0)
    {
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), 1));
    }
    else
    {
      int count = cardsMap[cards[i]->getValue()] + 1;
      cardsMap.insert(pair<int, int>(cards[i]->getValue(), count));
    }
  }

  for (map<int, int>::iterator it = cardsMap.begin(); it != cardsMap.end(); it++)
  {
    if (it->second == 1)
    {
      return false;
    }
    if (it->second == 3)
    {
      threeCards.push_back(it->first);
      threeCardsCount++;
    }
    else if (it->second == 4)
    {
      twoCardsCount += 2;
    }
    else
    {
      twoCardsCount++;
    }
  }

  if (threeCardsCount != twoCardsCount)
  {
    return false;
  }

  mutil::myQuickSort(threeCards, 0, (unsigned)threeCards.size() - 1);
  for (int i = 0; i < threeCards.size() - 1; i++)
  {
    if (threeCards[i + 1] - threeCards[i] != 1)
    {
      return false;
    }
    if (threeCards[i] > Ace || threeCards[i + 1] > Ace)
    {
      return false;
    }
  }

  return true;
}

bool CardRlue::isFourToOne(vector<Card *> cards)
{
  return false;
}

bool CardRlue::isFourToTwo(vector<Card *> cards)
{
  return false;
}

CardType CardRlue::getCardsType(vector<Card *> cards)
{
  int count = (unsigned)cards.size();
  switch (count)
  {
  case 1:
    if (isSingle(cards))
    {
      //单牌
      return Single;
    }
    break;
  case 2:
    if (isDouble(cards))
    {
      //对子
      return Double;
    }
    else if (isJokerBoom(cards))
    {
      //王炸
      return JokerBoom;
    }
    break;
  case 3:
    if (isThree(cards))
    {
      //三张（不带）
      return MThree;
    }
    break;
  case 4:
    if (isBoom(cards))
    {
      //炸弹
      return Boom;
    }
    else if (isThreeToOne(cards))
    {
      //三带一
      return MThreeToOne;
    }
    break;
  case 5:
    if (isThreeToTwo(cards))
    {
      //三带二
      return MThreeToTwo;
    }
    else if (isFourToOne(cards))
    {
      //四带一
      return FourToOne;
    }
    else if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    break;
  case 6:
    if (isFourToOne(cards))
    {
      //四带一
      return FourToOne;
    }
    else if (isFourToTwo(cards))
    {
      //四带二
      return FourToTwo;
    }
    else if (isThreeStraight(cards))
    {
      //飞机（不带）
      return ThreeStraight;
    }
    else if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    break;
  case 7:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    break;
  case 8:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    else if (isThreeStraightToOne(cards))
    {
      //飞机(三带一)
      return ThreeStraightToOne;
    }
    else if (isFourToTwo(cards))
    {
      //四带二
      return FourToTwo;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    break;
  case 9:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isThreeStraight(cards))
    {
      //飞机（不带张）
      return ThreeStraight;
    }
    break;
  case 10:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isThreeStraightToTwo(cards))
    {
      //飞机（三带二）
      return ThreeStraightToTwo;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    break;
  case 11:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    break;
  case 12:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isThreeStraightToOne(cards))
    {
      //飞机（三带一）
      return ThreeStraightToOne;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    else if (isThreeStraight(cards))
    {
      //飞机（不带张）
      return ThreeStraight;
    }
    break;
  case 13:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    break;
  case 14:
    if (isStraight(cards))
    {
      //顺子
      return Straight;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    break;
  case 15:
    if (isThreeStraightToTwo(cards))
    {
      //飞机（三带二）
      return ThreeStraightToTwo;
    }
    else if (isThreeStraight(cards))
    {
      //飞机（不带张）
      return ThreeStraight;
    }
    break;
  case 16:
    if (isThreeStraightToOne(cards))
    {
      //飞机（三带一）
      return ThreeStraightToOne;
    }
    else if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    break;
  case 17:
    break;
  case 18:
    if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    else if (isThreeStraight(cards))
    {
      //飞机（不带张）
      return ThreeStraight;
    }
    break;
  case 19:
    break;
  case 20:
    if (isDoubleStraight(cards))
    {
      //连对
      return DoubleStraight;
    }
    else if (isThreeStraightToOne(cards))
    {
      //飞机（三带一）
      return ThreeStraightToOne;
    }
    else if (isThreeStraightToTwo(cards))
    {
      //飞机（三带二）
      return ThreeStraightToTwo;
    }
    else if (isFourToOne(cards))
    {
      return FourToOne;
    }
    break;
  default:
    break;
  }
  return Error;
}

bool CardRlue::compareCards(vector<Card *> nowCards,
                            vector<Card *> lastCards,
                            CardType *lastType)
{
  if (*lastType == None)
  {
    CardType type = getCardsType(nowCards);
    cout << "type=" << getCardsTypeName(type) << endl;
    if (type != Error)
    {
      *lastType = type;
      return true;
    }
    return false;
  }
  else
  {
    CardType nowType = getCardsType(nowCards);
    if (nowType == JokerBoom)
    {
      *lastType = nowType;
      return true;
    }
    if (nowType == *lastType)
    {
      if (*lastType == Single || *lastType == Double || *lastType == MThree)
      {
        if (nowCards[0]->getValue() > lastCards[0]->getValue())
        {
          *lastType = nowType;
          return true;
        }
      }
      else if (*lastType == Straight || *lastType == DoubleStraight || *lastType == ThreeStraight || *lastType == Boom)
      {
        if (nowCards.size() == lastCards.size())
        {
          if (nowCards[0]->getValue() > lastCards[0]->getValue())
          {
            *lastType = nowType;
            return true;
          }
        }
      }
      else if (*lastType == MThreeToOne || *lastType == MThreeToTwo)
      {
        vector<int> nowCardsThrees = getIsThreeCardValue(nowCards);
        vector<int> lastCardsThrees = getIsThreeCardValue(lastCards);
        if (nowCardsThrees[0] > lastCardsThrees[0])
        {
          *lastType = nowType;
          return true;
        }
      }
      else if (*lastType == ThreeStraightToOne || *lastType == ThreeStraightToTwo)
      {
        if (nowCards.size() == lastCards.size())
        {
          vector<int> nowCardsThrees = getIsThreeCardValue(nowCards);
          vector<int> lastCardsThrees = getIsThreeCardValue(lastCards);
          if (nowCardsThrees[0] > lastCardsThrees[0])
          {
            *lastType = nowType;
            return true;
          }
        }
      }
      else if (*lastType == FourToOne || *lastType == FourToTwo)
      {
        vector<int> nowCardsFours = getIsFourCardValue(nowCards);
        vector<int> lastCardsFours = getIsFourCardValue(lastCards);
        if (nowCardsFours[0] > lastCardsFours[0])
        {
          *lastType = nowType;
          return true;
        }
      }
    }
  }
  return false;
}

char *CardRlue::getCardsTypeName(CardType type)
{
  char typeStr[16] = {0}; //0=='\0'
  switch (type)
  {
  case Single:
    strcpy(typeStr, "单牌");
    break;
  case Double:
    strcpy(typeStr, "一对");
    break;
  case MThree:
    strcpy(typeStr, "三不带");
    break;
  case MThreeToOne:
    strcpy(typeStr, "三带一");
    break;
  case MThreeToTwo:
    strcpy(typeStr, "三带二");
    break;
  case Straight:
    strcpy(typeStr, "顺子");
    break;
  case DoubleStraight:
    strcpy(typeStr, "连对");
    break;
  case ThreeStraight:
    strcpy(typeStr, "飞机(三不带)");
    break;
  case ThreeStraightToOne:
    strcpy(typeStr, "飞机(三带一)");
    break;
  case ThreeStraightToTwo:
    strcpy(typeStr, "飞机(三带二)");
    break;
  case Boom:
    strcpy(typeStr, "炸弹");
    break;
  case JokerBoom:
    strcpy(typeStr, "王炸");
    break;
  default:
    strcpy(typeStr, "错误");
    break;
  }
  char *ret = (char *)malloc(16);
  sprintf(ret, "%s", typeStr);
  return ret;
}
