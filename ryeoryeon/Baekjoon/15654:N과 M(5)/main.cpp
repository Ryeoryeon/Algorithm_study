#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> printList;
vector<int> numList;
vector<int> isChecked;

void NnM_5()
{
    int size = printList.size();
    if(size == M) // 재귀 회수시점
    {
        for(int i=0; i<M; ++i)
            cout<<printList[i]<<' ';
        cout<<'\n';
    }
    
    else
    {
        for(int i=0; i<N; ++i)
        {
            int size = printList.size();
            if(isChecked[numList[i]])
                continue;
            
            printList.push_back(numList[i]);
            isChecked[numList[i]] = 1;
            NnM_5();
            int last = printList.back();
            isChecked[last] = 0;
            printList.pop_back(); // 여기서 빼줘야 사이좋게 들어간다
        }
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    numList.assign(N, 0);
    
    for(int i=0; i<N; ++i)
        cin>>numList[i];
    
    sort(numList.begin(), numList.end());
    isChecked.assign(numList.back() + 1, 0); // (5) (제일 큰 수 + 1만큼으로 벡터 초기화)
    NnM_5();
    
    return 0;
}
