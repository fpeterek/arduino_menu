//
//  io.cpp
//  menu
//
//  Created by Filip Peterek on 27/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "io.hpp"

char read() {
    
    std::string str;
    std::getline(std::cin, str);
    /* Append \n because std::getline trims it */
    str.append("\n");
    return str[0];
    
}
