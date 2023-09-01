#include <iostream>
#include <vector>
using namespace std;
// Standard Quicksort where pivot is middle element
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[(low + high) / 2];
    while (low <= high) {
        while (arr[low] < pivot)
            low++;
        while (arr[high] > pivot)
            high--;
        if (low <= high) {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }
    return low;
}
void quicksort_middle(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition_middle(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi, high);
    }
}
