#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> printList;
vector<int> numList;

void NnM_6()
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
            if(size != 0 && (numList[i] <= printList[size - 1])) // 어차피 연쇄적인 크기비교가 될 것이므로
                continue;
            
            printList.push_back(numList[i]);
            NnM_6();
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
    NnM_6();
    
    return 0;
}
