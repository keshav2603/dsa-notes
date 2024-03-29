#include <iostream>
#include <stack>

int main()
{
    // Declare a stack of integers
    std::stack<int> intStack;

    // Push elements onto the stack
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Print the size of the stack
    std::cout << "Stack size: " << intStack.size() << "\n";

    // Access the top element without removing it
    std::cout << "Top element: " << intStack.top() << "\n";

    // Pop an element from the stack
    intStack.pop();

    // Check if the stack is empty
    if (intStack.empty())
    {
        std::cout << "Stack is empty.\n";
    }
    else
    {
        // Print the remaining elements in the stack
        std::cout << "Remaining elements: ";
        while (!intStack.empty())
        {
            std::cout << intStack.top() << " ";
            intStack.pop();
        }
        std::cout << "\n";
    }

    return 0;
}
