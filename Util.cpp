//
//  Util.cpp
//  Poker
//
//  Created by 郑晓克 on 2019/10/18.
//  Copyright © 2019 郑晓克. All rights reserved.
//

#include "Util.hpp"

namespace mutil {

    void myQuickSort(std::vector<int> arr,int start,int last){
        int i=start;
        int j=last;
        int temp=arr[i];
        if(i<j){
            while(i<j){
                while(i<j&&arr[j]>=temp){
                    j--;
                    
                }
                if(i<j){
                    arr[i]=arr[j];
                    i++;
                }
                
                while(i<j&&temp>arr[i])
                    i++;
                if(i<j){
                    arr[j]=arr[i];
                    j--;
                }
            }
            arr[i]=temp;
            myQuickSort(arr, start,i-1);
            myQuickSort(arr,i+1 ,last);
        }
    }

    void sort(std::vector<Card*>& cards,int cardsCount){
        int i;
        for(i=0;i<cardsCount-1;i++){
            int j;
            for(j=0;j<cardsCount-i-1;j++){
                if(mutil::compare1(cards[j], cards[j+1])){
                    Card* tmp=cards[j];
                    cards[j]=cards[j+1];
                    cards[j+1]=tmp;
                }
            }
        }
    }

    int compare1(Card* card1,Card* card2){
        if(card1->getValue()>card2->getValue()){
            return 1;
        }else if(card1->getValue()<card2->getValue()){
            return 0;
        }else{
            if(card1->getSuit()>card2->getSuit()){
                return 1;
            }else{
                return 0;
            }
        }
    }

}
