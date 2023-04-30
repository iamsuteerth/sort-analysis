// This is the good old optimized bubble sort
#include <iostream>
#include <vector>
void bubble_sort(vector<int> &array)
{
    int i, j, temp, n = array.size();
    bool flag = false;
    for (i = 0; i < n; i++)
    {
        flag = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                flag = true;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}
