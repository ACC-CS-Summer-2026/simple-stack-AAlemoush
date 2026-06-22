/* *************************************************
* Name: Abdullah Alemoush
* Assignment: Stack ADT
* Purpose: Implementation of the Stack class methods.
* ************************************************* */

#include "stack.h"

Stack::Stack() {
    /* *************************************************
    Default constructor for Stack. Initializes the stack
    to an empty state.

    @param na : na
    @return na : na
    @exception na : na
    @note When the constructor completes, the object should
          be fully ready for use.
    * ************************************************* */
    top = EMPTY;
}

Stack::~Stack() {
    /* *************************************************
    Destructor for Stack. Since static arrays are used,
    there is no dynamic memory to clean up.

    @param na : na
    @return na : na
    @exception na : na
    @note just a stub.
    * ************************************************* */
}

bool Stack::push(int val) {
    /* *************************************************
    Pushes an integer onto the top of the stack.

    @param (int) val: the value to push onto the stack
    @return (bool) : true if successful, false on overflow
    @exception na : na
    @note Checks for overflow before pushing.
    * ************************************************* */
    bool success = false;

    if (top < STACK_SIZE - 1) {
        top++;
        stack[top] = val;
        success = true;
    }
    
    return success;
}

bool Stack::pop(int* val) {
    /* *************************************************
    Removes and returns the top value from the stack via
    pass-by-reference.

    @param (int*) val : pointer to store the popped value
    @return (bool) : true if successful, false on underflow
    @exception na : na
    @note Checks for underflow before popping.
    * ************************************************* */
    bool success = false;

    if (!isEmpty()) {
        *val = stack[top];
        top--;
        success = true;
    }

    return success;
}

bool Stack::peek(int* val) {
    /* *************************************************
    Returns the top value from the stack without removing
    it via pass-by-reference.

    @param (int*) val : pointer to store the peeked value
    @return (bool) : true if successful, false on underflow
    @exception na : na
    @note Checks for empty stack before peeking.
    * ************************************************* */
    bool success = false;

    if (!isEmpty()) {
        *val = stack[top];
        success = true;
    }

    return success;
}

bool Stack::isEmpty() {
    /* *************************************************
    Checks if the stack is currently empty.

    @param na : na
    @return (bool) : true if empty, false otherwise
    @exception na : na
    @note Evaluates whether the top index is less than 0.
    * ************************************************* */
    return top == EMPTY;
}