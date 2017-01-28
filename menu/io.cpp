//
//  io.cpp
//  menu
//
//  Created by Filip Peterek on 27/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "io.hpp"

char read() {
    
    char c;
    
    std::string str;
    std::getline(std::cin, str);
    c = str[0];
    
    return c;
    
}
