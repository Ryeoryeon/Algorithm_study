#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> printList;

void NnM_4()
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
        for(int i=1; i<=N; ++i)
        {
            int size = printList.size();
            if(size != 0 && printList[size - 1] > i) // 처음엔 printList[0] > i인줄 알았는데 연쇄적으로 비교해야 하므로
                continue;
            
            printList.push_back(i);
            NnM_4();
            printList.pop_back(); // 여기서 빼줘야 사이좋게 들어간다
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    NnM_4();
    
    return 0;
}
