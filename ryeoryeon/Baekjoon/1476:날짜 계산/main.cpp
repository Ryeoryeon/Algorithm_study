//
//  main.cpp
//  날짜 계산
//
//  Created by 이영현 on 2021/06/29.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>

using namespace std;
int year = 1;
int E, S, M; // 지구, 태양, 달
int currentE = 1, currentS = 1, currentM = 1; // 현재 계산되고 있는 지구, 태양, 달의 연도

void findYear()
{
    ++currentE;
    ++currentS;
    ++currentM;
    ++year;
    
    // 범위를 넘기면 1로 초기화
    if(currentE > 15)
        currentE = 1;
    
    if(currentS > 28)
        currentS = 1;
    
    if(currentM > 19)
        currentM = 1;
    
    //findYear();
    return ;
}

int main(int argc, const char * argv[]) {
    cin>>E>>S>>M;
    //findYear();
    
    while(currentE != E || currentS != S || currentM != M)
        findYear();
    
    cout<<year;
    
    return 0;
}
