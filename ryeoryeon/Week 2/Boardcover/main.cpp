//
//  main.cpp
//  Boardcover
//
//  Created by 이영현 on 2020/02/17.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int board_cover(int H, int W, vector<vector<char>> & board, int number);

int main(int argc, const char * argv[]) {
    // 게임판 덮기 (H X W 크기의 게임판)
    // 모든 흰 칸을 세 칸 짜리 L자 모양의 블록으로 덮으려고 한다.
    // 블록들은 자유롭게 회전 가능. 서로 겹치거나 검은 칸을 덮거나 게임판 밖으로 나가선 X
    // 결론 :: 게임판이 주어질 때, 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.
    
    int C; // 테스트 케이스의 수 (30 이하)
    int H,W; // 게임판의 크기. 각 값은 20 이하. (단, 흰 칸의 수는 50 이하)
    
    cin>>C;
    
    for(int a=0; a<C; a++)
    {
        cin>>H>>W;
        vector<vector<char>> board;
        board.assign(H,vector<char>(W,0));
        
        board_cover(H, W, board, 0);

    }
    
    return 0;
}

int board_cover(int H, int W, vector<vector<char>> & board, int number)
{
     
     for(int i=0; i<H; i++)
     {
         for(int j=0; j<W; j++)
         {
             cin>>board[i][j];
         }
     }
     
     // 기저 사례 :: L칸(3칸)으로 모두 덮어야 한다.
     // 흰 칸이 3의 배수가 아니면 바로 탈락!
     
     int white=0;
     
     for(int i=0; i<H; i++)
     {
         for(int j=0; j<W; j++)
         {
             if(board[i][j]=='.')
                 white++;
         }
     }
     
     if(white%3==0)
         return 0;
    
    else
    {
        //만약 게임판을 블록으로 덮게 된다면 덮은 부분을 까만색으로 바꾸게 되면 어떨까?
        //그런데 하얀 블록을 어떻게 회전시켜서 덮게 될지는 잘 모르겠다ㅠㅠ
    }
}
