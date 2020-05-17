//
//  main.cpp
//  1012
//
//  Created by 이영현 on 2020/05/15.
//  Copyright © 2020 이영현. All rights reserved.
//

//All Pairs Shortest

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int node_num;
    cin>>node_num;
    
    vector<vector<int>> weight_list;
    weight_list.assign(node_num, vector<int>(node_num, 0));
    
    //가중치 입력 (연결되어 있지 않은 간선은 99999로 가중치 입력)
    for(int i=0; i<node_num; i++)
    {
        for(int j=0; j<node_num; j++)
            cin>>weight_list[i][j];
    }
    
    for(int k=0; k<node_num; k++)
    {
        for(int i=0; i<node_num; i++) // 단, i!=k
        {
            for(int j=0; j<node_num; j++) // 단, j!=k, j!=i
            {
                weight_list[i][j] = min(weight_list[i][k]+weight_list[k][j], weight_list[i][j]);
            }
        }
    }
    
    //최단거리 출력
    for(int i=0; i<node_num; i++)
    {
        for(int j=0; j<node_num; j++)
        {
            cout<<weight_list[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    
    
    return 0;
}
