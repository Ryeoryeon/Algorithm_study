//
//  main.cpp
//  1920 / 수 찾기
//
//  Created by 이영현 on 2021/03/30.
//  Copyright © 2021 이영현. All rights reserved.
//

/*
 // 사고의 흐름
 2^31 == 걍 int형이라는 얘기임
 만약 브루트포스를 하게 되면 N * M -> 최대 10^10이 되니까 시간초과가 된다! (펑)
 
 // 과연 for문을 저거만큼만 했다고 끝일까?
 
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    arr.assign(N, 0);
    for(int i=0; i<N; ++i)
        cin>>arr[i];
    
    // 이분 탐색은 정렬된 상태에서 써야한다
    sort(arr.begin(), arr.end());
    
    cin>>M;
    // 존재하면 1, 존재하지 않으면 0 출력
    int key, left, right, mid;
    for(int i=0; i<M; ++i)
    {
        cin>>key;
        right = N-1;
        left = 0;
        bool ans = false;

        for(int j=N; j>=1; j/=2)
        {
            mid = (left + right) / 2;
            
            if(arr[mid] == key)
            {
                ans = true;
                break;
            }
                
            else if (arr[mid] > key)
            {
                right = mid - 1;
                continue;
            }
            
            else if (arr[mid] < key)
            {
                left = mid + 1;
                continue;
            }
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}
