//
//  main.cpp
//  1389 / 케빈베이컨
//
//  Created by 이영현 on 2021/02/26.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M; // 유저의 수와 친구 관계의 수

struct kebin
{
    int idx; // idx번째 사람
    int kebinStep;
};

vector<vector<int>> friendList;
vector<int> isChecked;
int kebinMin = 1e9;
int kebinIdx;

void BFS(int start)
{
    int kebinNum = 0;
    
    queue<kebin> q;
    q.push({start, 1});
    isChecked[start] = 1;
    
    while(!q.empty())
    {
        kebin idx = q.front();
        q.pop();
        //++step;
        
        // 인접 리스트 검사와 방문체크 배열 검사
        int size = friendList[idx.idx].size();
        for(int i=0; i<size; ++i)
        {
            int temp = friendList[idx.idx][i];
            if(!isChecked[temp])
            {
                q.push({temp, idx.kebinStep + 1});
                isChecked[temp] = 1;
                kebinNum += idx.kebinStep;
            }
        }
    }
    
    if(kebinNum < kebinMin)
    {
        kebinMin = kebinNum;
        kebinIdx = start;
    }
}

int main()
{
    cin>>N>>M;
    friendList.resize(N + 1); // 사람의 번호는 1부터 N까지이므로
    isChecked.assign(N + 1, 0);
    
    int temp1, temp2;
    for(int i=0; i<M; ++i)
    {
        cin>>temp1>>temp2;
        friendList[temp1].push_back(temp2);
        friendList[temp2].push_back(temp1);
    }
    
    // 케빈의 수가 같으면 더 작은 번호의 사람이 출력되어야 한다는 것에 유의
    for(int i=1; i<=N; ++i)
    {
        BFS(i);
        isChecked.assign(N + 1, 0);
    }
    
    cout<<kebinIdx;
    
    return 0;
}

/*
// 사고의 흐름
이건 단방향 그래프일까 양방향 그래프일까? -> 당연히 양방향이겠지.. 친구가 단방향이면 좀 슬프지않을까..?
친구 관계 저장은 인접 리스트를 써보자~

케빈이라는 벡터를 만들어서 각 인덱스에 각 사람이 해당하는 케빈의 수를 저장하기로 했다
단, 이 문제의 특성상 출발점이 바뀌면 다시 탐색해야하므로- -> isChecked는 이 문제에서 함수가 진행되는 처음부분에서 계속 초기화해줘야함
ㄴ 그런데 걍 최소의 수만 출력하면 되니까 걍 매번 BFS마다 케빈의 수 비교해주면 될 것 같다
ㄴ 그리고 더 작은 인덱스의 사람이 출력되어야하는건 for문에서 오름차순으로 해주면 될듯

그리고 최소단계의 수를 탐색해야하므로 BFS를 써야할 것 같다

// 시행착오
1. isChecked[idx] = 1; // idx에 제발 start로 잘못쓰지말자 ^^..
2. 왜 isChecked 초기화 해줘야한다고 써놨으면서 써먹질 않니..
3. step에 대해서 조사해야하는데 이거를 함수 내에서 증가시켜서 하려고 똥꼬쑈 하다가
4. 걍 이게 결국 큐에 추가하는 시점에서 추가되는것도 아니고 큐에서 빼야하는 시점에서 추가되어야하는것도 아니고
5. 아 존나설명뭐라고써야하냐
6. 예를들어 1 > (3, 4 :: 1단계) > (2, 5 :: 2단계) 여야하는데 각 단계를 저장하려면 사실 구조체나 따로 벡터 두는게 제일 편하다
7. 근데 왜 편한지 논리적으로 설명을 못하겠네 흠
*/
