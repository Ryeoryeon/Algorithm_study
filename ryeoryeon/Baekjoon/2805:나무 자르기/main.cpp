//
//  main.cpp
//  2805 / 나무 자르기
//
//  Created by 이영현 on 2021/03/30.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int N, M; // 수확한 나무의 합이 M보다 크거나 같아야한다! (단, 수확한 나무의 합이 M에 가까울수록 좋다)
int maxHeight; // 절단기의 높이
long long int harvestWood = 0; // 수확 나무 길이합
int savingHeight;
vector<int> woodList;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;
    woodList.assign(N, 0);
    int maxWood = -1;
    
    for(int i=0; i<N; ++i)
    {
        cin>>woodList[i];
        if(maxWood < woodList[i])
            maxWood = woodList[i];
    }
    
    int left = 0;
    int right = maxWood;
    int mid;
    
    for(int size = maxWood + 1; size>=1; size/=2) // size는 0부터 maxWood까지니까 maxWood + 1
    {
        // 나무와 절단기의 길이를 계속 비교하려면 woodList를 한 번 돌아야할텐데..
        // 그런데 중첩되면 시간초과..? -> 재영 : 왜요? 어차피 이분탐색이잖아요 -> 아!
        mid = (left + right) / 2;
        harvestWood = 0;
        
        for(int j=0; j<woodList.size(); ++j)
        {
            if(mid < woodList[j]) // 절단기의 길이가 나무보다 길어 나무가 잘리는 경우
                harvestWood += (woodList[j] - mid);
        }
        
        if(harvestWood == M)
        {
            savingHeight = mid;
            break;
        }
        
        else if (harvestWood < M) // 수확량을 키워야한다 -> 절단기의 사이즈를 작게 해야한다
            right = mid - 1;
        
        else // harvestWood > M // 수확량을 작게 하면 좋다 -> 절단기의 사이즈를 크게 해야한다
        {
            left = mid + 1;
            savingHeight = mid; // 만일 M에 딱 충족하는 수확량이 없을 수도 있으니까
        }
            
    }
    
    cout<<savingHeight;
    
    return 0;
}

/*

// 사고의 흐름
이 문제의 정체는 대체 뭘까..?
일단 이 문제에서 중요한 건 다름이 아니라,
땅에 심은 나무(통나무 X)를 자르고 '수확한' 나무의 길이
-> 절단기를 자르고 수확한 나무들로 벡터를 만들어야하나..?

// 재영이의 힌트
(1) 첫 번째 힌트
어디에 포커스를 둬야할까?
-> 수확한 나무의 합이 아니라 절단기의 높이에 포커스를 둬야 한다

// 절단기에 포커스
1. 절단기의 길이가 높아질수록 수확한 나무의 길이가 짧아진다

// 절단기
절단기의 높이는 가장 길이가 긴 나무의 높이부터 시작하는거야
그런데 하나씩 절단기의 높이를 줄여가며 수확한 나무의 길이합을 갱신하는거지
-> 그런데 시간초과 뜰것같음.. 만일 한 나무의 높이가 너무 높은 경우 망함.

// 재영이의 힌트
(2) 두 번째 힌트
이분탐색 어케함?
-> 키 값과 mid비교
L,R,mid를 절단기의 높이라고 생각하시면 된다 (???)

// 다시 생각해보는 절단기
초기값
L : 0
R : 가장 길이가 긴 나무의 높이

mid는 그 중간이 되겠지
그러면 배열에 저장이 되는 원소들은 그 절단기로 잘랐을 때의 수확한 나무의 길이 합 (!!)
그래서 이제 sort하고, lower_bound로 찾는거지
재 : sort가 필요할까요?
영 : 20, 15, 10, 17 -> 15로 자르면 5, 15, 10, 2가 되지 않아?
재 : ㄴㄴ '수확한 나무'의 길이니까 5, 0, 0, 2임. 그러면 절단기의 길이가 작아질수록 수확한 나무의 길이가 커지는 정렬이 됨.
-> sort도 필요 없음

// 헷갈렸던 부분
이분탐색에서 수확량을 늘린다/줄인다가 절단기의 길이와 반비례여서 그 점이 좀 많이 헷갈렸다

// 처음 틀렸을 때
왜 틀렸지?
10억짜리 나무가 여러개가 나올 수 있으므로 나무 수확량 합이 21억이 초과할 수 있다
지금 최악은 10억 * 1000,000 == 10^15)
long long int는 2^64 (즉, 10^16까지는 커버)

// 그래서 이분 탐색이어야만 하는 이유는?
1. 브루트포스 -> 100% 시간초과. 안됨.
2. 그 때부터는 다른 방법을 써야하고, 여러 가지 생각을 해 본다. (그리디, 이분탐색 등)
   -> 그 중 하나가 이분탐색인거.
   a. 어떻게 이분탐색인걸 쉽게 찾아낼 수 있었을까?
       aa. 아 순차적으로 찾으면 시간초과가 너무 크니까 이분탐색으로 찾아야하나..? 라는 생각에서 시작한다고 한다.
*/
