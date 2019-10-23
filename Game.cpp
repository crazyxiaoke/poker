//
//  Game.cpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/18.
//  Copyright © 2019 郑晓克. All rights reserved.
//
#include "Game.hpp"

Player *gloablPlayers[PLAYER_COUNT];

int main(int argc, const char *argv[])
{
  start();
  return 0;
}

void start()
{
  CardType ct = None;
  lastType = &ct;
  //创建一副牌
  createPoker();
  //创建角色
  //    createPlayer();
  Player p1("张三", 0);
  Player p2("李四", 0);
  Player p3("王五", 0);
  gloablPlayers[0] = &p1;
  gloablPlayers[1] = &p2;
  gloablPlayers[2] = &p3;
  //洗牌
  Card **shuffle = shufflePoker(pokers);
  //发牌
  displayPoker(shuffle);
  free(shuffle);
  //打印各方手牌
  printPlayerCards();
  //抢地主
  grabLandlord();
  //开始打牌
  play();
}

void reStart()
{
  //洗牌
  Card **shuffle = shufflePoker(pokers);
  //发牌
  displayPoker(shuffle);
  free(shuffle);
  //打印各方手牌
  printPlayerCards();
  //抢地主
  grabLandlord();
  //开始打牌
  play();
}

void createPoker()
{
  int i = 0;
  for (i = 0; i < CARD_COUNT - 2; i++)
  {
    pokers[i].setValue(CardWeight(i / 4));
    pokers[i].setSuit(Suit(i % 4));
  }

  pokers[i].setValue(SJoker);
  pokers[i].setSuit(smallJoker);

  pokers[i + 1].setValue(LJoker);
  pokers[i + 1].setSuit(bigJoker);
}

void createPlayer()
{
  Player p1("张三", 0);
  Player p2("李四", 0);
  Player p3("王五", 0);
  gloablPlayers[0] = &p1;
  gloablPlayers[1] = &p2;
  gloablPlayers[2] = &p3;
}

Card **shufflePoker(Card *pokers)
{
  int i;
  Card **retPokers = (Card **)malloc(CARD_COUNT * sizeof(Card *));
  Card **pokers2 = (Card **)malloc(CARD_COUNT * sizeof(Card *));
  for (i = 0; i < CARD_COUNT; i++)
  {
    pokers2[i] = &pokers[i];
  }
  srand((unsigned)time(NULL));
  for (i = 0; i < CARD_COUNT; i++)
  {
    unsigned int index = rand() % CARD_COUNT;
    if (pokers2[index] != NULL)
    {
      retPokers[i] = pokers2[index];
      pokers2[index] = NULL;
    }
    else
    {
      i--;
    }
  }
  free(pokers2);
  return retPokers;
}

/**
    发牌
 */
void displayPoker(Card **shufflePokers)
{
  int i;
  for (i = 0; i < CARD_COUNT - LANDLORD_CARD_COUNT; i++)
  {
    Player *curPlayer = gloablPlayers[i % PLAYER_COUNT];
    curPlayer->addCards(shufflePokers[i]);
  }
  for (int j = 0; j < LANDLORD_CARD_COUNT; j++)
  {
    landlordCard.push_back(shufflePokers[i + j]);
  }
}

void grabLandlord()
{
  int score = 0;
  int index = 0;
  int noGrabCount = 0;
  Player *lastGrabPalyer;
  while (true)
  {
    int _score = 0;
    Player *curPlayer = gloablPlayers[index++];
    cout << "【" << curPlayer->getName() << "】"
         << "开始抢地主" << endl;
    cout << "【" << curPlayer->getName() << "】:";
    cin >> _score;
    if (_score == -1)
    {
      noGrabCount++;
      if (noGrabCount == PLAYER_COUNT)
      {
        grabLandlorded(gloablPlayers[0]);
        return;
      }
      else if (noGrabCount == PLAYER_COUNT - 1)
      {
        grabLandlorded(lastGrabPalyer);
        return;
      }
      cout << "【" << curPlayer->getName() << "】"
           << "不抢地主" << endl;
      continue;
    }
    if (_score <= score)
    {
      cout << "【" << curPlayer->getName() << "】:"
           << "报分必须比上个玩家报的分高" << endl;
      continue;
    }
    lastGrabPalyer = curPlayer;
    score = _score;
    if (score == 3)
    {
      grabLandlorded(curPlayer);
      return;
    }
  }
}

/*
  抢到地主
*/
void grabLandlorded(Player *curPlayer)
{
  cout << curPlayer << endl;
  curPlayer->setPlayerType(Landlord);
  cout << "【" << curPlayer->getName() << "】"
       << "抢到地主了" << endl;
  //打印地主牌
  mutil::sort(landlordCard, LANDLORD_CARD_COUNT);
  cout << "地主牌:";
  for (int i = 0; i < LANDLORD_CARD_COUNT; i++)
  {
    curPlayer->addCards(landlordCard[i]);
    cout << getCardName(landlordCard[i]) << " ";
  }
  cout << endl;
  printPlayerCards();
}

