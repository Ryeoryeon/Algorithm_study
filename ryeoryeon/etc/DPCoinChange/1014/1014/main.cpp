//
//  main.cpp
//  1014 (DPCoinChange)
//
//  Created by 이영현 on 2020/06/01.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib> // atoi
#include <cstring> // getline
#include <sstream> // istringstream

#define INF 9999999
#define MAX_LENTH 100000

using namespace std;

/*
 
 액면이 서로 다른 k개의 동전이 존재할 때, 이 동전들을 사용하며 n만큼의 거스름돈을 거슬러 주려고 한다.
 이 때, 거슬러주는 동전의 개수를 최소화하면서 거스름돈을 거슬러주는 프로그램을 작성하시오.
 
 */

vector<int> change_list;
vector<int> coin_list ;

int main(int argc, const char * argv[]) {
    
    coin_list.assign(10, 0);
    
    int money, index = 0;
    char temp_list[MAX_LENTH];
    
    string s;
    getline(cin, s); // string을 인자로 주는 경우 cstring의 getline을 사용해야 한다
    
    istringstream string_cut(s); // std::istringstream N(string);
    
    while(getline(string_cut, s, ','))
    {
        coin_list[index] = stoi(s);
        index++;
    }
    
    // 벡터의 실제 값들이 들어있는 총 사이즈값 == index
    
    cin>>money;
    change_list.assign(money+1, INF);
    
    change_list[0] = 0;
    
    for(int i=1; i<=money; i++)
    {
        for(int j=0; j<index; j++)
        {
            //이 코인으로 갱신할 수 있는 경우!
            if(coin_list[j] <= i && change_list[i-coin_list[j]]+1 < change_list[i])
                change_list[i] = change_list[i - coin_list[j]] + 1;
        }
    }

    cout<<change_list[money];
    
    return 0;
}
