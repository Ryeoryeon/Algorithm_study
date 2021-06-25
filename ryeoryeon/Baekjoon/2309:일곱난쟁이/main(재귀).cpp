//
//  main.cpp
//  일곱 난쟁이
//
//  Created by 이영현 on 2021/06/25.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> unpickDwarf; // 뽑히지 못한 난쟁이들
int dwarf[9];
int dwarfSum = 0; // 9명 난쟁이들의 키의 합
static int firstIdx = 0;

void findDwarf()
{
    // 사이즈가 2이면 재귀 회수
    if(unpickDwarf.size() == 2)
    {
        int sum, tempSum = 0;
        for(int i = 0; i < 2; ++i)
            tempSum += unpickDwarf[i];
        
        sum = dwarfSum - tempSum;
        if(sum == 100)
        {
            sort(dwarf, dwarf + 9);
            for(int i = 0; i < 9; ++i)
            {
                if(dwarf[i] != unpickDwarf[0] && dwarf[i] != unpickDwarf[1])
                    cout<<dwarf[i]<<'\n';
            }
            
            exit(0); // 하나만 출력하면 되니 바로 종료시키기
        }
    }
    
    else
    {
        // 비어있을 경우
        if(unpickDwarf.empty())
            unpickDwarf.push_back(dwarf[firstIdx]);
        
        for(int i = firstIdx + 1; i < 9; ++i)
        {
            unpickDwarf.push_back(dwarf[i]);
            findDwarf();
            
            if(i == 8) // 끝까지 돌아온 경우, firstIdx 증가
            {
                // 벡터도 초기화
                unpickDwarf.pop_back();
                unpickDwarf.pop_back();
                ++firstIdx;
                findDwarf();
                break;
            }
            
            unpickDwarf.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    
    for(int i=0; i<9; ++i)
    {
        cin>>dwarf[i];
        dwarfSum += dwarf[i];
    }
    
    // 9명 중 7명의 키 합이 100일 경우, 바로 출력!
    findDwarf();
    
    return 0;
}
