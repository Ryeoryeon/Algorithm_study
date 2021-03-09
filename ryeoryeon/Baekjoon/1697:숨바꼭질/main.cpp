//
//  main.cpp
//  1697 / 숨바꼭질
//
//  Created by 이영현 on 2021/03/09.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> isChecked;

struct locationNtime
{
    int location;
    int time;
};

int N, K; // 수빈이와 동생의 현재위치

int BFS(int start)
{
    queue<locationNtime> q;
    q.push({N, 0});
    isChecked[N] = 1; // 위치가 0이 될수도 있음에 주의
    int minTime = 999999;
    
    locationNtime idx;
    while(!q.empty())
    {
        idx = q.front();
        q.pop();
        
        if(idx.location == K)
        {
            if(idx.time < minTime)
                minTime = idx.time;
        }
        
        if((idx.location - 1) >= 0 && !isChecked[idx.location - 1])
        {
            q.push({idx.location - 1, idx.time + 1});
            isChecked[idx.location - 1] = 1;
        }
        
        if((idx.location + 1) <= 100000 && !isChecked[idx.location + 1])
        {
            q.push({idx.location + 1, idx.time + 1});
            isChecked[idx.location + 1] = 1;
        }
        
        if((idx.location * 2) <= 100000 && !isChecked[(idx.location * 2)])
        {
            q.push({idx.location * 2, idx.time + 1});
            isChecked[idx.location * 2] = 1;
        }
    }
    
    return minTime;
}

int main(int argc, const char * argv[]) {
    cin>>N>>K;
    int minTime;
    isChecked.assign(100001, 0);
    minTime = BFS(N);
    cout<<minTime;
    
    return 0;
}

/*
// 사고의 흐름
수빈이 순간이동 -> 2 * 현재위치
수빈이 걷기 -> 현 -1 or 현 + 1

N의 상태가 영 심상치않으니 절대 브루트포스는 아닐 것
'최단시간'이니까 BFS로 푸는것이 합당해보인다
수빈이가 순간이동 할 수 있는 위치와 -1, +1이 되어있는 위치가 직접적으로 이어져있다고 생각하자!
그런데 정점들을 헤집으면서 최단시간을 잴 때, 나이트의 이동처럼 구조체에 넣어놓고 하는게 좋을 것 같다는 생각이 들었다
*/

/*
 // 재영이의 코드리뷰
 1.
 사실 2 * 현재위치든, 현재위치 플마 1이든 전부 이전보다 time이 +1 이다
 그래서 minTime 비교 안쓰고 바로 return해도 괜찮다고 했는데 왜죠..?
 
 나 : 근데 꺼내는게 무조건 최솟값이라는 보장이 없잖아..?
 재 : 그래서 BFS를 쓰는거야!
 왜냐하면 큐는 FIFO라는걸 기억하세요.
 그러면 n+1 > n > 2N 비교하고 그 뒤에 다음 스탭으로 비교하게됨
 즉, 같은 선상의 시간끼리 비교하는거니까 바로 리턴해도된다
 
 2.
 minTime 999999를 하셨는데 만약에 문제에서 뭐 도달 못할수도 있다..
 이런 경우가 있을 수도 있음
 그럴 경우에는 -1를 출력하도록
 
 그리고 999999보다 화끈하게 1e9 고고
 */
