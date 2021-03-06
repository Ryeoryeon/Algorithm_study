//
//  main.cpp
//  재영이의 과외2
//
//  Created by 이영현 on 2021/03/06.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> isChecked;
queue<int> q;

int DFS(int start)
{
    int size = adj[start].size();
    isChecked[start] = 1;
    cout<<start<<' ';
    
    for(int i=0; i<size; ++i)
    {
        if(!isChecked[adj[start][i]])
        {
            // return DFS(adj[start][i]); // 재귀는 리턴을 하면 끝난다. (이렇게하면 회수가 안됨)
            DFS(adj[start][i]);
        }
        
        else
            continue;
    }
    
    return 0;
}

int BFS(int start)
{
    q.push(start);
    isChecked[start] = 1;
    
    int index = start;
    while(!q.empty())
    {
        cout<<q.front()<<' ';
        q.pop();
        int size = adj[index].size();
        for(int i = 0; i<size; ++i)
        {
            if(!isChecked[adj[index][i]])
            {
                q.push(adj[index][i]);
                isChecked[adj[index][i]] = 1;
            }
        }
        
        index = q.front(); // 다음 정점으로 인덱스 변경
    }
    
    return 0;
}

/*
 // 내가 처음에 잘못 짰던 무한반복 BFS 코드
 // 체크 배열을 써먹어야지..
 
 int BFS(int start)
 {
     q.push(start);
     isChecked[start] = 1;
     
     int index = start;
     while(!q.empty())
     {
         cout<<q.front()<<' ';
         q.pop();
         int size = adj[index].size();
         for(int i = 0; i<size; ++i)
         {
             q.push(adj[index][i]);
             isChecked[adj[index][i]] = 1;
         }
         
         index = q.front(); // 다음 정점으로 인덱스 변경
     }
     
     return 0;
 }
 */

int main(int argc, const char * argv[]) {
    int N, M, start; // 정점의 개수와 연결 관계의 수 그리고 시작점
    cin>>N>>M>>start;
    adj.resize(N + 1);
    isChecked.assign(N + 1, 0);
    
    for(int i=0; i<M; ++i)
    {
        int temp1, temp2;
        cin>>temp1>>temp2;
        
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    
    // 정점이 작은 번호부터 방문해야 하므로 sort함수 필수
    // resize(N+1)이므로 반복문 인덱싱에 주의
    for(int i=0; i<=N; ++i)
        sort(adj[i].begin(), adj[i].end());
    
    DFS(start);
    cout<<'\n';
    isChecked.assign(N + 1, 0); // 체크배열 초기화 꼭 필요!!!!!!!!!!
    BFS(start);
    cout<<'\n';
    
    return 0;
}
