//
//  main.cpp
//  로또
//
//  Created by 이영현 on 2021/02/05.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main(int argc, const char * argv[]) {
    
    // 49개의 수 중, 수 k를 골라 집합 S를 만든 다음 번호를 선택한다
    int k;
    int testNum = 0;
    
    do
    {
        cin>>k;
        if(k!=0)
        {
            vector<int> S_list;
            S_list.assign(k, 0);
            
            if(testNum != 0)
                cout<<'\n'; // 테스트 케이스 간의 공백
            
            for(int i=0; i<k; i++)
            {
                int temp;
                cin>>temp;
                S_list[i] = temp;
            }
            
            // checkList 초기화 {0, 0, ... 1, 1} // 여섯개의 1
            vector<int> checkList;
            checkList.assign(k, 0);
            for(int i=0; i<6; i++)
                checkList[k - 1 - i] = 1;
            
            vector<int> printList;
            int rowNum = 0;
            do{
                for(int i=0; i<k; i++)
                {
                    if(checkList[i])
                        printList.push_back(S_list[i]);
                }
                
                ++rowNum;
            }while(next_permutation(checkList.begin(),checkList.end()));
            ++testNum;
            
            int size = printList.size() - 1;
            // 6 7 8 9 10 11
            // 0 1 2 3 4 5
            for(int i = (rowNum - 1); i>=0; --i)
            {
                for(int j=0; j<6; ++j)
                {
                    int idx = 6 * i + j;
                    cout<<printList[idx]<<' ';
                }
                cout<<'\n';
            }
        }
        
    }while(k!=0);
    
    return 0;
}
