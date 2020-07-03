//
//  main.cpp
//  1017
//
//  Created by 이영현 on 2020/07/03.
//  Copyright © 2020 이영현. All rights reserved.
//

/*
 
 <Approximate Clustering>
 
 2차원 평면상의 n개의 점이 주어졌을 때,
 이 점들을 approximate_clustering 알고리즘을 이용하여 k개의 클러스터(cluster)에 배정하고,
 각 클러스터들의 센터 점을 출력하는 프로그램을 작성하시오.

 (단, 복수 정답을 피하기 위해 approximate_clustering 알고리즘 수행 시, 첫 번째 클러스터는 0번째 데이터가 사용되도록 한다.)

 <Input>
 
 첫 번째 줄에는 데이터의 수 n와 클러스터의 개수 k가 주어진다. (n <= 10000, k <= 10)
 두 번째 줄부터 n개의 줄에 걸쳐, 각 2차원 데이터들의 x, y좌표(정수)가 주어진다.
 
 <Output>
 
 k개의 줄에 각 클러스터의 센터 데이터의 x, y좌표를 출력한다.
 단, 클러스터 센터의 출력 순서는 입력 데이터의 인덱스가 작은 순서대로 출력한다.
 
 */

#include <iostream>
#include <cmath> // abs
#include <vector>
#include <algorithm> // sort

using namespace std;

struct dots
{
    int x;
    int y;
    int index;
};

//혹시 필요할까 가져온 예전 비교 코드
bool compare(const dots &d1, const dots &d2)
{
    if(d1.x < d2.x) return true;
    
    else if (d1.x == d2.x) return d1.y < d2.y;
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dots* dots_list;
    
    int dots_num, cluster_num; // 각각 n, k를 의미함
    cin>>dots_num>>cluster_num;
    
    dots_list = (dots*)malloc(sizeof(dots)*dots_num);
    
    // 입력
    for(int k=0; k<dots_num; k++)
    {
        cin>>dots_list[k].x>>dots_list[k].y;
        dots_list[k].index = k;
    }
    
    // 클러스터 구분!
    /*
     
     만일 k=1이면 자동으로 0번째 점이 센터가 되고 끝남.
     k=2이면 0번째 점과 가장 거리가 먼 점이 센터가 된다.
     k=3 이상일 때는 센터들과의 거리 중 가장 짧은 값이 가장 긴 점이 센터가 된다!
     
     일단 해보자..
     
     */
    
    // 일단 맨하탄 거리로 거리를 구하고 만일 안되면 유클리드 방법으로 바꾸자
    // 맨하탄 안된다. 유클리드로 하자..ㅠㅠ
    
    vector<int> center_index;
    center_index.push_back(0); // 센터 점들의 인덱스를 저장
    
    for(int k=1; k<cluster_num; k++)
    {
        if(k==1) // k==1이라는건 결국 두번째 클러스터일때
        {
            int distance_max = 0;
            int temp_center = 0;
            
            for(int i=1; i<dots_num; i++) // i==0은 무조건 센터의 인덱스이기 때문에
            {
                int euclidean_distance = 0;
                int temp = 0;
                
                temp += pow((dots_list[0].x - dots_list[i].x), 2);
                temp += pow((dots_list[0].y - dots_list[i].y), 2);
                
                euclidean_distance = sqrt(temp);
                
                if(distance_max < euclidean_distance)
                {
                    temp_center = i;
                    
                    distance_max = euclidean_distance;
                }
                
            }
            
            center_index.push_back(temp_center); // [1]
        }
        
        else
        {
            // i점에 대해, 센터들간의 거리 중 가장 짧은 값에 대해 가장 긴 값을 가지고 있는 i가 센터로 채택됨!
            
            int distance_max = 0;
            int temp_center;
            
            for(int i=1; i<dots_num; i++) // i==0은 무조건 센터의 인덱스이기 때문에
            {
                
                bool isCenter = false;
                
                // i가 이미 센터의 점인지 조사하기
                for(int center = 0; center<center_index.size(); center++)
                {
                    if(i==center_index[center])
                    {
                        isCenter = true;
                        break;
                    }
                }
                
                if(!isCenter)
                {
                    int temp_distance_min = 999999999; // INF (9억 9천만..)
                    
                    // i점에 대해, 클러스터 센터들간의 거리 중 최솟값 조사
                    for(int u=0; u<k; u++) // k==2일때는 클러스터 개수 3, (0,1과 비교해야 한다. 그러므로 등호 x)
                    {
                        
                        int temp = 0;
                        
                        temp += pow((dots_list[center_index[u]].x - dots_list[i].x), 2);
                        temp += pow((dots_list[center_index[u]].y - dots_list[i].y), 2);
                        
                        temp = sqrt(temp);
                        
                        // 클러스터 센터들간의 거리 중 최솟값으로 저장
                        if(temp < temp_distance_min)
                            temp_distance_min = temp;
                        
                    }
                    
                    if(temp_distance_min > distance_max)
                    {
                        distance_max = temp_distance_min;
                        temp_center = i;
                    }
                }
                
            }
            
            center_index.push_back(temp_center);
            
        }
            
    }
    
    // 입력 데이터에서 인덱스가 작은 순으로 출력되도록 정렬해야 한다
    sort(center_index.begin(), center_index.end());
    
    for(int i=0; i<center_index.size(); i++)
    {
        //cout<<center_index[i].x<<' '<<center_index[i].y;
        cout<<dots_list[center_index[i]].x<<' '<<dots_list[center_index[i]].y;
        
        if(i!=(center_index.size() - 1))
            cout<<'\n';
    }
    
    return 0;
}
