//
//  main.cpp
//  Closest_pair
//
//  Created by 이영현 on 2020/04/18.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct dots
{
    int x;
    int y;
};

double find_distance(int first, int last);
double distance(dots d1, dots d2);

bool compare(const dots &d1, const dots &d2)
{
    if (d1.x < d2.x) return true;
    
    else if (d1.x == d2.x) return d1.y < d2.y;
    
    return false;
}

dots * dots_list;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int dots_num;
    cin>>dots_num;
    char comma;
    
    dots_list = (dots*)malloc(sizeof(dots)*dots_num);
    
    for(int i=0; i<dots_num; i++)
    {
        cin>>dots_list[i].x>>comma>>dots_list[i].y;
    }
    
    sort(dots_list, dots_list + dots_num, compare);
    
    cout<<fixed;
    cout.precision(6);
    cout<<find_distance(0, dots_num - 1);
    
    free(dots_list);
    
    return 0;
}

double find_distance(int first, int last)
{
    double min_dist = 0;
    int mid = (first+last)/2;
    
    // 재귀 종료 조건
    // (왼쪽 부분에) 남아있는 점의 개수가 3개 이하이면 더 이상 분할하지 말라고 하셨다.
        // 2개면 그대로 그 친구들을 리턴하고, 아니라면 3개에 대해서 연산 진행.
    if(last-first <= 2)
    {
        if(last - first == 1)
        {
            return distance(dots_list[first], dots_list[last]);
        }

        min_dist = min(distance(dots_list[first], dots_list[last - 1]), distance(dots_list[first], dots_list[last]));
        min_dist = min(min_dist, distance(dots_list[first+1], dots_list[last]));
        
        return min_dist;
    }
    
    double dist_L, dist_R, dist_mid;
    
    dist_L = find_distance(first, mid); // 왼쪽
    dist_R = find_distance(mid + 1, last); // 오른쪽
    
    // 가운데는 dist_L과 dist_R보다 더 작은 값을 가진 애가 x간 간격이 된다. 중심 플마 간격으로!
    // 가운데 영역은 재귀를 안 써도 되지 않을까?
    
    //dist_L과 dist_R이 같을 때 예외처리를 오 ㅐ 안 해줬어!!!!!!!!
    if(dist_L >= dist_R)
    {
        // 중간 영역의 조사 간격은 dist_R이 된다. 이제 조사할 구간인 왼쪽과 오른쪽 인덱스를 찾아보자.
        
        // @@@@@@@@@@ 구간 벗어나는 거 예외처리 해 줘야 하나?
        int left_index = mid;
        int right_index = mid + 1;
        
        // 처음부터 글렀으면 애초에 반복문 자체를 돌릴 필요가 음슴.
        if((abs(dots_list[left_index].x - dots_list[right_index].x)) > dist_R)
            return dist_R;
        
        // 왼쪽 인덱스 찾기
        while(left_index > first)
        {
            --left_index;
            if(abs(dots_list[left_index].x - dots_list[mid].x) > dist_R) // (0419) 원래 등호를 붙였는데 등호 지웠다.
            {
                ++left_index; // 이미 빼진 상태로 비교됐으나 탈락된 거기 때문에 그 전 인덱스로 되돌려야 한다.
                break;
            }
        }
        
        while(right_index < last)
        {
            ++right_index;
            if(abs(dots_list[right_index].x - dots_list[mid + 1].x) > dist_R)
            {
                --right_index; // 이미 더해진 상태로 비교됐으나 탈락된 거기 때문에 그 전 인덱스로 되돌려야 한다.
                break;
            }
        }
        
        //[dist_mid 찾기]
        dist_mid = dist_R;
        
        for(int j=left_index; j<right_index; j++)
        {
            for(int k=j+1; k<=right_index; k++)
            {
                double temp = distance(dots_list[j], dots_list[k]);
                
                if(temp < dist_mid)
                    dist_mid = temp;
            }
        }
        
        min_dist = dist_mid;
        
    }
    
    else
    {
        // 중간 영역의 조사 간격은 dist_L이 된다. 이제 조사할 구간인 왼쪽과 오른쪽 인덱스를 찾아보자.
    
        // @@@@@@@@@@ 구간 벗어나는 거 예외처리 해 줘야 하나?
        int left_index = mid;
        int right_index = mid + 1;
        
        // 처음부터 글렀으면 애초에 반복문 자체를 돌릴 필요가 음슴.
        if((abs(dots_list[left_index].x - dots_list[right_index].x)) > dist_L)
            return dist_L;
        
        // 왼쪽 인덱스 찾기
        while(left_index > first)
        {
            --left_index;
            if(abs(dots_list[left_index].x - dots_list[mid].x) > dist_L)
            {
                ++left_index; // 이미 빼진 상태로 비교됐으나 탈락된 거기 때문에 그 전 인덱스로 되돌려야 한다.
                break;
            }
            
        }
        
        // 오른쪽 인덱스 찾기
        while(right_index < last)
        {
            ++right_index;
            if(abs(dots_list[right_index].x - dots_list[mid + 1].x) > dist_L)
            {
                --right_index; // 이미 더해진 상태로 비교됐으나 탈락된 거기 때문에 그 전 인덱스로 되돌려야 한다.
                break;
            }
        }
        
        //[dist_mid 찾기]
        dist_mid = dist_L;
        
        for(int j=left_index; j<right_index; j++)
        {
            for(int k=j + 1; k<=right_index; k++)
            {
                double temp = distance(dots_list[j], dots_list[k]);
                
                if(temp < dist_mid)
                    dist_mid = temp;
            }
        }
    
        min_dist = dist_mid;
        
    }
    
    
    return min_dist;
    
}

double distance(dots d1, dots d2)
{
    return sqrt(pow((d1.x - d2.x),2)+pow((d1.y - d2.y),2));
}
