//
//  main.cpp
//  1013 // knapsack problem
//
//  Created by 이영현 on 2020/05/25.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct item
{
    int value;
    int weight;
};

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int item_num, max_weight;
    cin>>item_num>>max_weight;
    
    item * item_list;
    item_list = (item*)malloc(sizeof(item) * item_num);
    
    for(int n=0; n<item_num; n++)
    {
        cin>>item_list[n].value>>item_list[n].weight;
    }
    
    vector<int> max_value_list;
    vector<int> temp_value_list; // 그냥 max_value_list에서 값 따오고 바로바로 비교하면 대입하는 중간에 값이 갱신되어서 중복된 아이템이 들어가는 문제가 생긴다!
    
    // 0의 무게부터 최대 무게까지 고려하므로 +1
    // (인덱스 값이 곧 잔여 무게임을 잊지 말자!)
     max_value_list.assign(max_weight + 1, 0);
     //temp_value_list.assign(max_weight + 1, 0);

    
    for(int j=0; j<item_num; j++) // j는 아이템의 인덱스
    {
        temp_value_list.assign(max_value_list.begin(), max_value_list.end()); // 벡터 복사
        
        for(int k=item_list[j].weight; k<=max_weight; k++)
        {
            // 잔여 무게 - 새로 추가하려는 아이템의 무게 >=0 일때 추가 가능!
            // k가 곧 max_value_list의 인덱스 == 잔여 무게
            
            // 기존 값보다 더해지는 value가 더 큰가?
            // 더해지는 value는 ex. 무게 4의 물건이 추가되면 0의 value+4의 value 해야 함.
            if(temp_value_list[k] < (item_list[j].value + temp_value_list[k-(item_list[j].weight)]))
                max_value_list[k] = item_list[j].value + temp_value_list[k-(item_list[j].weight)];
        }
    }
    
    cout<<max_value_list[max_weight];
    
    free(item_list);
    
    return 0;
}
