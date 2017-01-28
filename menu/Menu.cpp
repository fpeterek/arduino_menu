//
//  Menu.cpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu() {
    
    _components.push_back( MenuComponent("Return") );
    
}

void Menu::addComponent(const MenuComponent & cmp) {
    
    size_t compLen = _components.length();
    
    _components.insert(cmp, compLen - ((compLen > 2) ? 2 : 1) );
    
}

void Menu::addComponent(const MenuComponent && cmp) {
    addComponent(cmp);
}

void Menu::loop() {
    
    while (true) {
        
        display();
        
        if (handleInput() == status::exit) {
            break;
        }
        
    }
    
}

status Menu::handleInput() {
    
    char input = read();
    
    if (input == 'w') {
        
        --selectedOption;
        
    } else if (input == 's') {
        
        ++selectedOption;
    }
    
    
    if (selectedOption < 0) {
        
        selectedOption = _components.length() - 1;
        
    } else if (selectedOption >= _components.length()) {
        
        selectedOption = 0;
        
    }
    
    if (input == '\n') {
        
        _components[selectedOption].call();
        return status::exit;
        
    }
    
    return status::noExit;
    
}

void Menu::display() {
    
    
    
}
