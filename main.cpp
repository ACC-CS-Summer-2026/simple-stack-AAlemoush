/* *************************************************
* Name: Abdullah Alemoush
* Assignment: Stack ADT
* Purpose: Comprehensive testbed for the Stack class.
* ************************************************* */

#include "main.h"

int main() {
    /* **********************************
     * This function is the application driver. It thoroughly
     * tests all stack operations, states, and limits explicitly
     * and dynamically via random testing.
     *
     * @param na : na
     * @return (int) : application exit code
     * @exception na : na
     * @note Tests automatically scale based on STACK_SIZE.
     * **********************************/
    
    Stack myStack;
    int tempVal = 0;
    bool success = false;

    // Seed random number generator
    std::srand(std::time(0));

    std::cout << "==========================================\n";
    std::cout << "        STACK ADT EXPLICIT TESTING\n";
    std::cout << "        Max Stack Size: " << STACK_SIZE << "\n";
    std::cout << "==========================================\n\n";

    // ---------------------------------------------------------
    // Phase 1: Underflow state testing (Empty Stack)
    // ---------------------------------------------------------
    std::cout << "--- Phase 1: Underflow Testing ---\n";
    
    std::cout << "Checking isEmpty() on new stack: ";
    if(myStack.isEmpty()) std::cout << "PASS (Empty)\n"; else std::cout << "FAIL\n";

    std::cout << "Attempting to peek() empty stack: ";
    success = myStack.peek(&tempVal);
    if(!success) std::cout << "PASS (Underflow caught)\n"; else std::cout << "FAIL\n";

    std::cout << "Attempting to pop() empty stack: ";
    success = myStack.pop(&tempVal);
    if(!success) std::cout << "PASS (Underflow caught)\n"; else std::cout << "FAIL\n";
    std::cout << "\n";

    // ---------------------------------------------------------
    // Phase 2: Middle state testing (Filling the stack)
    // ---------------------------------------------------------
    std::cout << "--- Phase 2: Standard Operations & Filling ---\n";
    for(int i = 0; i < STACK_SIZE; i++) {
        success = myStack.push(i * 10);
        if(!success) {
            std::cout << "FAIL at pushing element " << i << "\n";
        }
    }
    std::cout << STACK_SIZE << " elements pushed.\n";
    
    std::cout << "Checking isEmpty() on full stack: ";
    if(!myStack.isEmpty()) std::cout << "PASS (Not empty)\n"; else std::cout << "FAIL\n";

    std::cout << "Checking peek() on full stack: ";
    success = myStack.peek(&tempVal);
    if(success && tempVal == (STACK_SIZE - 1) * 10) {
        std::cout << "PASS (Top is " << tempVal << ")\n";
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "\n";

    // ---------------------------------------------------------
    // Phase 3: Overflow state testing (Full Stack)
    // ---------------------------------------------------------
    std::cout << "--- Phase 3: Overflow Testing ---\n";
    std::cout << "Attempting to push() onto a full stack: ";
    success = myStack.push(999);
    if(!success) std::cout << "PASS (Overflow caught)\n"; else std::cout << "FAIL\n";
    std::cout << "\n";

    // ---------------------------------------------------------
    // Phase 4: Emptying the stack (Checking consistency)
    // ---------------------------------------------------------
    std::cout << "--- Phase 4: Emptying Stack ---\n";
    for(int i = 0; i < STACK_SIZE; i++) {
        success = myStack.pop(&tempVal);
        if(!success) {
            std::cout << "FAIL at popping element " << i << "\n";
        }
    }
    std::cout << STACK_SIZE << " elements popped.\n";
    
    std::cout << "Checking isEmpty() after full pop: ";
    if(myStack.isEmpty()) std::cout << "PASS (Empty)\n"; else std::cout << "FAIL\n";
    std::cout << "\n";


    // ---------------------------------------------------------
    // Phase 5: Dynamic Random Testing
    // ---------------------------------------------------------
    std::cout << "==========================================\n";
    std::cout << "        STACK ADT RANDOM TESTING\n";
    std::cout << "==========================================\n";
    
    // Scale tests linearly to the STACK_SIZE
    int numRandomTests = STACK_SIZE * 1000; 
    int pushCount = 0, popCount = 0, peekCount = 0;

    std::cout << "Running " << numRandomTests << " random operations...\n";

    for(int i = 0; i < numRandomTests; i++) {
        int operation = std::rand() % 3; // 0 = push, 1 = pop, 2 = peek
        
        if(operation == 0) {
            myStack.push(std::rand() % 100);
            pushCount++;
        } 
        else if (operation == 1) {
            myStack.pop(&tempVal);
            popCount++;
        } 
        else {
            myStack.peek(&tempVal);
            peekCount++;
        }
    }

    std::cout << "Random Test Summary:\n";
    std::cout << "Total Pushes Attempted: " << pushCount << "\n";
    std::cout << "Total Pops Attempted: " << popCount << "\n";
    std::cout << "Total Peeks Attempted: " << peekCount << "\n";
    
    // Final state check to ensure the stack hasn't corrupted
    std::cout << "\nFinal Stack Status: ";
    if(myStack.isEmpty()) {
         std::cout << "Valid (Empty)\n";
    } else {
         myStack.peek(&tempVal);
         std::cout << "Valid (Contains data, top is " << tempVal << ")\n";
    }

    std::cout << "\nAll testing complete.\n";

    return 0;
}