//
//  main.cpp
//  1010 (midterm_assignment)
//
//  Created by 이영현 on 2020/05/09.
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
    int duration;
};

bool compare(const task &t1, const task &t2)
{
    if (t1.finish < t2.finish) return true;
    
    else if (t1.finish == t2.finish) return t1.start < t2.start;
    
    return false;
}


task * task_list;

int main(int argc, const char * argv[]) {
    
    vector<int> choice_list; // 선택한 task의 종료 시간이 들어간다.
    
    int task_num;
    cin>>task_num;
    
    task_list = (task*)malloc(sizeof(task) * task_num);
    
    for(int i=0; i<task_num; i++)
        cin>>task_list[i].start>>task_list[i].finish;
    
    
    // 시작 시간 순서대로 정렬
    sort(task_list, task_list + task_num, compare);

    // 일찍 끝나는 회의일수록 우선순위로 배치한다!
    
    int idx = 0;
    int c_idx = -1;
    
    while(idx != task_num)
    {
        if(c_idx == -1)
        {
            choice_list.push_back(task_list[idx].finish);
            idx++;
            c_idx++;
        }
        
        // 선택한 task가 아직 끝나지 않았을 때 (task 선택 x)
        if(choice_list[c_idx] > task_list[idx].start)
        {
            idx++;
            continue;
        }
        
        // idx == task_num - 1 이거나
        // idx의 피니시가 idx+1의 피니시보다 더 빨리 끝나거나
        else
        {
            choice_list.push_back(task_list[idx].finish);
            idx++;
            c_idx++;
        }
    }
    
    cout<<choice_list.size()<<'\n';
    
    free(task_list);
    
    return 0;
}
