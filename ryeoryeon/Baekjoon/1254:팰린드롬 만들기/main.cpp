//
//  main.cpp
//  팰린드롬 만들기
//
//  Created by 이영현 on 2021/09/09.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
string str;

bool checkPalindrome(const string str, int startIdx)
{
    int fullLength = str.length();
    int length = fullLength - startIdx;
    string tempStr = str.substr(startIdx, length); // 0이면 0 ~ n-1, 1이면 1 ~ n-1
    
    for(int i = 0; i < (length / 2); ++i)
    {
        if(tempStr[i] != tempStr[length - 1 - i])
            return 0;
    }
    return 1; // true
}

int main(int argc, const char * argv[]) {
    cin>>str;
    int fullLength = str.length();
    int minLenth = fullLength - 1; // 최소 팰린드롬의 길이 (맨 마지막 문자를 제외하고 대칭시키면 되므로 -1)
    
    // 기저 사례
    if(fullLength == 1)
    {
        cout<<1;
        return 0;
    }
    
    for(int i = 0; i < (fullLength- 1); ++i)
    {
        if(checkPalindrome(str, i))
        {
            minLenth = i;
            break;
        }
    }
    
    cout<<minLenth + fullLength;
    
    return 0;
}
