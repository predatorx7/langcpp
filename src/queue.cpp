#include "queue.h"

#include <stdexcept>
#include <string>
#include <iostream>

namespace queue
{
    class Queue
    {
    private:
        int *queue;
        int size;
        int front_index;
        int rear_index;

    public:
        Queue(int n)
        {
            size = n;
            queue = new int[size];
            front_index = -1;
            rear_index = -1;
        }

        ~Queue()
        {
            delete[] queue;
        }

        void insert(int value)
        {
            if (rear_index == size - 1)
            {
                throw std::overflow_error("Exceeded size (" + std::to_string(size) + ") of queue causing queue overflow");
            }
            else
            {
                if (front_index == -1) {
                    front_index = 0;
                }
                rear_index++;
                queue[rear_index] = value;
            }
        }

        int remove()
        {
            if (front_index == - 1 || front_index > rear_index)
            {
                throw std::underflow_error("Underflowed because queue is empty");
            }
            else
            {
                front_index++;
                return queue[front_index];
            }
        }

        void printElements()
        {
            if (front_index != -1)
            {
                std::cout << "Queue elements are: ";
                for (int i = front_index; i <= rear_index; i++)
                {
                    std::cout << queue[i];
                    if (i < rear_index)
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Queue is empty" << std::endl;
            }
        }
    };

    int main()
    {
        Queue myQueue(5);

        myQueue.insert(12);
        myQueue.insert(50);
        myQueue.insert(30);
        myQueue.insert(46);
        myQueue.insert(55);

        myQueue.printElements();

        return 0;
    }
}