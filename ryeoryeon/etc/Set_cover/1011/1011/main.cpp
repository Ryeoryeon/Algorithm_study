//
//  main.cpp
//  1011 (midterm_assignment)
//
//  Created by 이영현 on 2020/05/11.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib> // atoi
#include <algorithm>
#include <cstdio> // 혹시나 해서 추가해줌

#define SUBSET_MAX_WHITE 30 // 두 자리 숫자가 10개, 공백이 9개 들어가는 최대길이

using namespace std;

//부분집합의 원소 개수가 많은 순으로 정렬되도록
bool compare_size(const vector<int> &v1, const vector<int> &v2)
{
    if (v1[10] > v2[10]) return true;
    
    else if (v1[10] == v2[10]) return v1[11] < v2[11];
    
    return false;
}

//겹치는 원소의 개수가 많은 순으로 정렬되도록
bool compare_numbers(const vector<int> &v1, const vector<int> &v2)
{
    if (v1[12] > v2[12]) return true;
    
    else if (v1[12] == v2[12]) return v1[11] < v2[11];
    
    return false;
}


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> num_set;
    vector<int> whole_num_set;
    int u_size;
    cin>>u_size;
    cin.ignore();
    
    whole_num_set.assign(u_size,0);
    num_set.assign(u_size, vector<int>(13, -1)); // 10 : 실제 size, 11 : 정렬되기 전 index, 12 : 겹치는 수의 개수
    
    for(int i=0; i<u_size; i++)
        whole_num_set[i] = i+1;
    
    for(int i=0; i<u_size; i++)
    {
        char temp[SUBSET_MAX_WHITE];
        
        scanf("%[^\n]s", temp, SUBSET_MAX_WHITE);
        getchar(); // 버퍼 비우기
        
        //입력받은 문자열 체크
        
        int idx = 0;
        int temp_num = 0;
        
        //스페이스바가 끝날 때 까지 각 숫자를 변환해 합산하고 저장
        for(int j=0; temp[j]!='\0'; j++)
        {
            //char * temp_char;
            char temp_char[2];
            temp_char[0] = temp[j];
            
            if(temp_char[0] != ' ')
            {
                //문자 숫자로 변경
                temp_num = temp_num * 10 + atoi(temp_char);
                
            }
            
            else
            {
                num_set[i][idx] = temp_num;
                idx++;
                temp_num = 0;
                    
            }
        }
        
        //대입되지 못한 마지막 숫자 대입
        num_set[i][idx] = temp_num;
        num_set[i][10] = idx + 1;
        num_set[i][11] = i + 1;
        num_set[i][12] = num_set[i][10];
    }
    
    //sort(num_set.begin(), num_set.end(), compare_size);
    vector<int> covered_list;
    vector<int> covered_list_index;
    
    int idx = 0;
    
    //whole_num_set.empty()는 covered_list.size==u_size와 같은 목적으로 사용될 수 있음
    int rows = u_size;
    
    while(covered_list.size() != u_size)
    {
        //U의 원소들을 가장 많이 포함하고 있는 집합 Si를 F에서 선택
        //처음에는 실행되지 않아도 되는 반복문
        if(covered_list.size() != 0)
        {
            for(int j=0; j<rows; j++)
            {
                //겹치는 원소의 개수 초기화
                num_set[j][12] = 0;
                
                for(int k=0; k<num_set[j][10]; k++)
                {
                    for(int l=0; l<whole_num_set.size(); l++)
                    {
                            if(whole_num_set[l] == num_set[j][k])
                            {
                                num_set[j][12]++;
                                break;
                            }
                    }
                }
            }
        }
        
        sort(num_set.begin(), num_set.end(), compare_numbers);
        
        covered_list_index.push_back(num_set[idx][11]);
        
        for(int k=0; k<num_set[idx][10]; k++)
        {
            for(int l=0; l<whole_num_set.size(); l++)
            {
                //부분집합의 원소가 whole에 포함되어 있으면 지우고 covered 집합에 넣기
                  if(whole_num_set[l] == num_set[idx][k])
                  {
                      whole_num_set.erase(whole_num_set.begin() + l);
                      covered_list.push_back(num_set[idx][k]);
                      
                      break;
                  }
            }
        }
        
        //idx에 해당하는 행 삭제
        num_set.erase(num_set.begin() + idx);
        rows--;
    }
    
    sort(covered_list_index.begin(), covered_list_index.end());
    
    int covered_index_size = covered_list_index.size();
    
    for(int i=0; i<covered_index_size; i++)
    {
        if(i!=covered_index_size - 1)
            cout<<covered_list_index[i]<<' ';
        else
            cout<<covered_list_index[i];
    }
    
    return 0;
}

