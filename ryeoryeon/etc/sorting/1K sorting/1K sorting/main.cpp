//
//  main.cpp
//  1K sorting
//
//  Created by 이영현 on 2020/04/11.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
vector<int> merge_sort(int first, int last);
vector<int> merge_compare (vector<int> v1, vector<int> v2);

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int num;
    cin>>num;
    
    //크기가 num 사이즈인 배열에 저장되는 비정렬 숫자들
    list.assign(num, 0);
    
     for(int i=0; i<num; i++)
     {
         cin>>list[i];
     }
    
    //테스트용
    /*
     for(int i=0; i<num; i++)
     {
         list[i] = rand() % num + 1;
     }
     */
    
    int size = list.size();
    int last_index = size - 1;
    
    vector<int> sorted = merge_sort(0, last_index);
    
    for(int i=0; i<size; i++)
    {
        cout<<sorted[i]<<'\n';
    }
    
    return 0;
}


vector<int> merge_sort(int first, int last)
{
    //v1을 처음에 끊어야 함
    //벡터를 쓸 거면..?
    
    int size = last - first + 1;
    
    if(size != 1)
    {
        vector<int> v1 = list;
        v1.erase(v1.begin()+first, v1.begin()+last);
    }
    
    if(size == 1)
    {
        vector<int> m1;
        m1.assign(1, 0);
        m1[0] = list[first];
        return m1;
    }
    
    vector<int> m1;
    m1.assign(size, 0);
    
    vector<int> left;
    vector<int> right;
    
    if(size >= 2)
    {
        //쪼개기
        int k = (first + last)/2;
        
        left = merge_sort(first, k);
        right = merge_sort(k+1, last);
        
        int index_left = 0;
        int index_right = 0;
        int index_m1 = 0;
        
        while(1)
        {
            if(index_left == left.size()) // 좌측에 있는 아이가 이미 정렬 끝난 경우
            {
                for(int i=index_right; i<right.size(); i++)
                {
                    m1[index_m1] = right[i];
                    ++index_m1;
                }
                break;
            }
            
            else if(index_right == right.size()) // 우측에 있는 아이가 이미 정렬 끝난 경우
            {
                for(int i=index_left; i<left.size(); i++)
                {
                    m1[index_m1] = left[i];
                    ++index_m1;
                }
                break;
            }
            
            else
            {
                if(left[index_left] <= right[index_right])
                {
                    m1[index_m1] = left[index_left];
                    ++index_left;
                    ++index_m1;
                }
                
                else
                {
                    m1[index_m1] = right[index_right];
                    ++index_right;
                    ++index_m1;
                }
            }
        }

    }
    
    return m1;
}
