//
//  List.cpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "List.hpp"

out_of_range::out_of_range(const char * newMessage) {
    
    message = (char*)malloc( strlen(newMessage) * sizeof(char) );
    strcpy(message, newMessage);
    
}

out_of_range::~out_of_range() {
    
    free(message);
    message = nullptr;
    
}

const char * out_of_range::what() const throw() {
    
    return message;
    
}
