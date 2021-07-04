//
//  main.cpp
//  2xn 타일링
//
//  Created by 이영현 on 2021/07/04.
//  Copyright © 2021 이영현. All rights reserved.
//

#include <iostream>

using namespace std;
int squareSize; // 문제의 n
unsigned long long int tileNum[1001] = {0, };

// 점화식은 n번째 = n-1번째 + n-2번째
// n번째는 n-1번째에서 2*1블럭 하나를 추가하는 경우와 n-2번째에서 1*2 블럭 두 개를 추가하는 경우로 구성되어 있기 때문

void tiling()
{
    for(int i = 3; i<=squareSize; ++i)
        tileNum[i] = (tileNum[i - 1] + tileNum[i - 2]) % 10007;
    
    cout<<tileNum[squareSize];
}

int main(int argc, const char * argv[]) {
    
    tileNum[1] = 1;
    tileNum[2] = 2;
    cin>>squareSize;
    tiling();
    
    return 0;
}
