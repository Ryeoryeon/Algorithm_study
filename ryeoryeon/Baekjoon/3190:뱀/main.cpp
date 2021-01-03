//
//  main.cpp
//  뱀
//
//  Created by 이영현 on 2021/01/04.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> board;
    int boardSize, apples, spendTime = 0;
    cin>>boardSize>>apples;
    board.assign(boardSize, vector<int>(boardSize, 0));
    
    for(int k=0; k<apples; k++)
    {
        int row, col;
        cin>>row>>col;
        board[row - 1][col - 1] = -1; // board에 1이 저장되어 있으면 자신의 몸, -1이 저장되면 사과
    }
    
    int directionNum;
    cin>>directionNum;
    
    vector<char> rotationList;
    int pastCount = 0;
    rotationList.push_back('X');
    for(int k=0; k<directionNum; k++)
    {
        int timeCount;
        char rotaType;
        
        cin>>timeCount>>rotaType;
        
        for(int l=pastCount; l<timeCount-1; l++)
        {
            rotationList.push_back('X'); // 'X'는 방향전환 X
        }
        rotationList.push_back(rotaType);
        pastCount = timeCount;
    }
    
    // 메인. rotationList만큼 돈다
    // 현재 위치
    int currentR = 0, currentC = 0;
    int tailR = 0, tailC = 0;
    
    // 현재 진행방향. 0이면 동쪽(0,1), 1이면 남쪽(1,0), 2면 서쪽(0,-1) 3이면 서쪽(-1,0)
    // int rotaR = 0, rotaC = 1;
    int rotaR[4] = {0, 1, 0, -1};
    int rotaC[4] = {1, 0, -1, 0};
    int currentRota = 0; // 동쪽부터 시작
    
    // 지난 위치를 검사하기 위한 뱀의 벡터
    vector<int> rHistory;
    vector<int> cHistory;
    
    for(int k=0; ; k++)
    {
        // 방향 전환
        if(k<rotationList.size()&&rotationList[k]!='X')
        {
            if(rotationList[k] == 'L')
            {
                currentRota--;
                if(currentRota < 0)
                    currentRota = 3;
            }
            
            else
            {
                currentRota++;
                if(currentRota >= 4)
                    currentRota = 0;
            }
        }
    
        
        // 현재 진행방향에 따라 몸 길이 늘리고, 사과 검사
        // 사과가 있다면 꼬리 위치 그대로, 자신의 몸 그쪽으로 넓히기
        currentR += rotaR[currentRota];
        currentC += rotaC[currentRota];
        
        // 벽과 부딪혔다면?
        if(currentR < 0 || currentC < 0 || currentR == boardSize || currentC == boardSize)
        {
            spendTime = k;
            break;
        }
        
        // 자신의 몸과 부딪혔다면?
        if(board[currentR][currentC] == 1)
        {
            spendTime = k;
            break;
        }
        
        rHistory.push_back(currentR);
        cHistory.push_back(currentC);
        
        if(board[currentR][currentC] < 0)
            board[currentR][currentC] = 1;
    
        // 사과가 없다면 꼬리 위치를 몸통의 다음 칸으로 이동하기
        else
        {
            board[tailR][tailC] = 0;
            tailR = rHistory[0];
            tailC = cHistory[0];
            rHistory.erase(rHistory.begin());
            cHistory.erase(cHistory.begin());
            board[currentR][currentC] = 1;
        }
        
        spendTime = k;
    }
    
    cout<<spendTime + 1;
    
    return 0;
}
