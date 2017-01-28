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
    MenuComponent(const char * newString, void (*newFunction)(void) = &noFunction);
    MenuComponent(MenuComponent & mc);
    
    ~MenuComponent();
    
    void setString(const char * newString);
    void setFunction(void (*newFunction)(void) = &noFunction);
    void (*getFunction())(void);
    const char * getString();
    
    void call();
    
};

#endif /* MenuComponent_hpp */
