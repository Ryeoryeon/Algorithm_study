//
//  main.cpp
//  나이트의 이동
//
//  Created by 이영현 on 2021/03/07.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

/*
 // 사고의 흐름
 어쨌든 행렬에서 이동하는것과 같으니까 dx, dy를 쓰자
 
 첫 과제
 정점의 개수가 확실히 정해져있지 않다
 -> 그럼 방문체크 배열을 어떻게 만들어갈까?
 아하 체스판의 크기만큼 해도 되겠구나
 
 두번째 과제
 가장 최단단계를 어떻게, 코드의 어디서 비교시켜야할까?
 -> 단계수를 어디서 증가시켜야하는지 고민을 진짜 많이했었는데, 매번 반복문이 끝날 때마다 처음에 해주다가..
 생각해보면 큐에는 같은 단계에서 증가시켜준 정점들이 한번에 추가되는데, 그럼 다음 정점을 큐에서 꺼내고 반복문을 돌릴 때 이미 이전 정점에서
 합쳐준 단계수가 누적되어있으므로 큐에서 꺼내줄때마다 step을 다시 그 때 시점으로 초기화해줘야한다
 그러려면 구조체에 currentStep을 저장하여 주변을 조사할 때마다 이전에 대해 +1씩 해주는게 제일 깔끔하다는 판단이 들어 이렇게 풀었다
 
 만일 도착지에 도저히 도착하지 못하는 경우가 있으면 어떡하지?
 -> 그럴리는 없다. 결국 타고타고 가면 어떻게든 모든 체스판의 위치를 이동할 수 있기 때문에
 (즉, 체스판의 모든 칸은 그래프로 결국 이어져있다고 생각해도 될듯)
 
 // 0부터 입력을 받고있음에 주의
 -> 그러므로 ChessSize + 1로 초기화를 시켜주는 것이 아니라 0부터 데이터가 들어가니까 ChessSize로 초기화를 해줘야한다
 
 */

struct point
{
    int C;
    int R;
    int currentStep;
};

using namespace std;
vector<vector<int>> isChecked;
int chessSize;
int destR, destC;
int currentR, currentC;

int dC[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dR[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int BFS(point start)
{
    queue<point> q;
    q.push(start);
    isChecked[start.R][start.C] = 1;
    int minStep = 999999;
    
    while(!q.empty())
    {
        point idx = q.front();
        q.pop();
        
        // 시작점에 대해서도 조사되어야 하므로
        if(idx.R == destR && idx.C == destC)
        {
            if(idx.currentStep < minStep)
            {
                minStep = idx.currentStep;
            }
        }
        
        point next;
        next.currentStep = (idx.currentStep + 1);
        for(int i=0; i<8; ++i)
        {
            next.C = idx.C + dC[i];
            next.R = idx.R + dR[i];
            
            if(next.R >= chessSize || next.C >= chessSize || next.R <0 || next.C <0)
                continue;
            
            if(isChecked[next.R][next.C]) // 방문체크 써먹는거 제발 빼먹지말자
                continue;
            
            //++step;
            q.push(next);
            isChecked[next.R][next.C] = 1;
        }
        //++step;
    }
    
    return minStep;
}

int main(int argc, const char * argv[]) {
    
    int testNum;
    cin>>testNum;
    int minStep;
    
    for(int i=0; i<testNum; ++i)
    {
        cin>>chessSize;
        cin>>currentR>>currentC;
        cin>>destR>>destC;
        
        isChecked.assign(chessSize, vector<int>(chessSize, 0)); // 주의!
        minStep = BFS({currentC, currentR, 0}); // 중괄호 쳐주면 생성자 안 만들어줘도 OK
        cout<<minStep<<'\n';
    }
    
    return 0;
}
