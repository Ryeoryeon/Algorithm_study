//
//  main.cpp
//  일곱 난쟁이
//
//  Created by 이영현 on 2021/01/31.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    int height_list[9];
    int idx_list[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};
    
    for(int i=0; i<9; ++i)
        cin>>height_list[i];

    // 일곱 난쟁이의 합은 100이 되어야 한다
    // 저번 시간에 배운 순열을 이용해서 풀어보자
    sort(height_list, height_list+9);
    
    do
    {
        int sum = 0;
        for(int i=0; i<9; ++i)
        {
            if(idx_list[i])
                sum += height_list[i];
        }
        
        if(sum == 100)
            break;
    }while(next_permutation(idx_list, idx_list+9));
    
    for(int i=0; i<9; ++i)
    {
        if(idx_list[i] && i!=8)
            cout<<height_list[i]<<'\n';
        
        else if(i==8 && idx_list[i])
            cout<<height_list[i]<<'\n'; // 마지막에는 엔터 출력 X
    }
    
    return 0;
}
