#include "linked_list.h"

#include <iostream>

namespace linked_list
{
    // A linked list node
    class Node
    {
    public:
        int data;
        Node *next;
    };

    /* Given a reference (pointer to pointer)
   to the head of a list and an int, inserts
   a new node on the front of the list. */
    void push(Node **head_ref, int new_data)
    {
        // 1. Allocate node
        Node *new_node = new Node();

        // 2. Put in the data
        new_node->data = new_data;

        // 3. Make next of new node as head
        new_node->next = (*head_ref);

        // 4. Move the head to point to the
        //    new node
        (*head_ref) = new_node;
    };

    // This function prints contents of
    // linked list starting from head
    void print(Node *node)
    {
        std::cout << "Printing linked list: ";
        while (node != NULL)
        {
            std::cout << " " << node->data;
            node = node->next;
        }
        std::cout << std::endl;
    }

    int main()
    {
        Node *head = NULL;
        push(&head, 4);
        print(head);
        push(&head, 2);
        print(head);
        push(&head, 7);
        print(head);
        push(&head, 9);
        print(head);
        push(&head, 5);
        print(head);
        return 0;
    }
}