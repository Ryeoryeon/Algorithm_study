//
//  main.cpp
//  2667 / 단지번호붙이기
//
//  Created by 이영현 on 2021/03/10.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct point{
    int R;
    int C;
};

int N;
vector<vector<int>> apartMap;
vector<vector<int>> isChecked;
vector<int> apartNumList; // [단지]에 저장되는 건 아파트의 수

int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};

void DFS(point start, int apartComplex)
{
    isChecked[start.R][start.C] = 1;
    ++apartNumList[apartComplex];
    
    for(int i=0; i<4; ++i)
    {
        point next = {start.R + dR[i], start.C + dC[i]};
        
        // 유효한 위치인지 검사하기
        if(next.R >= 0 && next.R < N && next.C >= 0 && next.C < N)
        {
            // 방문체크 배열에 있는지 검사하고, 아파트인지 검사하기
            if(apartMap[next.R][next.C] && !isChecked[next.R][next.C])
            {
                //isChecked[next.R][next.C] = 1;
                DFS({next.R, next.C}, apartComplex);
            }
        }
    }
    
    return ;
}


int main(int argc, const char * argv[]) {
    int apartComplex = 0;
    cin>>N; // 단지의 크기
    apartMap.assign(N, vector<int>(N, 0));
    isChecked.assign(N, vector<int>(N, 0));
    
    string temp;
    for(int i=0; i<N; ++i)
    {
        cin>>temp;
        for(int j=0; j<N; ++j)
            apartMap[i][j] = (temp[j] - '0'); // int 변환 잊지말기!
    }
    
    // map에서 1인 지점(아파트)에 대해서 DFS를 진행한다
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(apartMap[i][j] && !isChecked[i][j])
            {
                apartNumList.push_back(0);
                DFS({i, j}, apartComplex); // i는 행, j는 열
                ++apartComplex;
            }
        }
    }
    
    cout<<apartComplex<<'\n';
    sort(apartNumList.begin(), apartNumList.end());
    
    for(int i=0; i<apartComplex; ++i)
        cout<<apartNumList[i]<<'\n';
    
    return 0;
}

/*
// 사고의 흐름
이게 왜 그래프일까..
그런데 저번에 풀었던 섬의 개수와 문제가 비슷해보인다?
일단 물 떠놓고 다시 풀어보자

왜 이게 그래프일까..
사실상 연결관계가 명시적으로 주어져있지 않은 그래프 아닐까?
그러므로 연결관계를 찾기 위해 탐색이 필요한 것 같다.
ㄴ 시작 위치(1이 있는 애 중 아무거나 선택)를 기준으로 해서 0이 나타나면 탐색 종료!
ㄴ 하는식으로 자기들끼리의 단지를 찾아나가면 될 것 같은데..
ㄴ 구체적으로 어떻게..? 먼가 체크 배열을 아주 잘 쓰면 될 것 같은데..
아 잠깐 굳이 필요없겠다
그냥 단지에 포함된 애들 수만 출력하면 되잖아??
그럼 DFS를 쓰든 BFS를 쓰든 노상관이겠네
*/
