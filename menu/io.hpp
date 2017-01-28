//
//  io.hpp
//  menu
//
//  Created by Filip Peterek on 27/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef io_hpp
#define io_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
void print(const T & printable) {
    std::cout << printable << std::endl;
}

char read();


#endif /* io_hpp */
