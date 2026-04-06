#include <iostream>
#include "stack.h"
#include "node.h"

/** 
 * @file 
 * @brief Implementation of the constructors of the stack.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Initializes an empty stack.
 *
 * @details Top is set to nullptr, allowing the stack to be empty.
 */

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

/***********************************************************************/

/** 
 * @brief Clears the stack and releases all dynamically allocated resources.
 *
 * @details Deletes all the Nodes stored in the stack, thus releasing all allocated memory.
 */

template <typename T>
Stack<T>::~Stack()
{
    Node<T>* tmp = top;
        
    while (tmp != nullptr)
    {
        Node<T>* deleteNode = tmp;
        tmp = tmp->getNext();
        delete deleteNode;
    }
}

/***********************************************************************/

/** 
 * @brief Returns true if the stack has no Nodes, and false otherwise.
 * @return True if the stack has no Nodes. False if it has at least one Node.
 */

template <typename T>
bool Stack<T>::emptyStack() const
{
    return top == nullptr;
}

/***********************************************************************/

/** 
 * @brief Returns the number of Nodes in the stack by traversing the list.
 * @return The number of Nodes in the stack.
 */

template <typename T>
int Stack<T>::getSize() const
{
    int count = 0;
    Node<T>* tmp = top;

    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->getNext();
    }

    return count;
}

/***********************************************************************/

/** 
 * @brief Adds a new Node, with a value, to the top of the stack.
 * 
 * @details If the stack is empty, the new Node becomes the top of the stack.
 * Otherwise, the pointer of the new Node is set to the memory address of "top", 
 * then the new Node becomes the top.
 * 
 * @param newNode Memory address of the new Node.
 */

template <typename T>
void Stack<T>::push(Node<T>* newNode)
{
    if (emptyStack())
    {
        top = newNode;
    }
    else
    {
        newNode->insertNext(top);
        top = newNode;
    }
}

/***********************************************************************/

/** 
 * @brief Deletes the Node associated at the top of the stack.
 * 
 * @details If the stack is empty, then an error message is thrown.
 * Otherwise, a new pointer "deleteNode" that references to the top of the stack (pointer "top"),
 * while another variable stores the value stored in "top" to return it.
 * 
 * The top of the stack becomes the next Node. Finally, "deleteNode" is deleted.
 * 
 * @return The value stored in the deleted Node.
 */

template <typename T>
T Stack<T>::pop()
{
    if (emptyStack())
    {
        throw runtime_error("The stack has no elements yet!");
    }
    else
    {
        Node<T>* deleteNode = top;
        T nodeValue = top->getValue();

        top = top->getNext();
        delete deleteNode;
        return nodeValue;
    }
}


/***********************************************************************/

/** 
 * @brief ///< Returns the value of the Node at the top of the stack.
 * 
 * @details If the stack is empty, then an error message is thrown.
 * Otherwise, it returns the value inside "top", and in the main file (main.cpp) by
 * using getSize(), it also returns the number of Nodes in the stack. This can be
 * done through the option 3 of the menu.
 * 
 * @return The value stored in the top of the stack.
 */

template <typename T>
T Stack<T>::peek() const
{
    if (emptyStack())
    {
        throw runtime_error("The stack has no elements yet!");
    }
    else
    {
        return top->getValue();
    }
}