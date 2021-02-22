//
//  main.cpp
//  N과 M(3)
//
//  Created by 이영현 on 2021/02/06.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int sum;
int n, m;
vector<int> nmList;

void realNM(int cnt)
{
    // 재영 : 회수는 기저 사례에서 해줘야해요!!!!
    if(cnt == m) // 스택에 M개가 쌓이면 출력하고 하나 빼기~!
    {
        for(int i=0; i<m; ++i)
            cout<<nmList[i]<<' ';
        nmList.pop_back(); // 똥은 얘가치워
        cout<<'\n';
        return ;
    }
    
    for(int i=1; i<=n; ++i)
    {
        nmList.push_back(i); // 얘는 똥을 싸는애야
        
        int size = nmList.size();
        realNM(size);
    }
    nmList.pop_back();
    
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    realNM(0);
    return 0;
}

//
/*
 
 #include <iostream>
 #include <vector>
 #include <cmath>
 using namespace std;

 int N, M;
 vector<int> N_list;
 vector<int> N_choice_list;
 
 void printNM_final(int idx)
 {
     N_choice_list.push_back(idx);
     if(N_choice_list.size()==M)
     {
         for(int i=0; i<M; ++i)
             cout<<N_choice_list[i]<<' ';
         cout<<'\n';
         // 재귀 종료
         if(idx >= N)
             return ;
         
         N_choice_list.pop_back();
         return printNM_final(idx + 1);
     }
     return printNM_final(idx + 1);
 }

 int main(int argc, const char * argv[]) {
     // N개 중 M개를 고르는 순열
     cin>>N>>M;
     N_list.assign(N, 0);
     
     for(int i=0; i<N; i++)
         N_list[i] = i+1;
     
     printNM_final(1);
     
     return 0;
 }
 
 */
