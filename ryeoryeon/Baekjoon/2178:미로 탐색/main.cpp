//
//  main.cpp
//  2178 / 미로탐색
//
//  Created by 이영현 on 2021/03/10.
//  Copyright © 2021 이영현. All rights reserved.
//
// 00 : 07

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> isChecked;
vector<vector<int>> mazeMap;
int N, M; // N개의 줄과 M칸 (N * M) (행은 N, M은 열)

int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};

struct point
{
    int R;
    int C;
    int moveNum;
};

int BFS(int startR, int startC)
{
    queue<point> q;
    q.push({startR, startC, 1}); // 출발 칸도 포함해야하므로
    
    point idx;
    while(!q.empty())
    {
        idx = q.front();
        q.pop();
        
        // 과연 바로 리턴해도 될것인가?
        if(idx.R == N-1 && idx.C == M-1)
        {
            return idx.moveNum;
        }
        
        point next;
        for(int i=0; i<4; ++i)
        {
            next.R = idx.R + dR[i];
            next.C = idx.C + dC[i];
            
            // 위치 범위 확인
            if(next.R >= 0 && next.R < N && next.C >= 0 && next.C < M)
            {
                // 미로에서 이동할 수 있는 칸인지 확인(1인지 확인)하고, 방문체크 확인하기
                if(mazeMap[next.R][next.C] && !isChecked[next.R][next.C])
                {
                    next.moveNum = idx.moveNum + 1;
                    isChecked[next.R][next.C] = 1; // 방문체크 잊지말자!
                    q.push(next);
                }
            }
        }
        
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    mazeMap.assign(N, vector<int>(M, 0));
    isChecked.assign(N, vector<int>(M, 0));
    
    string temp;
    for(int i=0; i<N; ++i)
    {
        cin>>temp;
        for(int j=0; j<M; ++j)
        {
            mazeMap[i][j] = (temp[j] - '0');
        }
    }
    
    cout<<BFS(0, 0); // 행렬의 (1, 1)칸은 실제 배열의 (0, 0)
    
    return 0;
}

/*
 // 사고의 흐름
 미로 -> 아 ㅋㅋ 빼박 그래프!
 최소의 칸수니까 BFS
 
 서로 인접 칸으로만 이동 가능
 -> 이건 음.. dR dC로 본뒤에 그 칸에 0이 들어있는지 확인한다
 // 그런데 인접위치라는 말이 애매했는데 재영이가 보통 상하좌우라고 한다
 
 * 칸 셀 때 시작위치와 도착위치 포함해야함 주의
 
이건 일단 N, M 크기가 그렇게 크지 않으니까 일단은 미로의 정보 자체는 인접행렬로 받아보자
 
그리고 이동할 수 있는 칸은 1이다.. 이거땜에 무한루프걸려서.. 한참 찾음..
 */