void play()
{
  int index = 0;
  for (int i = 0; i < PLAYER_COUNT; i++)
  {
    if (gloablPlayers[i]->getPlayerType() == Landlord)
    {
      index = i;
    }
  }
  int passCount = 0;
  while (true)
  {
    Player *curPlayer = gloablPlayers[index % PLAYER_COUNT];
    cout << "【" << curPlayer->getName() << "】"
         << "开始出牌:";
    vector<int> popCardIndexs;
    int cardNums;
    while (cin >> cardNums)
    {
      if (cardNums == -1)
      {
        if (popCards(curPlayer, popCardIndexs))
        {
          printPlayerCards();
          break;
        }
        else
        {
          cout << "【" << curPlayer->getName() << "】"
               << "出牌类型错误" << endl;
          popCardIndexs.clear();
          continue;
        }
      }
      else if (cardNums == -2)
      {
        passCount++;
        cout << "【" << curPlayer->getName() << "】"
             << "要不起" << endl;
        break;
      }
      else
      {
        popCardIndexs.push_back(cardNums);
      }
    }
    if (passCount == 2)
    {
      passCount = 0;
      *lastType = None;
    }
    if (curPlayer->getCardsCount() == 0)
    {
      cout << "====================打牌结束====================" << endl;
      gameOver(curPlayer);
      break;
    }
    index++;
  }
}

bool popCards(Player *player, vector<int> popCardIndexs)
{
  vector<Card *> playCards;
  for (int i = 0; i < popCardIndexs.size(); i++)
  {
    playCards.push_back(player->getCards()[popCardIndexs[i] - 1]);
  }
  int count = (unsigned)playCards.size();
  mutil::sort(playCards, count);
  if (rlue.compareCards(playCards, lastCards, lastType))
  {
    system("clear");
    lastCards = playCards;
    cout << "【" << player->getName() << "】"
         << "打出：";
    for (int i = 0; i < playCards.size(); i++)
    {
      cout << getCardName(playCards[i]);
      player->removeCards(playCards[i]);
    }
    cout << "(" << rlue.getCardsTypeName(*lastType) << ")";
    cout << endl;
  }
  else
  {
    return false;
  }
  return true;
}

void gameOver(Player *player)
{
  if (player->getPlayerType() == Landlord)
  {
    cout << "【" << player->getName() << "】"
         << "地主赢了" << endl;
  }
  else
  {
    cout << "【" << player->getName() << "】"
         << "农民赢了" << endl;
  }

  for (int i = 0; i < PLAYER_COUNT; i++)
  {
    gloablPlayers[i]->clearCards();
  }
}

char *getCardName(Card *card)
{
  char suitStr[16] = {0}; //0=='\0'
  switch (card->getSuit())
  {
  case heart:
    strcpy(suitStr, "红桃");
    break;
  case spade:
    strcpy(suitStr, "黑桃");
    break;
  case diamond:
    strcpy(suitStr, "方块");
    break;
  case club:
    strcpy(suitStr, "梅花");
    break;
  default:
    break;
  }

  char valueStr[16];
  switch (card->getValue())
  {
  case Jack:
    strcpy(valueStr, "J");
    break;
  case Queen:
    strcpy(valueStr, "Q");
    break;
  case King:
    strcpy(valueStr, "K");
    break;
  case Ace:
    strcpy(valueStr, "A");
    break;
  case Two:
    strcpy(valueStr, "2");
    break;
  case SJoker:
    strcpy(valueStr, "小王");
    break;
  case LJoker:
    strcpy(valueStr, "大王");
    break;
  default:
    sprintf(valueStr, "%d", card->getValue() + 3);
    break;
  }
  char *ret = (char *)malloc(16);
  sprintf(ret, "%s%s", suitStr, valueStr);
  return ret;
}

void printPlayerCards()
{
  cout << endl
       << endl
       << endl;
  cout << "======================================================" << endl;
  for (int i = 0; i < PLAYER_COUNT; i++)
  {
    mutil::sort(gloablPlayers[i]->getCards(),
                gloablPlayers[i]->getCardsCount());
    cout << "【" << gloablPlayers[i]->getName() << "】"
         << ".手牌数:"
         << gloablPlayers[i]->getCardsCount() << endl;
    cout << "【" << gloablPlayers[i]->getName() << "】"
         << ".手牌:";
    for (int j = 0; j < gloablPlayers[i]->getCardsCount(); j++)
    {
      cout << getCardName(gloablPlayers[i]->getCards()[j])
           << "(" << j + 1 << ")"
           << " ";
    }
    cout << endl;
  }
  cout << "======================================================" << endl;
}
