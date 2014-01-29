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

#include "Help.h"
int main(int argc, const char * argv[])
{
    using namespace help;
    std::string firstLine;
    std::getline (std::cin, firstLine);
    int n = std::stoi(firstLine);
    std::string line;
    Help * help = new Help();
    
    
    for(int i = 0; i < n; i++) {
        std::getline (std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> first{std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>{}};
        
        std::getline (std::cin, line);
        std::istringstream iss2(line);
        std::vector<std::string> second{std::istream_iterator<std::string>{iss2},
            std::istream_iterator<std::string>{}};
        if(first.size() != second.size()) {
            // Not same says, cant be equal
            std::cout << "-" << std::endl;
        }
        else {
            if(help->run(first, second)) {
                std::cout << first[0];
                for(int i = 1; i < first.size(); i++) {
                    std::cout << " " << first[i];
                }
                std::cout << std::endl;
            } else {
                std::cout << "-" << std::endl;
            }
        }
        
    }
    return 0;
}
