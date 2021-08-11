//
//  main.cpp
//  PPAP
//
//  Created by 이영현 on 2021/08/06.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int pNum =0, size;
    string input;
    cin>>input;
    size = input.size();
    
    for(int i = 0; i < size; ++i)
    {
        if(input[i] == 'A')
        {
            if(pNum >= 2 && (i + 1) < size && input[i + 1] == 'P')
                pNum -= 2;
            
            else
            {
                cout<<"NP";
                return 0;
            }
        }
        
        else // 'P'
            ++pNum;
    }
    
    if(pNum == 1)
        cout<<"PPAP";
    else
        cout<<"NP";
    return 0;
}
