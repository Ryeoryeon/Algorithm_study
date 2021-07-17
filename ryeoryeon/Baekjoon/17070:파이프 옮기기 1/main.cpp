//
//  main.cpp
//  파이프 옮기기 1
//
//  Created by 이영현 on 2021/07/17.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, r, c; // 집의 크기, 행, 열
int houseStatus[16][16];
int wayNum = 0;

// 비어있는지 체크해야할 위치들
vector<vector<int>> checkR;
vector<vector<int>> checkC;

// 다음 위치에 따른 moveCase
vector<vector<int>> nextMoveCase;

// →, ↘, ↓ 순서
void initialize()
{
    checkR.resize(3);
    checkC.resize(3);
    nextMoveCase.resize(3);
    
    // 가로
    checkR[0].push_back(0);
    checkC[0].push_back(1);
    nextMoveCase[0].push_back(0); // 다음 상태는 가로
    
    checkR[0].push_back(1);
    checkC[0].push_back(1);
    nextMoveCase[0].push_back(1); // 다음 상태는 대각선
    
    // 대각선
    checkR[1].push_back(0);
    checkC[1].push_back(1);
    nextMoveCase[1].push_back(0); // 다음 상태는 가로
    
    checkR[1].push_back(1);
    checkC[1].push_back(1);
    nextMoveCase[1].push_back(1); // 다음 상태는 대각선
    
    checkR[1].push_back(1);
    checkC[1].push_back(0);
    nextMoveCase[1].push_back(2); // 다음 상태는 세로
    
    // 세로
    checkR[2].push_back(1);
    checkC[2].push_back(1);
    nextMoveCase[2].push_back(1); // 다음 상태는 대각선
    
    checkR[2].push_back(1);
    checkC[2].push_back(0);
    nextMoveCase[2].push_back(2); // 다음 상태는 세로
}

void pipeFunc(int tempR, int tempC, int moveCase)
{
    // 재귀 회수 (1) : 파이프의 한 쪽 끝이 (N,N)에 도달했을 때
    if(tempR == (N - 1) && tempC == (N - 1))
    {
        ++wayNum;
        return ;
    }
    
    // 다음 이동 지점이 벽이지 않으면 다음 재귀 호출
    // moveCase에 따라 조사 지점 다름 (0 == 가로, 1 == 대각선, 2 == 세로)
    unsigned int checkSize = checkR[moveCase].size();
    int nextR, nextC, nextMove;
    for(int i = 0; i < checkSize; ++i)
    {
        nextR = tempR + checkR[moveCase][i];
        nextC = tempC + checkC[moveCase][i];
        nextMove = nextMoveCase[moveCase][i];
        
        if(nextR < N && nextC < N) // 다음 위치가 사이즈 N을 초과하지 않고, 벽이 아니라면 재귀 호출
        {
            // 대각선일 경우
            if(nextMove == 1)
            {
                if(!houseStatus[nextR][nextC] && !houseStatus[nextR - 1][nextC] && !houseStatus[nextR][nextC - 1])
                    pipeFunc(nextR, nextC, nextMove);
            }
            
            // 대각선이 아닐 경우
            else if(!houseStatus[nextR][nextC])
                pipeFunc(nextR, nextC, nextMove);
        }
    }
    
    return ;
    
}

int main(int argc, const char * argv[]) {
    cin>>N;
    initialize();
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cin>>houseStatus[i][j];
    }
    
    pipeFunc(0, 1, 0);
    cout<<wayNum;
    
    return 0;
}
