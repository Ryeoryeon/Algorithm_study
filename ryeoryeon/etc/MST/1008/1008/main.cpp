//
//  main.cpp
//  1008
//
//  Created by 이영현 on 2020/04/27.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct line
{
    int d1;
    int d2;
    int weight;
    
};

int * root;
list<line> graph;

struct list_sorting
{
    bool operator()(line const & l1, line const & l2) const
    {
        return l1.weight < l2.weight;
    }
};

int find_root(int d1_index)
{
    int root_value = root[d1_index];
    
    //자기 자신이 루트가 아닌 경우
    if((d1_index + 1) != root_value) // 자기 자신 == d1_index + 1임에 주의!
    {
        //최종 루트까지 찾는다
        
        int final_root;
        
        //인덱싱 주의!
        for(final_root = root[root_value - 1]; final_root!=root[final_root - 1]; )
        {
            final_root = root[final_root - 1];
            
        }
        
        root_value = final_root;
        
    }

    return root_value;
}

int main(int argc, const char * argv[]) {
    
    int node_num, line_num;
    cin>>node_num>>line_num; // (node_num * (node_num - 1))/2;
    
    for(int i=0; i<line_num; i++)
    {
        line temp; // 임시값
        cin>>temp.d1>>temp.d2>>temp.weight;
        graph.push_back(temp);
    }
    
    graph.sort(list_sorting());
    list<line>::iterator it = graph.begin();
    
    root = (int*)malloc((sizeof(int)) * node_num);
  
    //맨 처음(연결되어 있지 않은)은 모든 노드의 루트 노드 == 자기 자신
    for(int i = 0; i < node_num; i++)
    {
        root[i] = i+1;
    }
     
    int weight_sum = 0;
    int current_lines = 0;
    
    while(it != graph.end())
     {
         line temp_ = *it;
         
         //모두 조사된거임!
         if(current_lines == node_num - 1)
             break;
         
         //find (추가하고 싶은 간선의 두 노드에 대해서 루트를 조사한다)
         //루트 노드 조사를 타고타고 올라간다.
        
         int root_d1 = find_root(temp_.d1 - 1);
         int root_d2 = find_root(temp_.d2 - 1);
        
         
         if(root_d1 == root_d2)
         {
             graph.erase(it++);
             //it++;
             continue; // 사이클이 만들어진다면 과감히 버린다.
         }
         
         //root[temp_.d2 - 1] = temp_.d1;
         root[root_d2 - 1] = temp_.d1;
             
         weight_sum += temp_.weight;
         current_lines++;
         it++;
     }
    
    cout<<weight_sum;
    
    /*
     while(it != graph.end())
      {
          line temp_ = *it;
          cout<<temp_.d2<<'\n';
          it++;
      }
     */
    
    return 0;
}
