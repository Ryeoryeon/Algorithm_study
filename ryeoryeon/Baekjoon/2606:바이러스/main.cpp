//
//  main.cpp
//  바이러스
//
//  Created by 이영현 on 2021/03/07.
//  Copyright © 2021 이영현. All rights reserved.
//
// 01:24 시작

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> graph_list;
vector<int> isChecked;
int virusCom = 0;

// 생각의 흐름
/*
 단방향(양방향)그래프 문제같다
 이거 그냥 1번 컴퓨터에 연결된 애들의 개수를 모두 구하면 될 것 같은데? -> 아님
 왜냐하면 깊이 파고들어가서 걸리는 애들도 있기 때문이다
 1번과 직접적이 아니어도 결국 연결되어있는 컴퓨터의 개수를 모두 조사해야한다
 */

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    isChecked[start] = 1;
    
    int index;
    while(!q.empty())
    {
        index = q.front();
        q.pop();
        int size = graph_list[index].size();
        
        for(int i=0; i<size; ++i)
        {
            if(!isChecked[graph_list[index][i]])
            {
                q.push(graph_list[index][i]);
                isChecked[graph_list[index][i]] = 1;
                ++virusCom;
            }
        }
    }
    
    return ;
}

int main(int argc, const char * argv[]){
    int comNum, relationNum;
    cin>>comNum>>relationNum;
    graph_list.resize(comNum + 1);
    isChecked.assign(comNum + 1, 0);
    
    for(int i=0; i<relationNum; ++i)
    {
        int temp1, temp2;
        cin>>temp1>>temp2;
        graph_list[temp1].push_back(temp2);
        graph_list[temp2].push_back(temp1);
    }
    
    BFS(1);
    cout<<virusCom;
    
    return 0;
}
