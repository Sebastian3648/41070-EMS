#include "PDALib.h"

/**
 * @brief Class for easy menuing with I2C LCD Screens. 
 * @param screens > A linked list containing all screens for the menu. Normal menus (accessible by navigation) should be ranged in the order you wish for them to appear starting from index 0. Special access menu items (accesible by clicking on a menu item or through code) should occur in any order after the normal menus
 * @param menuableScreens > An integer representing the index at which navigational menuing should stop and special access menus begin
 */
Menu::Menu(LinkedList<MenuScreen> screens, int menuableScreens) : 
    screens_(screens), menuable_(menuableScreens){
    
}

void Menu::next(){
    if((currentMenu_+=1)<=menuable_){currentMenu_+=1;}
}

void Menu::previous(){
    if((currentMenu_-=1)>=0){currentMenu_-=1;}
}

void Menu::enter(){
    //If(screens_.get(currentMenu_).get(currentMenuOption_) != 0
    //I.e: if the current selection on the current menu has a specialMenu to access (it's special menu value is not zero), display that menu
}

void Menu::exit(){
    //Exit the current special menu back to the currentMenu
}