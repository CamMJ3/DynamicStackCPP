#pragma once
#include <string>
#include "node.h"

/** 
 * @file
 * @brief Defines the structure of the Stack.
 * Its structure consists of a pointer called "top".
 *
 * @details A stack is a linear data structure that follows the LIFO (Last-in, First-out) method,
 * thus making the core of its functions the last element, or in this case Node, added to the stack.
 * This file defines the constructors of the functions of the stack.
 */

template <typename T>
class Stack
{
    private:
    
        Node<T>* top; ///< Points to the last Node added to the stack (its top).
    
    public:
    
        Stack(); ///< Initializes an empty stack.
        ~Stack(); ///< Clears the stack and releases all dynamically allocated resources.

        bool emptyStack() const; ///< Returns true if the stack has no Nodes, and false otherwise.
        int getSize() const; ///< Returns the number of Nodes in the stack by traversing the list.

        void push(Node<T>* data); ///< Adds a new Node, with a value, to the top of the stack.
        T pop(); ///< Deletes the Node associated at the top of the stack.

        T peek() const; ///< Returns the value of the Node associated at the top of the stack.

};

#include "../src/stack.cpp" 