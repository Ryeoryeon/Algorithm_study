//
//  main.cpp
//  20208:진우의민트초코우유
//
//  Created by 이영현 on 2021/01/07.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> village;
int mintNum = 0;
int mintHP;

int HomeR, HomeC;

int findMint(int HP, int startR, int startC, int maxMint, int index, vector<int> mintListR, vector<int> mintListC)
{
    // maxMint == mintNum이 되면 더이상 함수가 돌아갈 필요 X
    if(maxMint == mintNum)
        return maxMint;
    
    // 방금 전의 반복문에서 조사했던 민초 제외
    if(index >= 0)
    {
        mintListR.erase(mintListR.begin() + index);
        mintListC.erase(mintListC.begin() + index);
    }

    for(int j=0; j < mintListR.size(); j++)
    {
        // 민트초코를 얻고 다시 돌아올 수 없는 경우
        int distance1 = abs(startR - mintListR[j]) + abs(startC - mintListC[j]);
        int distance2 = abs(HomeR - mintListR[j]) + abs(HomeC - mintListC[j]);
        int distance = distance1 + distance2;
        
        if((distance - mintHP) > HP)
            continue;
        
        return findMint((HP - distance1 + mintHP), mintListR[j], mintListC[j], ++maxMint, j, mintListR, mintListC);
    }
    
    // 이제 더이상 민트초코우유를 겟할 수 없는 경우
    return maxMint;
}

int main(int argc, const char * argv[]) {
    
    // 순서대로 상하좌우
    // int dr[4] = {0, 1, 0, -1};
    // int dc[4] = {-1, 0, 1, 0};
    
    int villSize, HP, maxMint = 0;
    cin>>villSize>>HP>>mintHP;
    
    vector<int> mintListR;
    vector<int> mintListC;
    village.assign(villSize, vector<int>(villSize, 0));
    for(int j=0; j<villSize; j++)
    {
        for(int k=0; k<villSize; k++)
        {
            cin>>village[j][k];
            if(village[j][k] == 2)
            {
                mintNum++;
                mintListR.push_back(j);
                mintListC.push_back(k);
            }
            
            else if(village[j][k] == 1)
            {
                HomeR = j;
                HomeC = k;
            }
        }
    }
    
    maxMint = findMint(HP, HomeR, HomeC, maxMint, -1, mintListR, mintListC);
    
    cout<<maxMint;
    
    return 0;
}
