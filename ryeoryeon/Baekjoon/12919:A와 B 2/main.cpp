//
//  main.cpp
//  A와 B 2
//
//  Created by 이영현 on 2021/08/11.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string S,T; // 바꿔야 할 문자열과 타겟 문자열
bool isChangable = 0;

void changeTtoS(string currentT) // T에서 S를 접근해보자
{
    if(currentT == S)
    {
        isChangable = 1;
        return ;
    }
    
    int size = currentT.size();
    char temp = currentT[size - 1];
    char temp2 = currentT[0];
    if(currentT[size - 1] != 'A' && currentT[0] != 'B') // 두 경우가 모두 불가능한 경우 (재귀 회수)
         return ;
    
    if(currentT[size - 1] == 'A')
    {
        currentT.pop_back();
        changeTtoS(currentT);
        currentT += 'A'; // 혹시 다음 B조건에 걸릴 수도 있으니까 복구
    }
    
    if(currentT[0] == 'B')
    {
        reverse(currentT.begin(), currentT.end());
        currentT.pop_back();
        changeTtoS(currentT);
    }
}

int main(int argc, const char * argv[]) {
    cin>>S>>T;
    changeTtoS(T);
    
    cout<<isChangable;
    return 0;
}
