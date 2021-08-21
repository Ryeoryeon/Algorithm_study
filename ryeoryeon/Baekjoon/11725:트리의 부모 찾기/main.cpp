//
//  main.cpp
//  트리의 부모 찾기
//
//  Created by 이영현 on 2021/08/21.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int N; // 노드의 개수
vector<vector<int>> tree;
int treeHeight[1000001] = {0,};
bool isChecked[100001] = {0,};

void DFS(int currentNode, int height)
{
    treeHeight[currentNode] = height;
    int size = tree[currentNode].size();
    for(int i = 0; i < size; ++i)
    {
        if(!isChecked[tree[currentNode][i]]) // 방문 체크 안됐을 때
        {
            isChecked[tree[currentNode][i]] = 1;
            DFS(tree[currentNode][i], height + 1);
        }
    }
    return ;
}

int main(int argc, const char * argv[]) {
    cin>>N;
    tree.resize(N + 1); // 1 ~ N번 인덱스 사용
    int temp1, temp2;
    for(int i = 0; i < (N - 1); ++i)
    {
        cin>>temp1>>temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }
    
    isChecked[1] = 1; // 첫 번째 노드 방문체크는 미리 진행
    DFS(1, 0);
    for(int i = 2; i < N + 1; ++i)
    {
        for(int j = 0; j < tree[i].size(); ++j) // 연결된 노드들을 돌며, 자신보다 위치가 -1인 노드(부모 노드)를 출력
        {
            int connectNode = tree[i][j];
            if(treeHeight[connectNode] == (treeHeight[i] - 1))
                cout<<connectNode<<'\n';
        }
    }
    
    return 0;
}
