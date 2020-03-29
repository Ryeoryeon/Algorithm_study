//
//  main.cpp
//  1914
//
//  Created by 이영현 on 2020/03/29.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
//필요한 이동 순서 출력하기!

int main(int argc, const char * argv[]) {
    
    vector<int> top_list; // 장대의 가장 위에 있는 원소를 나타내는 벡터
    top_list.assign(3, 0);
    
    int K_number;
    cin>>K_number;

    top_list[0] = K_number;
    
    return 0;
}

int hanoi_tower(int K_number, int index, vector<int> top_list)
{
    //K-1개의 기둥을 왼쪽에서 가운데로 옮긴다. (1)
    //맨 왼쪽의 마지막 기둥을 맨 오른쪽으로 옮긴다.
    //가운데의 K-1개의 기둥을 오른쪽으로 옮긴다 * -> (2)
    
    //(2)
    //K-2개의 기둥을 가운데 기둥에서 왼쪽으로 옮긴다.
    //가운데의 마지막 기둥을 맨 오른쪽으로 옮긴다.
    //왼쪽의 K-2개의 기둥을 오른쪽으로 옮긴다 * -> (1) 반복
    
    int movement = 0;
    
    if(index==1) // 함수 종료, 여태까지 구한 수 출력하기
        return 1;
    
    
    
    return movement + (hanoi_tower(K_number, index-1, top_list));
}
