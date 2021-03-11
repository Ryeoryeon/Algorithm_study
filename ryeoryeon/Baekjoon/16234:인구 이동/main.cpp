//
//  main.cpp
//  16234 / 인구 이동
//
//  Created by 이영현 on 2021/03/11.
//  Copyright © 2021 이영현. All rights reserved.
//
// 22:00

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L, R; // N^2 == 나라의 수, 인구차이 하한과 상한
vector<vector<int>> A; // A[r][c]에는 r행 c열의 나라의 국민수가 있음
vector<vector<int>> isChecked;

int realMove = 0;
bool willMove = true;
//int relationNum = 0; // 연합 수
//int relationPeople = 0; // 연합의 인구 수

int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};

struct point
{
    int R;
    int C;
};

void BFS(point start)
{
    int relationNum = 0; // 연합 국가의 수
    int relationPeople = 0; // 연합의 인구 수
    
    isChecked[start.R][start.C] = 1;
    queue<point> q;
    queue<point> afterQ; // 큐에 넣어놓고 나중에 인구 수 계산
    q.push(start);
    afterQ.push(start);
    
    while(!q.empty())
    {
        point idx = q.front();
        ++relationNum;
        relationPeople += A[idx.R][idx.C];
        q.pop();
        point next;
        for(int i=0; i<4; ++i)
        {
            next.R = idx.R + dR[i];
            next.C = idx.C + dC[i];
            if(next.R>=0 && next.R<N && next.C>=0 && next.C<N)
            {
                // 방문체크 확인
                int temp = abs(A[next.R][next.C] - A[idx.R][idx.C]);
                bool isRelated = (temp >= L && temp <= R) ? true : false;
                if(isRelated && !isChecked[next.R][next.C])
                {
                    isChecked[next.R][next.C] = 1;
                    q.push(next);
                    afterQ.push(next);
                }
            }
        }
    }
    
    while(!afterQ.empty())
    {
        if(afterQ.size() != 1) // 1일 경우 국경이 열리지 않은 경우와 다름없음
            willMove = true; // 인구이동이 되었으므로 반복문이 한 번 더 돌아가야할 '껀덕지'가 생김
        
        point idx = afterQ.front();
        A[idx.R][idx.C] = relationPeople / relationNum;
        afterQ.pop();
    }
}

int main(int argc, const char * argv[]) {
    cin>>N>>L>>R;
    A.assign(N, vector<int>(N, 0));
    isChecked.assign(N, vector<int>(N, 0));
    
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
            cin>>A[i][j];
    }
    
    while(willMove)
    {
        willMove = false;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(!isChecked[i][j]) // 이미 같은 하루에 처리된 국경은 손대지 않는다
                {
                    BFS({i, j});
                    //willMove = true;
                }
            }
        }
        
        if(willMove) // 인구이동이 일어나지 않은 마지막 하루의 경우에 대해서 제외해주기 위해
            ++realMove; // 같은 하루에 처리된 여러 개의 국경에 대한 인구이동은 한 번으로 처리해야한다 (!!!)
        isChecked.assign(N, vector<int>(N, 0));
    }
    
    cout<<realMove;
    
    return 0;
}
