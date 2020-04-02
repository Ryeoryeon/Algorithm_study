//
//  main.cpp
//  피보나치킨
//
//  Created by 이영현 on 2020/04/02.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
vector<int> real_zeck_list; // 제켄도르프 법칙을 이용하는 경우 그 수를 이루는 Index를 저장한다.

//input보다 작거나 같은 피보나치 수 list를 구한다.
vector<int> fibonacci(int input)
{
    vector<int> fibonacci_list;
    //input보다 더 커지기 직전까지 피보나치 수를 구한다.
    
    fibonacci_list.push_back(0);
    fibonacci_list.push_back(1);
    fibonacci_list.push_back(1);
    
    int current_f = 0;
    
    for(int i=1; current_f != input; i++)
    {
        current_f = fibonacci_list[i] + fibonacci_list[i+1];
        
        if(current_f > input)
            break;
        
        fibonacci_list.push_back(current_f);
        
        //마지막 피보나치 수가 input과 같게 되면 대입 후 반복문을 빠져나가게 된다.
    }
    
    return fibonacci_list;
}

//일단 다 더해놨는데 완전 끝에서 꺾어야 하는 경우는 없는 것 같다.
//보통은 더해놨는데 Input보다 커서 문제인듯.

/*
 vector<int> zeckendorf(int index, int remain, const vector<int> & fibonacci_list, vector<int> zeck_list)
 {
     remain -= fibonacci_list[index];
     
     if(remain < 0)
     {
         remain += fibonacci_list[index];
         return zeckendorf(index - 1, remain, fibonacci_list, zeck_list);
     }
     
     zeck_list.push_back(fibonacci_list[index]);
     
     if(remain==0)
     {
         
         return zeck_list;
     }
         
     return zeckendorf(index - 2, remain, fibonacci_list, zeck_list);
     
 }
 */

int zeckendorf(int index, int remain, const vector<int> & fibonacci_list)
{
    remain -= fibonacci_list[index];
    
    if(remain < 0)
    {
        remain += fibonacci_list[index];
        return zeckendorf(index - 1, remain, fibonacci_list);
    }
    
    real_zeck_list.push_back(index);
    
    if(remain==0)
    {
        return 1;
    }
        
    return zeckendorf(index - 2, remain, fibonacci_list);
    
}


int fibonachiken(int input)
{
    vector<int> fibonacci_list = fibonacci(input);

    unsigned int vector_size = (fibonacci_list.size() - 1);
    
    //피보나치 리스트의 마지막 수 != input이면 input에 대해 제켄도르프 정리를 사용해야 한다.
    if(fibonacci_list[vector_size]!=input)
    {
        //일단 이 경우라면 피보나치 수 벡터의 마지막 원소가 input보다 마지막으로 작은 피보나치 친구임.
        zeckendorf(vector_size, input, fibonacci_list);
        int sum = 0;
        
        for(int i=0; i<real_zeck_list.size(); i++)
        {
            sum += fibonacci_list[real_zeck_list[i] - 1];
        }
        
        return sum;
        
    }
    
    else
    {
        return fibonacci_list[vector_size - 1];
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    //입력 값은 최대 3억 이하의 자연수
    string str;
    cin>>str;
    
    int input = atoi(str.c_str());
    
    //input이 피보나치수의 합으로 이루어질 때 input보다 작은 최대 피보나치 수가 무조건 포함된다는 가정 하에.
    cout<<fibonachiken(input);
    
    return 0;
}


//제켄도르프 정리 의사코드를 짜 보자!
/*
    재귀 사용
        만일 인덱스가 0이나 1인데도 여태까지 더한 수가 != input이라면 글렀음. 다시 처음부터 해야함. acuum의 맨 처음 값을 피보나치 리스트에서 인덱스 하나 작은걸로..
        이걸 어떻게 처리할 것인가?
        
        //방안 1
            bool형 함수로 정의하고 다 더했을 때 틀려?! 그러면 false 반환하고 다시 다른 값을 max로 넣어주는 건 함수의 외부에서 처리해 주는 방법 (#반복문)
            단점 : vector로 다시 한꺼번에 리스트 뽑으려면 귀찮아짐.
 
        //방안 2
            vector 반환형 함수로 정의하고 다 더했을 때 틀리면 걍 다시 처음으로 돌아가서 하면 됨.
            단점 : 어떻게 짜야할지 모르겠음 시밤
 
        //방안 3
            어차피 총 치킨수를 뽑는거니까 int반환형 함수로 정의하고,
            만약 이렇게 해서 안 나왔을 경우는 0을 반환하게 해서 앗! 0이 반환되면 다음 수를 집어넣자! 하게 하는거징.
 
            만약 제켄도르프로 수를 찾으면 미리 계산해놨던 치킨수를 출력하는거고.
 */

/*
 제켄도르프 법칙을 어떻게 적용하지?
 우리의 뇌는 어떨까?
 ex. 일단 적용하려는 수보다 작은 수 중에 가장 큰 수를 대입하겠지.
 
 17 = 13 + 3 + 1
 
 17 - 13 = 4
 4 중에 피보나치 수가 있나요? 없습니다!
 4 = 3 + 1 로 합니다.
 
 2000 = 1597 + 377 + 21 + 5
 377 전에 610이 있다.
 2000 - 1597 = 403 (610은 이것보다 크므로 만족 못함)
 
 403 - 377 = 26
 26 = 바로 만족하는 수가 21
 
 26 - 21 = 5
 5 = 5
 
 만약 적용하려는 보다 가장 큰 수 대입을 했는데 안 되는 경우면..
 다음 수를 대입하면 되겠지.
 */
