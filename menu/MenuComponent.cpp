//
//  MenuComponent.cpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "MenuComponent.hpp"

void noFunction() {
    return;
}

MenuComponent::MenuComponent() {
    
    string = (char *) malloc(2 * sizeof(char));
    strcpy(string, "");
    
    setFunction();
    
}

MenuComponent::MenuComponent(const char * newString, void (*newFunction)(void)) {
    
    string = (char *) malloc(strlen(newString) * sizeof(char));
    strcpy(string, newString);
    
    setFunction(newFunction);
    
}

MenuComponent::MenuComponent(MenuComponent & mc) {
    
    const char * newStr = mc.getString();
    string = (char *) malloc( strlen(newStr) * sizeof(char));
    strcpy(string, newStr);
    
    setFunction(mc.getFunction());
    
}

MenuComponent::~MenuComponent() {
    
    free(string);
    string = nullptr;
    
}

void MenuComponent::setString(const char * newString) {
    
    string = (char *) realloc(string, strlen(newString));
    strcpy(string, newString);
    
}

void MenuComponent::setFunction(void (*newFunction)(void)) {
    
    function = newFunction;
    
}

const char * MenuComponent::getString() {
    
    return string;
    
}

void (*MenuComponent::getFunction())(void) {
    
    return function;
    
}

void MenuComponent::call() {
    
    function();
    
}
