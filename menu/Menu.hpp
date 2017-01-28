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
#include <cstdarg>

#include "MenuComponent.hpp"
#include "List.hpp"
#include "io.hpp"

enum class status {
    
    noExit,
    exit
    
};

class Menu {
    
    list<MenuComponent> _components;
    
    short selectedOption = 0;
    
    void display();
    status handleInput();
    
public:
    
    Menu();
    
    void addComponent(const MenuComponent & cmp);
    void addComponent(const MenuComponent && cmp);
    
    void loop();
    
};


#endif /* Menu_hpp */
