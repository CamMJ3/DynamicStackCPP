#include <iostream>
#include "node.h"
#include "stack.h"

/** 
 * @file 
 * @brief The complete program of the dynamic stack.
 * Includes a menu function so that the user may input any desired value.
 *
 * @details Option 1 allows the user to input any value of type int.
 * Option 2 allows the user to delete the Node at the top of the stack.
 * Option 3 allows the user to view the value at the top of the stack and its size.
 * Option 4 allows the user to exit the program.
 */

int menu();
using namespace std;

int main()
{
    Stack<int> stack; ///< Initializes a stack of type int.

    while (true)
	{

		switch (menu())
		{
		case 1:
        {
            int value;
			cout << "\nWhat value is to be stored in the new Node?: ";
            cin >> value;

            stack.push(new Node<int>(value));
            cout << "\nThe node has been added with the value of " << value << "!";
			break;
        }
		case 2:
        {
            try ///< Attempts to delete the top of the stack.
            {
                cout << "\nThe value stored in the top of the stack is: " << stack.pop();
                cout << "\nThe top of the stack has been deleted!";
            }
            catch(const std::exception& e) ///< Sends an message if an error occurs.
            {
                std::cerr << e.what() << '\n';
            }

            break;
        }
        case 3:
        {
            try ///< Attempts to retrieve the value in top of the stack, as well as the stack's size.
            {
                cout << "\nThe value stored in the top of the stack is: " << stack.peek();
                cout << "\nThe number of Nodes in the stack is: " << stack.getSize();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n'; ///< Sends an message if an error occurs.
            }

            break;
        }
        case 4:
        {
			cout << "\nExiting the program...";
			exit(0);
			break;
        }
        }
    }
}

/***********************************************************************/

/** 
 * @brief Menu that manages user input.
 *
 * @details Returns an option to the main function.
 */

int menu()
{
    int option;
	do
	{
		cout << "\n\n\n\t--- MENU! ---";
		cout << "\n1) Push.\n";
		cout << "2) Pop.\n";
		cout << "3) Peek.\n";
		cout << "4) Exit.\n";
		cout << "\n--> Choose an option: ";
		cin >> option;
	} while (option < 1 || option > 4);
	return option;
}

/***********************************************************************/

/** 
 * @page Tests
 * @brief Execution of the Stack program.
 * @section stack_test Test results
 * 
 * The following images show the execution of the Stack program in the terminal,
 * including the functions of Push, Pop, and Peek.
 * 
 * \image latex sTest1.png "Stack execution! (Part 1)"
 * \image html sTest1.png
 * 
 * \image latex sTest2.png "Stack execution! (Part 2)"
 * \image html sTest2.png
 */