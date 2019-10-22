//
//  Util.hpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/18.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp
#include <iostream>
#include <vector>
#include "Card.hpp"

namespace mutil {
    /**
        快速排序
     */
    void myQuickSort(std::vector<int> arr,int start,int last);

    /**
        牌排序
     */
    void sort(std::vector<Card*>& pokers,int cardsCount);

    /**
        先根据点数，再根据花色排序
     */
    int compare1(Card* card1,Card* card2);
}


#endif /* Util_hpp */
