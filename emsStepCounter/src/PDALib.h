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

typedef void (*ButtCallback)();
class ButtonMatrix{
    public:
    ButtonMatrix(int rows, int cols, int inputs[], int outputs[]);
    void assignButton(ButtCallback func, int x, int y);
    void process();
    void enable();
    void disable();
    protected:
    private:
    int _rows;
    int _cols;
    int** inputs;
    int** outputs;
    bool** _state;
    bool** _prevState;
    ButtCallback** _functionMatrix;
    void _updateState();
};
/**User should provide to the constructor the size of the butotn matrix and two arrays integers. One of size cols, and one of size rows
 *      Inputs should contian the input pins for the matrix in order from left to right and should be of size rows
 *      Outputs should contain the output pins for the matrix in order from top to bottom and should be of size cols
 * 
 * There are two matrix layers. The state matrix, and the function matrix.
 * When "enable" is run in config, a timer based interrupts system will be configured and start running. Everytime this timer overflows:
 *      1. Each button will be checked for it's state using the inputs and outputs matrices
 *      2. the state matrix will then be changed to match the current input state (true where a button is pressed, false elsewhere)
 *      3. the state matrix will be compared to the previous state matrix to check for rising edges
 *      4. where a rising edge if found, it will index the function matrix and call the corresponding function once
 * 
 * assignButton will take a funciton pointer and an index in the matrix and assign that function to that index in the function matrix
 *  unassigned indexes in the matrix will be nullPointers to avoid errors
 * 
 * 
*/
