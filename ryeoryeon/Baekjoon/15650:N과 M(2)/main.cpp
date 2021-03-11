#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> printList;

void NnM_2()
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
            if(size != 0 && printList[size - 1] >= i)
                continue;
            
            printList.push_back(i);
            NnM_2();
            printList.pop_back(); // 여기서 빼줘야 사이좋게 들어간다
        }
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    NnM_2();
    
    return 0;
}
