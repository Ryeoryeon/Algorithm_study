//
//  main.cpp
//  2458 / 키 순서
//
//  Created by 이영현 on 2021/05/06.
//  Copyright © 2021 이영현. All rights reserved.
//

// am 08:45 시작!

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> connectedNumList;
vector<int> checkList;
vector<vector<int>> connectedList; // 이중 벡터 선언 주의
int N, M;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    checkList.assign(N + 1, 0);
    
    //int connectedNum = 0;
    while(!q.empty())
    {
        //++connectedNum;
        int idx = q.front();
        q.pop();
        int size = connectedList[idx].size();
        for(int i=0; i<size; ++i)
        {
            int tempIdx = connectedList[idx][i];
            if(!checkList[tempIdx])
            {
                q.push(tempIdx);
                checkList[tempIdx] = 1;
                ++connectedNumList[tempIdx];
                ++connectedNumList[start];
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    cin>>N>>M; // 학생수와 학생 키 비교한 횟수
    connectedList.resize(N + 1); // 연결 리스트는 resize로 선언 후 push_back
    connectedNumList.assign(N + 1, 0);
    //checkList.assign(N + 1, 0);
    
    int shortStudent, longStudent;
    for(int i=0; i<M; ++i)
    {
        cin>>shortStudent>>longStudent;
        connectedList[shortStudent].push_back(longStudent);
    }
    
    for(int i=1; i<=N; ++i)
        BFS(i);
    
    int studentNum = 0;
    for(int i=1; i<=N; ++i)
    {
        if(connectedNumList[i] == N - 1)
            ++studentNum;
    }
    
    cout<<studentNum;
    
    return 0;
}
