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
    std::cout << Ans << '\n';
    
    return 0;
}

bool hasWord(const std::vector<std::vector<char>>& Boggle, int index, int y, int x, const std::vector<char>& str_vec)
{
    // 위치가 범위 밖일 때 예외처리
    if(x<=0 || x>4 || y<=0 || y>4)
        return false;
    
    // ex. index가 0 (처음상황)이라면 첫글자부터 보글판에서 뻑이 난 경우.
    if(Boggle[y-1][x-1] != str_vec[index])
        return false;
        
    // * 재귀 호출은 함수 내에서 쓸 땐 한번으로 끝내자.
    // * 어차피 방향은 정해져 있으므로 방향에 대한 배열을 정해놓기
    
    int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
    
    for(int d = 0; d < 8; d++)
    {
        int next_y = y + dy[d];
        int next_x = x + dx[d];
        
        if(hasWord(Boggle, index + 1, next_y, next_x, str_vec))
        {
            std::cout<<"Yeah!"<<'\n';
            return true;
        }
        
        /*
        if(index < str_vec.size() && hasWord(Boggle, index + 1, next_y, next_x, str_vec))
            return true;
         */
    }
    
    // 주위의 칸은 8칸이 될 수도 있고 더 적은 칸수가 남을 수도 있다.
    // 단, 왼쪽과 오른쪽 모두에 칸이 없을 수는 없고 위쪽과 아래쪽 모두에 칸이 없을 수는 없다.
    
    if(index==str_vec.size()-1)
    {
        std::cout<<"Yeah!"<<'\n';
        return true;
    }
    
    return false;
}

