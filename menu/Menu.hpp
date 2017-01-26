//
//  Menu.hpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "MenuComponent.hpp"

class Menu {
    
    MenuComponent * _components;
    
public:
    
    Menu();
    Menu(unsigned int count, MenuComponent ...);
    
};


#endif /* Menu_hpp */
