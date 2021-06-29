//
//  main.cpp
//  1로 만들기
//
//  Created by 이영현 on 2021/05/07.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int minNumList [1000001] = {0,};
    minNumList[2] = 1;
    int num;
    cin>>num;
    
    if(num <= 2)
    {
        cout<<minNumList[num];
        return 0;
    }
    
    for(int i=3; i<=num; ++i) // num >= 3인 경우
    {
        int tempMin = 99999999;
        
        if(i % 3 == 0)
            tempMin = minNumList[i / 3] + 1;
        
        if(i % 2 == 0)
            tempMin = min(tempMin, (minNumList[i/2] + 1));
        
        tempMin = (min(tempMin, minNumList[i - 1] + 1));
        minNumList[i] = tempMin;
    }
       
    cout<<minNumList[num];
    return 0;
}
