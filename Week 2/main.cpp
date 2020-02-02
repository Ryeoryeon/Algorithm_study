//
//  main.cpp
//  Boggle_game
//
//  Created by 이영현 on 2020/02/03.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Boggle_game.h"

bool hasWord(const std::vector<std::vector<char>>& Boggle, int index, int y, int x, const std::vector<char>& str_vec);

int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<char>> Boggle;
    Boggle.assign(5, std::vector<char>(5));
    
    Boggle = {{'U','R','L','P','M'},{'X','P','R','E','T'},{'G','I','A','E','T'},{'X','T','N','Z','Y'},{'X','O','Q','R','S'}};
    
    std::vector<char> str_vec;
    std::string str = "PRETTY";
    str_vec = string_split(str); // 문자열을 벡터에 저장할 수 있도록 해 주는 작업
    
    bool Ans = hasWord(Boggle, 0, 2, 2, str_vec); // y,x 기준은 0이 아닌 1부터 시작하는 걸로.
    
    return 0;
}

bool hasWord(const std::vector<std::vector<char>>& Boggle, int index, int y, int x, const std::vector<char>& str_vec)
{
    // ex. index가 0 (처음상황)이라면 첫글자부터 보글판에서 뻑이 난 경우.
    if(Boggle[y-1][x-1] != str_vec[index])
        return false;
    
    // 주위의 칸은 8칸이 될 수도 있고 더 적은 칸수가 남을 수도 있다.
    // 단, 왼쪽과 오른쪽 모두에 칸이 없을 수는 없고 위쪽과 아래쪽 모두에 칸이 없을 수는 없다.
    
    if(y-1 <= 0) // 위쪽에 칸이 없는 경우
    {
        if(x-1 <= 0) // 왼쪽에 칸이 없는 경우
        {
            // 기준의 칸으로부터 아래, 대각선(오른)아래, 오른
            hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
            hasWord(Boggle, index+1, y+1, x+1, str_vec); // 대각선(오른)아래
            hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
        }
        
        else if(x-1 >= 4) // 오른쪽에 칸이 없는 경우
        {
            // 기준의 칸으로부터 아래, 대각선(왼)아래, 왼
            hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
            hasWord(Boggle, index+1, y+1, x-1, str_vec); // 대각선(왼)아래
            hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
        }
        
        else // 왼쪽, 오른쪽 모두에 칸이 있는 경우
        {
            // 기준의 칸으로부터 왼쪽, 오른쪽, 대각선(왼,오른)아래, 아래
            hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
            hasWord(Boggle, index+1, y+1, x-1, str_vec); // 대각선(왼)아래
            hasWord(Boggle, index+1, y+1, x+1, str_vec); // 대각선(오른)아래
            hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
            hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
        }
    }
    
    else if(y-1 >= 4) // 아래쪽에 칸이 없는 경우
    {
        if(x-1 <= 0) // 왼쪽에 칸이 없는 경우
        {
            // 기준의 칸으로부터 위, 대각선(오른)위, 오른
            hasWord(Boggle, index+1, y-1, x, str_vec); // 위
            hasWord(Boggle, index+1, y-1, x+1, str_vec); // 대각선(오른)위
            hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
        }
        
        else if(x-1 >= 4) // 오른쪽에 칸이 없는 경우
        {
            // 기준의 칸으로부터 위, 대각선(왼)위, 왼
            hasWord(Boggle, index+1, y-1, x, str_vec); // 위
            hasWord(Boggle, index+1, y-1, x-1, str_vec); // 대각선(왼)위
            hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
        }
        
        else // 왼쪽, 오른쪽 모두에 칸이 있는 경우
        {
            // 기준의 칸으로부터 왼쪽, 오른쪽, 대각선(왼,오른)위, 위
            hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
            hasWord(Boggle, index+1, y-1, x-1, str_vec); // 대각선(왼)위
            hasWord(Boggle, index+1, y-1, x+1, str_vec); // 대각선(오른)위
            hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
            hasWord(Boggle, index+1, y-1, x, str_vec); // 위
        }
    }
    
    else // 위쪽, 아래쪽 모두 칸이 있음
    {
        if(x-1 <= 0) // 왼쪽에 칸이 없는 경우
               {
                   // 기준의 칸으로부터 위, 대각선(오른)위, 오른
                   hasWord(Boggle, index+1, y-1, x, str_vec); // 위
                   hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
                   hasWord(Boggle, index+1, y-1, x+1, str_vec); // 대각선(오른)위
                   hasWord(Boggle, index+1, y+1, x+1, str_vec); // 대각선(오른)아래
                   hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
               }
               
               else if(x-1 >= 4) // 오른쪽에 칸이 없는 경우
               {
                   // 기준의 칸으로부터 위, 대각선(왼)위, 왼
                   hasWord(Boggle, index+1, y-1, x, str_vec); // 위
                   hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
                   hasWord(Boggle, index+1, y-1, x-1, str_vec); // 대각선(왼)위
                   hasWord(Boggle, index+1, y+1, x-1, str_vec); // 대각선(왼)아래
                   hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
               }
               
               else // 왼쪽, 오른쪽 모두에 칸이 있는 경우
               {
                   // 8방향 모두
                   hasWord(Boggle, index+1, y, x+1, str_vec); // 오른
                   hasWord(Boggle, index+1, y-1, x-1, str_vec); // 대각선(왼)위
                   hasWord(Boggle, index+1, y-1, x+1, str_vec); // 대각선(오른)위
                   hasWord(Boggle, index+1, y, x-1, str_vec); // 왼
                   hasWord(Boggle, index+1, y-1, x, str_vec); // 위
                   hasWord(Boggle, index+1, y+1, x, str_vec); // 아래
                   hasWord(Boggle, index+1, y+1, x-1, str_vec); // 대각선(왼)아래
                   hasWord(Boggle, index+1, y+1, x+1, str_vec); // 대각선(오른)아래
               }
    }
    
    if(index == str_vec.size())
    {
        std::cout<<"True!"<<'\n';
        return true;
    }
    
    else
    {
        return false;
    }
}

