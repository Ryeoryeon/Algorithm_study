//
//  main.c
//  10M sorting_C
//
//  Created by 이영현 on 2020/04/13.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <stdio.h>

int * sorting_list;

void merge_sort(int *list, int left, int right);

int main(void){
    
    int num = 0;
    scanf("%d", &num);
    
    int * list = (int*)malloc(num * sizeof(int));
    sorting_list = (int*)malloc(num * sizeof(int));
    
    for(int k=0; k<num; k++)
    {
        scanf("%d", &list[k]);
    }
    
    merge_sort(list, 0, num - 1);
    
    for(int i=0; i<num; i++)
    {
        printf("%d\n", list[i]);
    }
    
    return 0;
    
}

void merge_sort(int *list, int left, int right)
{
    if(left < right)
    {
        int center = (left+right)/2;
        
        merge_sort(list, left, center);
        merge_sort(list, center+1, right);
        
        //merge(list, left, center, right);
        int index_left = left;
        int index_right = center+1;
        int index_m1 = left;
        
        //index_left와 index_right 모두 범위 내에 있을 때
        
        //@ 이 부분 먼저 쓰기 주의!
        while(index_left <= center && index_right <= right)
        {
            //왼쪽과 오른쪽 중 왼쪽이 더 작을 때
            if(list[index_left] <= list[index_right])
            {
                sorting_list[index_m1] = list[index_left];
                index_left++;
            }
            
            //오른쪽이 더 작을 때
            else
            {
                sorting_list[index_m1] = list[index_right];
                index_right++;
            }
            
            index_m1++;
        }
        
        //오른쪽 부분이 범위를 벗어난 경우
        if(index_right > right)
        {
            //여태 대입한 왼쪽 친구들을 끝날 때 까지 순차적으로 대입 해 준다.
            for(int ind = index_left; ind <= center; ind++)
            {
                sorting_list[index_m1] = list[ind];
                index_m1++;
            }
        }
        
        //왼쪽 부분이 범위를 벗어난 경우 (index_left > center)
        else
        {
            for(int ind = index_right; ind <= right; ind++)
            {
                sorting_list[index_m1] = list[ind];
                index_m1++;
            }
            
        }
        
        //list = sorting_list; // 아! 이렇게 해 주면 길이 이상한거까지 복사되니까..
        //바꿔줘야 할 구간만 인덱스를 받아서 바꿔줘야 한다.
        for(int ind = left; ind <=right; ind++)
        {
            list[ind] = sorting_list[ind];
        }
        
    }
    
}
