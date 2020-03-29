//
//  main.cpp
//  4811
//
//  Created by 이영현 on 2020/03/24.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>

//할아버지는 매번 알약 반 조각을 먹는다.
//약이 N개 담긴 병을 선물로 주었다.
//첫째 날에 할아버지는 약 하나를 꺼내서 반을 먹고 다른 조각은 다시 병에 넣는다.
//다음 날부터 종수는 약을 하나씩 꺼내는데 반조각일수도 있고 한조각 전체일수도 있다. (반복)

//한조각을 꺼낸 날은 == W
//반조각을 꺼낸 날은 == H

//2N일이 지났을 때, 가능한 서로 다른 문자열의 개수는 총 몇 개? (단, N은 30 이하)

using namespace std;

//재귀 회수 트리거
//1. 하나로 남아있는 알약이 모두 소모되었을 때 (이제 반쪽짜리 알약밖에 꺼내는 경우만 남았을 때)
//2. 모든 알약을 다 먹었을 때
//그런데 어차피 2는 1에 포함되니까 걍 1로만 재귀 회수하면 될 것 같다.

//20부터 엄청나게 오랜 시간이 걸린다..

unsigned long long int drug(int remain_half, int remain_one)
{
    unsigned long long int num = 0; // 알약이 30개면 int의 범위를 한참 초과함.
    
    if(remain_one == 0)
        return 1; // 0? 1? (1임! 얘도 하나의 경우니까 하나로 더해줘야 함.)
    
    if(remain_half == 0)
        return num + drug(remain_half+1, remain_one-1);
    
    return num + drug(remain_half+1, remain_one-1) + drug(remain_half-1, remain_one);
}

int main(int argc, const char * argv[]) {
    
    int drug_num;
    
    while(1)
    {
        cin>>drug_num;
        
        if(drug_num==0)
            break;
        
        cout<<drug(0, drug_num)<<'\n';
    }

    return 0;
}

//처음에 짠 코드

/*
 //
 //  main.cpp
 //  4811
 //
 //  Created by 이영현 on 2020/03/24.
 //  Copyright © 2020 이영현. All rights reserved.
 //

 #include <iostream>

 //할아버지는 매번 알약 반 조각을 먹는다.
 //약이 N개 담긴 병을 선물로 주었다.
 //첫째 날에 할아버지는 약 하나를 꺼내서 반을 먹고 다른 조각은 다시 병에 넣는다.
 //다음 날부터 종수는 약을 하나씩 꺼내는데 반조각일수도 있고 한조각 전체일수도 있다. (반복)

 //한조각을 꺼낸 날은 == W
 //반조각을 꺼낸 날은 == H

 //2N일이 지났을 때, 가능한 서로 다른 문자열의 개수는 총 몇 개? (단, N은 30 이하)

 using namespace std;

 //재귀 회수 트리거
 //1. 하나로 남아있는 알약이 모두 소모되었을 때 (이제 반쪽짜리 알약밖에 꺼내는 경우만 남았을 때)
 //2. 모든 알약을 다 먹었을 때
 //그런데 어차피 2는 1에 포함되니까 걍 1로만 재귀 회수하면 될 것 같다.

 unsigned long long int drug(int remain_half, int remain_one)
 {
     unsigned long long int num = 0; // 알약이 30개면 int의 범위를 한참 초과함.
     
     if(remain_one == 0)
         return 1; // 0? 1? (1임! 얘도 하나의 경우니까 하나로 더해줘야 함.)
     
     else if(remain_half < 0) // H를 뽑을 수 없는 경우라면 과감히 돌아가게 해 주자.
         return 0;
     
     return num + drug(remain_half+1, remain_one-1) + drug(remain_half-1, remain_one);
 }

 int main(int argc, const char * argv[]) {
     
     int drug_num;
     
     while(1)
     {
         cin>>drug_num;
         
         if(drug_num==0)
             break;
         
         cout<<drug(0, drug_num)<<'\n';
     }

     return 0;
 }

 */
