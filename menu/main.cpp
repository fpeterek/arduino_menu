//
//  main.cpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include <iostream>

#include "List.hpp"
#include "Menu.hpp"

static Menu menu;
static Menu submenu;


void test() {
    std::cout << "Test" << std::endl;
}

void showSubmenu() {
    submenu.loop();
}

void addItem() {
    submenu.addComponent(MenuComponent("Test"));
}

int main(int argc, const char * argv[]) {

    
    menu.addComponent(MenuComponent("Print Test", test));
    menu.addComponent(MenuComponent("Show submenu", showSubmenu));
    menu.addComponent(MenuComponent("Nothing"));
    menu.addComponent(MenuComponent("Nothing again"));
    menu.addComponent(MenuComponent("I hope this works"));
    menu.addComponent(MenuComponent("Menu Component"));
    menu.addComponent(MenuComponent("Nothing again"));
    menu.addComponent(MenuComponent("I hope this works"));
    menu.addComponent(MenuComponent("Last item"));
    
    submenu.addComponent(MenuComponent("Nothing"));
    submenu.addComponent(MenuComponent("Add component", addItem));
    
    menu.loop();
}
