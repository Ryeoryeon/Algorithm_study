//
//  string_split.cpp
//  Boggle_game
//
//  Created by 이영현 on 2020/02/03.
//  Copyright © 2020 이영현. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <vector>

std::vector<char> string_split(const std::string str)
{
    std::vector<char> strArr;
    
    char *buffer = new char[1000];
    strcpy(buffer, str.c_str()); // strcpy와 c_str을 사용해 C타입으로 변경 해 줘야 한다.

    int i = 0;
    while(buffer[i] != NULL) {
        strArr.push_back((buffer[i]));
        i++;
    }

    //for(int i=0; i<strArr.size(); i++) std::cout << strArr[i] << "\n";

    return strArr;
}


std::vector<std::string> string_space_split(const std::string str)
{
    std::vector<std::string> strArr;
    
    char *buffer = new char[1000];
    strcpy(buffer, str.c_str()); // strcpy와 c_str을 사용해 C타입으로 변경 해 줘야 한다.

    // 문자열 자르기
    char *tok = strtok(buffer, " "); // 문자열 자르는 함수
    
    while(tok != NULL) {
        strArr.push_back(std::string(tok));
        tok = strtok(NULL, " ");
    }

    // 확인
    for(int i=0; i<strArr.size(); i++) std::cout << strArr[i] << "\n";

    return strArr;
}
