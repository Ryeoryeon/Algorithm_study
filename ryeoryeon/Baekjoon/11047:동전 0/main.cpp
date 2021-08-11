//
//  main.cpp
//  동전0
//
//  Created by 이영현 on 2021/08/06.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
using namespace std;
int coinList[10] = {0,};

int main(int argc, const char * argv[]) {
    int N, K, currentCoin = 0; //동전의 개수와 가치의 합
    cin>>N>>K;
    for(int i = 0; i < N; ++i)
        cin>>coinList[i];
    
    int coinPointer = N - 1; // 가장 가치가 큰 동전부터 조사해야 하므로
    while(K != 0)
    {
        if(K >= coinList[coinPointer]) // K<=coinList[coinPointer] 일 때는 같은 가치의 동전이 한 번 더 쓰일 수도 있다
        {
            K -= coinList[coinPointer];
            ++currentCoin;
        }
        
        else
            --coinPointer;
    }
    cout<<currentCoin;
    return 0;
}
