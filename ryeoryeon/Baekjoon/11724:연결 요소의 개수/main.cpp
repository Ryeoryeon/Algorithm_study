//
//  main.cpp
//  연결 요소의 개수
//
//  Created by 이영현 on 2021/03/06.
//  Copyright © 2021 이영현. All rights reserved.
//
// 23:59 시작

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> graph_list; // 그래프의 연결관계
vector<int> isChecked;

int DFS(int start){
    int size = graph_list[start].size();
    isChecked[start] = 1;
    
    for(int i=0; i<size; ++i)
    {
        if(!isChecked[graph_list[start][i]])
            DFS(graph_list[start][i]);
    }
    
    return 0;
}

int isCheckedOne()
{
    int returnVal = -1;
    int size = isChecked.size();
    
    for(int i=1; i<size; ++i) // 배열의 0번째는 버리는 수이므로 i=0부터 검사하면 절대 X
    {
        if(!isChecked[i])
        {
            returnVal = i;
            break;
        }
    }
    
    return returnVal;
}

int main(int argc, const char * argv[]) {
    int N, M;
    cin>>N>>M;
    graph_list.resize(N + 1);
    isChecked.assign(N + 1, 0);
    
    for(int i=0; i<M; ++i)
    {
        int temp1, temp2;
        cin>>temp1>>temp2;
        graph_list[temp1].push_back(temp2);
        graph_list[temp2].push_back(temp1);
    }
    
    for(int i=0; i<=N; ++i)
        sort(graph_list[i].begin(), graph_list[i].end());
    
    int component_num = 1;
    int nonCheckedVertex = 1;
    
    while(1)
    {
        DFS(nonCheckedVertex);
        nonCheckedVertex = isCheckedOne();
        if(nonCheckedVertex < 0)
            break;
        
        ++component_num;
    }
    
    cout<< component_num;
    return 0;
}


// 시행착오 필기

/*
 // 첫 번째 시련 (문제를 어떻게 풀어야할까?)
 우선 무방향 그래프인거에 주목해보자
 사람이 분리가 되는 그래프에 대해 생각할 때, 분리가 되는걸 어떻게 체크하지?
 1-2-5-1과 3-4-6-3이 있을 때 둘이 떨어져있는걸 알게 되는 계기는 둘 사이의 접점이 없다
 즉, start를 아무거나 하고 거기서 연결된 애들을 다 찾게 되면 이제 연결된 애들을 제외하고 남은 정점에 대해서 돌리는거지
 -> 남은 정점이 없을 때까지!
 
 그럼 BFS로 풀든 DFS로 풀든 상관 없는 문제같다 어차피 연결관계만 체크하면 되는거니까
 -> 재영이가 둘 다 풀라고 했으니까 둘 다 해봐야지..
 
 // 처음 생각했던 해결 방법
 vector<vector<int>> component_list; // 자기들끼리의 집합 [0]에는 컴포넌트 0의 정점들, [1]에는 컴포넌트 1의 정점들..
 1. 아무 시작점에서나 출발한다
 2. 해당 시작점에 대해 그래프 리스트 배열을 돌며 BFS/DFS를 돌린다
 3. 돌리면서 들리는 정점에 대해 cout을 하는게 아니라 component_list에 채워넣는다
 4. 다음 정점에 대해서도 돌리되 이전 component_list[이전 인덱스]에 이미 있으면 검사를 스킵한다
 -> 근데 꼭 component_list가 필요할까?
 
 // 진짜 해결 방법
 아!
 이건 모든 그래프가 이어져있는게 아니니까 BFS/DFS가 끝나도 isChecked의 모든 요소가 1이 되지 않을 것
 1이 되지 않은 요소들에 대해 BFS/DFS 재진행
*/

/*
// 두 번째 시련 (연결 요소의 개수에 대해서)
// 일단 처음에는 무조건 아무 정점으로나 실행해야함
// 그리고 돌리고 나서 계속 isChecked배열이 모두 1인지 검사해야함
// -> 그럼 따로 검사하는 함수를 만들까?

// 그리고 더 심플하게 출력할 수 있는 코드
component_num = 0;
for(int i=1; i<=N; ++i)
{
    if(!isChecked[i])
    {
        DFS(i);
        ++component_num;
    }
}
-> DFS자체를 포문에 넣어버리면 되는거였다! 앞으로 아이디어를 잘 이용해보자
*/
