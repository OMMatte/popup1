//
//  main.cpp
//  popup-v1-help
//
//  Created by Mathias Lindblom on 2014-01-27.
//  Copyright (c) 2014 Mathias Lindblom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

#include "Piano.h"
int main(int argc, const char * argv[])
{
//    for(int day = 0; day < 100; day++) {
//        if(((day+2)/7)*7-2 == day) {
//            std::cout << std::to_string(day) << "NO" << std::endl;
//        } else if(((day+1)/7)*7-1 == day) {
//            std::cout << std::to_string(day) << "NO" << std::endl;
//        }else {
//            std::cout << std::to_string(day) << "YES" << std::endl;
//        }
//    }

    
    using namespace piano;
    
    Piano * piano = new Piano();
    std::string line;
    std::getline (std::cin, line);
    int n = std::stoi(line);
    
    for(int i = 0; i < n; i++){
        std::vector<int> pianoDates[100];
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> pianosAndMovers{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        int pianos = std::stoi(pianosAndMovers[0]);
        int movers = std::stoi(pianosAndMovers[1]);
        
        for(int p = 0; p < pianos; p++) {
            std::getline (std::cin, line);
            std::istringstream iss(line);
            std::vector<std::string> pianoMove{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            int firstDay = std::stoi(pianoMove[0]);
            int lastDay = std::stoi(pianoMove[1]);
            pianoDates[firstDay-1].push_back(lastDay-1);
        }
        
        if(piano->isFine(pianoDates, movers/2, pianos)) {
            std::cout << "fine" << std::endl;
        } else if(piano->isWeekend(pianoDates, movers/2, pianos)) {
            std::cout << "weekend work" << std::endl;
        } else {
            std::cout << "serious trouble" << std::endl;
        }
        
    }
    return 0;
}
