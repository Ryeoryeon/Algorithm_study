//
//  main.cpp
//  섬의 개수
//
//  Created by 이영현 on 2021/02/26.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct location
{
    int row;
    int col;
    
    location(int row, int col)
    {
        this -> row = row;
        this -> col = col;
    }
    
};

vector<vector<int>> land_map;
vector<vector<int>> landChecked;
int rows, cols;

queue<location> q;

void BFS(location l1)
{
    // 조사하고자 하는 첫 노드 push
    q.push(location(l1.row, l1.col));
    
    int nodeR, nodeC;
    
    while(!(q.empty()))
    {
        nodeR = q.front().row;
        nodeC = q.front().col;
        
        q.pop();
        
        // 인접 노드 조사
        for(int i=0; i<8; ++i)
        {
            int currentR = nodeR - dr[i];
            int currentC = nodeC - dc[i];
            
            // 이동해도 범위 안인지 조사
            if(currentR >=0 && currentC >=0 && currentR < rows && currentC < cols)
            {
                // 방문하지 않은 인접 노드가 있는지 조사
                if(land_map[currentR][currentC] && !(landChecked[currentR][currentC]))
                {
                    landChecked[currentR][currentC] = 1;
                    q.push(location(currentR, currentC));
                }
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin>>cols>>rows; // w와 h
    if(cols==0 && rows==0)
        return 0;
    
    else
    {
        while(cols!=0 && rows!=0)
        {
            int islandNum = 0;
            land_map.assign(rows, vector<int>(cols, 0));
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                    cin>>land_map[i][j];
            }
            landChecked.assign(rows, vector<int>(cols, 0));
            
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    if(land_map[i][j] && (!landChecked[i][j]))
                    {
                        BFS(location(i, j));
                        ++islandNum;
                    }
                }
            }
            
            cout<<islandNum<<'\n';
            cin>>cols>>rows;
        }
    }
    return 0;
}
