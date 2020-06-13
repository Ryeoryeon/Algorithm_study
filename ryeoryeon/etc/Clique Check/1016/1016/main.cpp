//
//  main.cpp
//  1016
//
//  Created by 이영현 on 2020/06/13.
//  Copyright © 2020 이영현. All rights reserved.
//
// Clique problem
// n개의 노드로 구성된 그래프에서 크기가 k인 클리크가 존재하는지 확인하는 프로그램을 작성하시오.


/*
 
 [input]
 
 첫 번째 줄에는 n이 주어진다. (n <= 10)

 두 번째 줄부터 그래프의 간선(edge) 정보가 주어진다. 그래프들의 연결 정보는 n개의 줄의 2차원 배열 형태로 주어진다.
 (노드들이 연결되어있으면 1, 연결되어있지 않으면 0)

 마지막 줄에는 k가 주어진다.
 
 */

/*
 
 [output]
 
 주어진 그래프에서 크기 k의 클리크가 존재한다면 1을, 존재하지 않는다면 0을 출력하는 프로그램을 작성하시오.
 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> node_list; // 0과 1로 저장된 노드 사이의 관계들
vector<vector<int>> refine_list; // 정제된 관계들

int CURRENT_NODE = 0;
int CHECK_EXIST = 0; // k_size의 크기를 가지는 클리크가 있는지 저장하는 변수

void combination(int n,int r, vector<int>& selected)
{
    if (selected.size() == r)
    {
        for(int i=0; i<(selected.size() - 1); i++)
        {
            for(int j=i+1; j<selected.size(); j++)
            {
                //refine_list[CURRENT_NODE][selected[i]]와 refine_list[CURRENT_NODE][j] 와의 관계를 생각한다
                if(node_list[refine_list[CURRENT_NODE][selected[i]]][refine_list[CURRENT_NODE][selected[j]]]==0)
                {
                    return;
                }
            }
        }
        
        CHECK_EXIST = 1;
    }

    // 만일 selected 벡터가 비었다면 i에 0이 대입
    // 만일 selected 벡터가 비지 않았다면 i에 selected 벡터의 가장 뒷 원소 + 1번째가 대입
    // i(가장 뒷 원소)가 n이 되기 전까지 계속한다
    for (int i = selected.empty() ? 0 : selected.back() + 1; i < n; i++)
    {
        selected.push_back(i);
        combination(n, r,selected);
        selected.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    
    int n_size, k_size;
    cin>>n_size;
    
    node_list.assign(n_size, vector<int>(n_size, 0));
    
    refine_list.assign(n_size, vector<int>(11, -1)); // 11번째 원소[10]에는 각 행(노드 k)와 연결된 노드의 개수
    
    
    for(int j=0; j<n_size; j++)
    {
        for(int k=0; k<n_size; k++)
        {
            cin>>node_list[j][k];
        }
    }
    
    // 재구성 작업
    for(int j=0; j<n_size; j++)
    {
        int sum = 0;
        int temp_location = 1;
        
        for(int k=0; k<n_size; k++)
        {
            if(node_list[j][k] == 1)
            {
                refine_list[j][temp_location] = k;
                sum++;
                temp_location++;
            }
        }
        
        refine_list[j][0] = j;
        refine_list[j][10] = sum + 1; // 클리크의 크기는 sum + 1이 되어야 함 (자신의 노드까지 생각해야 하므로)
    }
    
    cin>>k_size;
    
    vector<int> selected;
    
    for(int i=0; i<n_size; i++)
    {
        //sum이 k_size보다 크거나 같다면 클리크를 만들 껀덕지가 생긴다!
        CURRENT_NODE = i;
        
        //k_size가 2이하면 무조건 존재한다.
        if(k_size<=2)
        {
            CHECK_EXIST = 1;
            break;
        }

        if(refine_list[i][10]>=k_size)
        {
            combination(refine_list[i][10], k_size, selected);
        }
        
        if(CHECK_EXIST == 1)
            break;
    }
    
    cout<<CHECK_EXIST;
    
    return 0;
}
