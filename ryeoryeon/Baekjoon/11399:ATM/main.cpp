//
//  main.cpp
//  11399 / ATM
//
//  Created by 이영현 on 2021/03/07.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 사고의 흐름
 
 그리디 - 테스트 케이스에 답이 있는 것 같다
 가장 최소 시간 걸리는 사람부터 먼저 하게 하기
 
 브루트 포스 - (?) // 안됨. 전체 순열의 가짓수를 전부 따져야하는데 그러면 O(N!)이 되어 시간초과
 */

int main(int argc, const char * argv[]) {
    int N, accumTime = 0; // 사람의 수
    cin>>N;
    vector<int> N_list;
    N_list.assign(N, 0);
    
    for(int i=0; i<N; ++i)
        cin>>N_list[i];
    
    // 0번째 사람은 지것만, 1번째 사람은 0+1, 2번째 사람은 0+1+2
    int totalTime = 0;
    sort(N_list.begin(), N_list.end());
    
    for(int i=0; i<N; ++i)
    {
        accumTime += N_list[i];
        totalTime += accumTime;
    }
    
    cout<<totalTime;
    
    return 0;
}
