//
//  main.cpp
//  1, 2, 3 더하기 (3)
//
//  Created by 이영현 on 2021/07/03.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>


using namespace std;
int dividedNum;
int tempSaveFinal = 3; // 마지막으로 저장된 수
unsigned long long int divideMemo[1000001] = {0, };

void divideFunc(int num)
{
    if(divideMemo[num] != 0) // 이미 저장되어있는 경우, 바로 출력
        cout<<divideMemo[num] % 1000000009<<'\n'; // 개행 빼먹지 말자 ^^..
    
    else
    {
        for(int i = tempSaveFinal + 1; i <= num;++i)
        {
            divideMemo[i] = (divideMemo[i - 1] + divideMemo[i - 2] + divideMemo[i - 3]);
            divideMemo[i] %= 1000000009;
        }
        tempSaveFinal = num;
        cout<<divideMemo[num] % 1000000009 <<'\n';
    }
}

int main(int argc, const char * argv[]) {
    int testCase;
    cin>>testCase;
    
    divideMemo[1] = 1;
    divideMemo[2] = 2;
    divideMemo[3] = 4;
    
    for(int i = 0; i < testCase; ++i)
    {
        cin>>dividedNum;
        divideFunc(dividedNum);
    }
    
    return 0;
}
