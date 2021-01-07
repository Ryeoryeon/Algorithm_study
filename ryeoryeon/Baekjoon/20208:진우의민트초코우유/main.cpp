//
//  main.cpp
//  20208:진우의민트초코우유
//
//  Created by 이영현 on 2021/01/07.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> village;
int mintNum = 0;
int mintHP;

int HomeR, HomeC;

//함수를 쓸 때 굳이 많은 매개변수를 사용할 필요가 없습니다. 전역변수를 적극적으로 활용합니다.
//전역변수는 배열의 경우 모든 원소가 0, 숫자는 0, 문자열은 빈 문자열로 초기화된 상태로 선언되므로 초기화가 필요 없습니다.
//매개변수에서 vector의 사용을 주의합시다. 그 이유는 call by value이므로, vector가 깊은복사 됩니다.
//이러한 경우 메모리가 굉장히 낭비되므로, 되도록 reference를 씁시다. > call by reference
int findMint(int HP, int startR, int startC, int maxMint, int index, vector<int>& mintListR, vector<int>& mintListC)
{
    // maxMint == mintNum이 되면 더이상 함수가 돌아갈 필요 X
    if(maxMint == mintNum)
        return maxMint;
    
    // 방금 전의 반복문에서 조사했던 민초 제외
    if(index >= 0)
    {
        mintListR.erase(mintListR.begin() + index); //반복문 또는 재귀함수 내에서 erase와 같은 STL에 포함된 함수의 사용을 "주의" 합시다.
        mintListC.erase(mintListC.begin() + index); //그 이유는 시간복잡도 때문입니다. erase 함수는 시간복잡도가 O(N)입니다. 따라서 O(N)짜리 반복문에서 사용한다면 O(N^2)되는 마법이 벌어집니다.
    }                                               //erase를 사용하는 대신, check 배열을 만들어서 해당 원소가 쓰였나 안쓰였나를 체크합시다.
   
    for(int j=0; j < mintListR.size(); j++)
    {
        // 민트초코를 얻고 다시 돌아올 수 없는 경우
        int distance1 = abs(startR - mintListR[j]) + abs(startC - mintListC[j]);
        int distance2 = abs(HomeR - mintListR[j]) + abs(HomeC - mintListC[j]);  //이런 부분은 틀리거나 디버깅을 할 때 멘붕을 유발할 수 있으므로 함수로 만듭시다.
        int distance = distance1 + distance2;
        
        if((distance - mintHP) > HP)
            continue;
        
        return findMint((HP - distance1 + mintHP), mintListR[j], mintListC[j], maxMint + 1, j, mintListR, mintListC); //전위증감, 후위증감 연산자는 되도록 함수나 인덱스에 넣지 맙시다.
        //반복문 안에서 return을 쓰면 그냥 함수가 끝나버립니다.
        //maxMin 계속 증가, (maxMint + 1)
        //매개변수에 들어가는 애는, 되도록 수정 금지
    }
    
    // 이제 더이상 민트초코우유를 겟할 수 없는 경우
    return maxMint;
}
struct POS{
    int x, y;
};

int main(int argc, const char * argv[]) {
    
    // 순서대로 상하좌우
    // int dr[4] = {0, 1, 0, -1};
    // int dc[4] = {-1, 0, 1, 0};
    
    //cin과 cout을 쓰는 경우에는 밑의 코드 최소 두 줄, 최대 세 줄 추가합시다
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int villSize, HP, maxMint = 0;
    cin>>villSize>>HP>>mintHP;
    
    vector<int> mintListR;  //2차원의 위치를 표현하는 좌표는 굳이 따로 저장해야하지 않는다면, 구조체 등을 활용합시다.
    vector<int> mintListC;  //두 개를 따로 쓰게 되면, 배열을 수정하거나 하는 경우 의도치 않은 결과를 얻을 수 있습니다.
    village.assign(villSize, vector<int>(villSize, 0));
    for(int j=0; j<villSize; j++)   //후위증감 연산은 전위증감 연산보다 느립니다.
    {
        for(int k=0; k<villSize; k++)
        {
            cin>>village[j][k];
            if(village[j][k] == 2)
            {
                mintNum++;
                mintListR.push_back(j);
                mintListC.push_back(k);
            }
            
            else if(village[j][k] == 1)
            {
                HomeR = j;
                HomeC = k;
            }
        }
    }
    
    maxMint = findMint(HP, HomeR, HomeC, maxMint, -1, mintListR, mintListC);
    
    cout<<maxMint;
    //cout 사용시 endl을 사용하지 맙시다.`
    return 0;
}
