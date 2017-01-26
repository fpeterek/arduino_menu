//
//  MenuComponent.hpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef MenuComponent_hpp
#define MenuComponent_hpp

#include <cstdlib>
#include <cstring>
#include <cstdio>

void noFunction();

class MenuComponent {
    
    char * string;
    void (*function)(void);
    
public:
    
    MenuComponent();
    MenuComponent(char * newString, void (*newFunction)(void));
    
    void setString(char * newString);
    void setFunction(void (*newFunction)(void));
    const char * getString();
    
};

#endif /* MenuComponent_hpp */
