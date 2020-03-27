//
//  main.cpp
//  Picnic
//
//  Created by 이영현 on 2020/02/03.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

//1초 내에 실행되어야 한다.

using namespace std;

void picnic(int *number, int index_j, const vector<vector<int>>& fri_graph, vector<int>& couples);

int main(int argc, const char * argv[]) {
    int C; // 테스트 케이스의 개수 (50 이하)
    cin>>C;
    
    for(int k=0; k<C; k++)
    {
        int n; // 학생의 수 (2에서 10 사이)
        int m; // 친구 쌍의 수 (0부터 n(n-1)/2 사이)
        
        cin>>n>>m;
        
        vector<int> friends;
        friends.assign(2 * m,0);
        
        // 모든 학생들이 친구들끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.
        // 사람이라면 어떻게 할까?
        // 몇 번 학생이 누구와 친구인지 생각해보고 하나하나 경우의 수를 짜지 않을까?
        // 둘이 서로 친구라면 1, 둘이 서로 친구가 아니라면 0
        // 학생수 * 학생수 만큼의 이중 배열을 만드는 건? (대응 행렬이 되겠다.)
        
        vector<vector<int>> fri_graph;
        fri_graph.assign(n, vector<int>(n, 0));
        
        for(int i=0; i<2*m; i++)
        {
            cin>>friends[i];
        }
        
        //모든 짝을 보여주는 대응 행렬 제작
        for(int i=0; i<2*m; i++)
        {
            fri_graph[friends[i]][friends[++i]] = 1;
            fri_graph[friends[i]][friends[--i]] = 1;
            
            ++i;
            
        }
        
        vector<int> couples;
        couples.assign(n, 0);
        int number = 0;
        
        picnic(&number, 0, fri_graph, couples);
        
        std::cout << number <<'\n';
        
    }

    return 0;
}

void picnic(int *number, int index_j, const vector<vector<int>>& fri_graph, vector<int>& couples)
{
    // n은 학생수, fri_graph는 짝을 보여주는 대응 행렬
    
    int n = (int)couples.size();

    for(int j=index_j; j<n; j++)
    {
        //j의 '짝'을 찾자!
        for(int k=j; k<n; k++)
        {
            //다 짝을 지으면 행렬의 원소를 0으로 바꿀까? ㄴㄴ 아냐
            //일차 행렬을 만들어서 얘 임자있어요를 시전하자. (0이면 임자 x, 1이면 임자 o)
            if(couples[k]==0 && fri_graph[j][k] == 1) // 으악 근데 이걸 재귀호출로 어떻게 하지..?
            {
                couples[j]=1 + k; // 자기 짝이 누군지 알게 하기 위해 디버깅!
                couples[k]=1 + j;
                picnic(number, ++j, fri_graph, couples); // 여기서 이어지는 경우는 모두 재귀함수로 구현하겠지.
                couples[j]=0;
                couples[k]=0; // 이제 재귀호출에서 해놓은 경우를 제외한 친구들을 부르기 위해!
            }
        }
    }
    
    if(index_j==n-1) //디버깅 해 봤는데 짝이 안 바뀐다 엉엉
        ++(*number);

}
