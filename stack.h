/* *************************************************
* Name: Abdullah Alemoush
* Assignment: Stack ADT
* Purpose: Class definition for a static integer stack.
* ************************************************* */

#ifndef CLASSES_STACK_H
#define CLASSES_STACK_H

#define STACK_SIZE 10

class Stack {

    public:
    /**********************
    Constructors/Destructor
    ***********************/
    Stack();
    ~Stack();

    /**********************
    Getters/Accessors
    ***********************/
    bool peek(int*);
    bool isEmpty();

    /**********************
    Setters/Mutators
    ***********************/
    bool push(int);
    bool pop(int*);

    /**********************
    Printing
    ***********************/

    private:
    /**********************
    Methods
    ***********************/

    /**********************
    Attributes
    ***********************/
    int stack[STACK_SIZE];
    int top;

};

#endif //CLASSES_STACK_H