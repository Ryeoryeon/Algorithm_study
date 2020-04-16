//
//  main.cpp
//  10M sorting
//
//  Created by 이영현 on 2020/04/12.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> list;
vector<int> sorting_list;
void merge_sort(int first, int last);

//사실 해 놓고 보니 합병 정렬이 아니..네..?
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int num;
    cin>>num;
    
    //크기가 num 사이즈인 배열에 저장되는 비정렬 숫자들
    list.assign(num, 0);
    
    /*
     for(int i=0; i<num; i++)
     {
         cin>>list[i];
     }
     */
    
    //테스트용
    for(int i=0; i<num; i++)
    {
        list[i] = rand() % num + 1;
    }
    
    
    int size = list.size();
    int last_index = size - 1;
    
    //시작!
    
    //(처음 아이디어)
    //index가 처음에는 1로 시작. 두배씩 증가.
    //단, 남은 길이가 인덱스의 두배보다 작을 때 (홀수일 때)는 나머지 한꺼번에 합침
    //그런데 이제 index가 전체 길이의 반이 됐을 때 그만두자!
        
    int index = 2; // 해당 단계가 목표로 하는 단위 배열 안의 원소의 개수. (1단계는 2개 -> 2단계는 4개 ..)
    int step = 0; // 단계. 딱 반반씩 떨어지지 않고 마지막에 애매하게 서로 찢어졌을 때를 위해 넣음.
        
    sorting_list = list;
    
    int pair_index = num;
        
        while(pair_index!=1)
        {
            int pair_num = (pair_index+1)/2; //ex. 원소의 개수가 9개면 첫 쌍은 5개, 10개여도 5개.
            
            int left_to_right;
            
            //마지막 단계에서는 꼭 left_to_right 재정의가 필요.
            if(pair_num<=2)
                left_to_right = pow(2,step); // left와 right 사이의 배열 간격
            
            else
                left_to_right = index/2; // left와 right 사이의 배열 간격
            
            for(int pair=0; pair<pair_num; pair++)
            {
                int index_left = pair * index;
                int index_right = index_left + left_to_right;
                
                //잉여가 남을 때
                if(index_right >= size)
                    break;
                
                for(int ind=pair*index; (ind - (pair*index))<index; ind++)
                {
                    //ind - (pair*index)는 현재까지 안에 들어간 배열의 개수
                    if(index_left == (pair*index + left_to_right))
                    {
                        //좌측에 있는 아이들이 이미 다 정렬되었을 때
                        //우측에 있는 아이들을 모두 sorting_list에 밀어넣어야함.
                        for(int j=index_right; j!=(pair*index + index); j++)
                        {
                            sorting_list[ind] = list[j];
                            ++ind;
                        }
                        break;
                    }
                    
                    else
                    {
                        //우측에 있는 아이들이 이미 다 정렬되었을 때 (단, pair*index + index가 사이즈를 뛰어넘을 때를 위해)
                        if(pair == pair_num - 1 && index_right == size)
                        {
                            //우측에 있는 아이들이 이미 다 정렬되었을 때
                            //좌측에 있는 아이들을 모두 sorting_list에 밀어넣어야함.
                            for(int j=index_left; j!=(pair*index + left_to_right); j++)
                            {
                                sorting_list[ind] = list[j];
                                ++ind;
                            }
                            break;
                        }
                        
                        else if(pair != pair_num - 1 && index_right == (pair*index + index))
                        {
                            //우측에 있는 아이들이 이미 다 정렬되었을 때
                            //좌측에 있는 아이들을 모두 sorting_list에 밀어넣어야함.
                            for(int j=index_left; j!=(pair*index + left_to_right); j++)
                            {
                                sorting_list[ind] = list[j];
                                ++ind;
                            }
                            break;
                        }
                        
                        if(list[index_left] < list[index_right])
                        {
                            sorting_list[ind] = list[index_left];
                            ++index_left;
                        }
                        
                        else
                        {
                            sorting_list[ind] = list[index_right];
                            ++index_right;
                        }

                    }
                    
                }
            }
            
            if(2*index <= size)
                index*=2;
            
            else
                index = size;
                
            ++step;
            pair_index = pair_num;
            list = sorting_list;
        }
     
    
    //merge_sort(0, last_index);
        
    for(int i=0; i<size; i++)
    {
        cout<<list[i]<<'\n';

    }
        
    return 0;
    
}


//
void merge_sort(int first, int last)
{
    //길이가 1이 되면 first==last가 됨
    if(first<last)
    {
        int k = (first+last)/2;
        
        //가장 안쪽의 재귀부터 풀림. 재귀가 하나 풀리면 이미 list에서 어느정도 정렬이 되는 상태.
        merge_sort(first, k);
        merge_sort(k+1, last);
        
        
        //list[first ~ k]와 list[k+1 ~ last]를 비교 후 합병
        int index_left = first;
        int index_right = k+1;
        int index_m1 = first;
        
        sorting_list = list; // sorting_list는 list가 정렬될 때 기준이 될, 맨 처음 상태의 list의 왼/오 벡터가 될 친구.
        
        while(1)
        {
            if(index_left > k) // 좌측에 있는 아이가 이미 정렬 끝난 경우
            {
                for(int i=index_right; i<last; i++)
                {
                    sorting_list[index_m1] = list[i];
                    ++index_m1;
                }
                break;
            }
            
            else if(index_right == last + 1) // 우측에 있는 아이가 이미 정렬 끝난 경우
            {
                for(int i=index_left; i<=k; i++)
                {
                    sorting_list[index_m1] = list[i];
                    ++index_m1;
                }
                break;
            }
            
            else
            {
                if(list[index_left] <= list[index_right])
                {
                    sorting_list[index_m1] = list[index_left];
                    ++index_left;
                    ++index_m1;
                }
                
                else
                {
                    sorting_list[index_m1] = list[index_right];
                    ++index_right;
                    ++index_m1;
                }
            }
        }
        
        list = sorting_list;
    }
}
