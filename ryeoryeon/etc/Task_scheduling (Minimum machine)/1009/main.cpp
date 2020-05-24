//
//  main.cpp
//  1009 (task_scheduling) // 최소 기계의 수
//
//  Created by 이영현 on 2020/05/25.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct task
{
    int start;
    int finish;
};

bool compare(const task &t1, const task &t2)
{
    if (t1.start < t2.start) return true;
    
    else if (t1.start == t2.start) return t1.finish < t2.finish;
    
    return false;
}

task * task_list;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> machine_list;
    
    int task_num;
    cin>>task_num;
    
    task_list = (task*)malloc(sizeof(task) * task_num);
    
    for(int i=0; i<task_num; i++)
        cin>>task_list[i].start>>task_list[i].finish;
    
    // 시작 시간 순서대로 정렬
    sort(task_list, task_list + task_num, compare);

    // 일찍 시작하는 회의일수록 우선순위로 배치한다!
    
    int idx = 0;
    machine_list.assign(1, 0);
    
    /*
     처음 사이즈는 따로 지정 ㄴㄴ (새로운 기계를 assign할 때마다 push_back)
     벡터의 사이즈만큼 매번 반복문을 돌되 마지막으로 저장된 기계의 인덱스를 저장
     새로운 기계를 갱신할 때 기계의 인덱스를 저장하도록! -> 마지막으로 저장된 기계의 끝나는 시간을 저장하도록!
     */
    
    //처음에는 무조건 배치
    machine_list[0] = task_list[0].finish;
    idx++;
    
    while(idx != task_num)
    {
        int size = machine_list.size();
         
         //모든 기계를 탐색해보고 만일 기계에서 수행하던 작업이 끝나 있다면 그 기계에 새로 배치한다.
         
         for(int k=0; k<size; k++)
         {
             //기존 기계에 작업을 배치할 수 있는 경우
             if(machine_list[k] <= task_list[idx].start)
             {
                 machine_list[k] = task_list[idx].finish;
                 idx++;
                 break;
             }
             
             //모든 기계를 탐색해봤으나, 기존의 기계에서는 해당 idx의 task를 수행할 수 없을 때
             if(k==size - 1)
             {
                 machine_list.push_back(task_list[idx].finish);
                 idx++;
             }
         }
    }
    
    cout<<machine_list.size(); // 엔터 뺐음
    
    free(task_list);
    
    return 0;
}
