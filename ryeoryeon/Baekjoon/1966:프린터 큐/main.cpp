//
//  main.cpp
//  1966:프린터 큐
//
//  Created by 이영현 on 2020/12/31.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int test;
    cin>>test;
    
    for(int i=0; i<test; i++)
    {
        int numDocs, docs;
        cin>>numDocs>>docs;
        vector<int> docs_list;
        docs_list.assign(numDocs, 0);
        int ans = 0;
        
        for(int j=0; j<numDocs; j++)
            cin>>docs_list[j];
        
        if(numDocs == 1)
        {
            if(i == (test-1))
                cout<<1;
            else
                cout<<1<<'\n';
            continue;
        }
        
        while(1)
        {
            if(docs_list.size() == 1 || docs_list[0] != 9) // 원소가 하나 남았거나 중요도가 9일 경우 바로 출력
            {
                for(int k=1; k<docs_list.size(); k++)
                {
                    if(docs_list[k] > docs_list[0])
                    {
                        int temp = docs_list[0];
                        docs_list.erase(docs_list.begin());
                        docs_list.push_back(temp);
                        
                        docs--; // 내가 검사하려는 문서를 한 칸 앞으로 이동
                        if(docs == -1) // 현재 내가 검사하려는 문서가 벡터의 끝을 넘어갔을 경우
                            docs = (docs_list.size() - 1);
                        
                        k = 0; // 다음 첫번쨰가 되는 원소에 대해 비교할 수 있도록 k값 초기화
                    }
                }
            }
            
            // 출력 처리
            
            if(docs == 0)
            {
                ans++;
                if(i == (test-1))
                    cout<<ans;
                else
                    cout<<ans<<'\n';
                break;
            }
            
            else
            {
               docs_list.erase(docs_list.begin());
                ans++;
                docs--;
            }
        }

    }
    return 0;
}
