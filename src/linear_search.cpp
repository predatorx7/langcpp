#include "linear_search.h"

#include <iostream>

namespace linear_search
{
    int search(int array[], int array_size, int query)
    {
        for (int i = 0; i < array_size; i++)
        {
            if (array[i] == query)
            {
                return i;
            }
        }
        return -1;
    }

    int main()
    {
        int array[] = {5, 6, 7, 8, 9, 10};
        int query = 10;
        int array_size = sizeof(array) / sizeof(int);
        int index_of_query = search(array, array_size, query);
        if (index_of_query < 0)
        {
            std::cout << "Could not find '" << query << "' in the array" << std::endl;
        }
        else
        {
            std::cout << "Found index of '" << query << "' in the array at index " << index_of_query << std::endl;
        }
        return 1;
    }
}