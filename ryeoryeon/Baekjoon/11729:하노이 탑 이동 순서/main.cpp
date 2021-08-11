//
//  main.cpp
//  하노이 탑 이동 순서
//
//  Created by 이영현 on 2021/08/12.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int N, K = 0; // 원판의 개수와 옮긴 횟수
vector<pair<int, int>> moving;

void hanoi(int start, int mid, int destination, int currentNum)
{
    if(currentNum == 0)
        return ;
    
    ++K;
    // n-1개를 경유 지점으로 옮긴다
    hanoi(start, destination, mid, currentNum - 1);
    // 가장 큰 원판을 마지막 지점으로 옮긴다
    moving.push_back({start, destination});
    // 경유 지점에 있는 n-1개를 마지막 지점으로 마저 옮긴다
    hanoi(mid, start, destination, currentNum - 1); // 나머지 한 지점은 자동으로 경유 지점이 된다
}

int main(int argc, const char * argv[]) {
    cin>>N;
    hanoi(1, 2, 3, N);
    
    cout<<K<<'\n';
    for(int i = 0; i < moving.size(); ++i)
        cout<<moving[i].first<<' '<<moving[i].second<<'\n';
    return 0;
}
