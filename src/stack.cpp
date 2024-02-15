#include "stack.h"

#include <stdexcept>
#include <string>
#include <iostream>

namespace stack
{
    class Stack
    {
    private:
        int *stack_array;
        int size;
        int top_index;

    public:
        Stack(int n)
        {
            size = n;
            stack_array = new int[size];
            top_index = -1;
        }

        ~Stack()
        {
            delete[] stack_array;
        }

        void push(int value)
        {
            if (top_index >= size - 1)
            {
                throw std::overflow_error("Exceeded size (" + std::to_string(size) + ") of stack causing stack overflow");
            }
            else
            {
                top_index++;
                stack_array[top_index] = value;
            }
        }

        int pop()
        {
            if (top_index <= -1)
            {
                throw std::underflow_error("Underflowed because stack is empty");
            }
            else
            {
                top_index--;
                return stack_array[top_index];
            }
        }

        void printElements()
        {
            if (top_index >= 0)
            {
                std::cout << "Stack elements are: ";
                for (int i = top_index; i >= 0; i--)
                {
                    std::cout << stack_array[i];
                    if (i > 0)
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Stack is empty" << std::endl;
            }
        }
    };

    int main()
    {
        Stack myStack(5);

        myStack.push(15);
        myStack.push(25);
        myStack.push(35);
        myStack.push(45);
        myStack.push(55);

        myStack.printElements();

        return 0;
    }
}