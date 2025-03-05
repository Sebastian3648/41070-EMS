#include <Arduino.h>
#include <LinkedList.h>

class Menu{
    public:
    Menu(LinkedList<MenuScreen> screens, int menuableScreens);
    void next();
    void previous();
    void enter();
    void exit();
    protected:
    private:
    int menuable_;
    int currentMenu_ = 0;
    int currentSpecial_ = 0;
    int currentMenuOption = 0;
    int numScreens_;
    LinkedList<MenuScreen> screens_;
};

class MenuScreen{
    public:
    MenuScreen(String options[], int specialIndex[]);
    MenuScreen(String option, int &variable, int inc, void (*function)() = nullptr);
    protected:
    private:
    void (*function_)();
};