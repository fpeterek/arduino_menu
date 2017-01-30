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
    
    _components.insert(cmp, compLen - ((compLen > 3) ? 2 : 1) );
    
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
        printingCounter ? --printingCounter : --startPrintingAt;
        
    } else if (input == 's') {
        
        ++selectedOption;
        printingCounter < 3 ? ++printingCounter : ++startPrintingAt;
        
    }
    
    if (selectedOption < 0) {
        
        selectedOption  = _components.length() - 1;
        startPrintingAt = selectedOption - 3;
        printingCounter = 3;
        
    } else if (selectedOption >= _components.length()) {
        
        /* I'm bored */
        selectedOption  ^= selectedOption;
        startPrintingAt ^= startPrintingAt;
        printingCounter ^= printingCounter;
        
    }
    
    if (input == '\n') {
        
        _components[selectedOption].call();
        
        if (selectedOption == _components.length() - 1) {
            return status::exit;
        }
        
    }
    
    return status::noExit;
    
}

char * Menu::prependAsterisk(const char * str) {
    
    char * newStr = (char *)malloc(strlen(str) + 2);
    strcpy(newStr + 2, str);
    newStr[0] = '*';
    newStr[1] = ' ';
    
    return newStr;
    
}

void Menu::display() {
    
    const size_t startAt = _components.length() <= 4 ? 0 : startPrintingAt;
    const size_t endAt = (startAt + 4 < _components.length()) ? startAt + 4 : _components.length();
    
    for (size_t i = startAt; i < endAt; ++i) {
        
        const char * str = _components[i].getString();
        
        if (i == selectedOption) {
            
            char * temp = Menu::prependAsterisk(str);
            print(temp);
            free(temp);
            
        } else {
            
            print(str);
            
        }
        
    }
    
}
