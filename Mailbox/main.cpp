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

#include "Mailbox.h"
int main(int argc, const char * argv[])
{
    using namespace mailbox;
    
    Mailbox * mailbox = new Mailbox();
    std::string line;
    std::getline (std::cin, line);
    unsigned int n = std::stoi(line);
    
    int kMinMax[11][101][101] = {0};
    
    for(int i = 0; i < n; i++){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> mailboxAndCrackers{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        unsigned int mailboxes = std::stoi(mailboxAndCrackers[0]);
        unsigned int maxFireCrackers = std::stoi(mailboxAndCrackers[1]);
        if(mailboxes == 0 || maxFireCrackers == 0) {
            std::cout << std::to_string(0) << std::endl;
        } else {
            unsigned int result = mailbox->run(mailboxes, 1, maxFireCrackers, kMinMax);
            std::cout << std::to_string(result) << std::endl;
        }
    }
    return 0;
}
