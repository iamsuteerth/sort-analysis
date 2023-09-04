#include <iostream>
#include <vector>
using namespace std;
int max(vector<int> &arr)
{
    int n = arr.size();
    int max_element = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_element)
            max_element = arr[i];
    return max_element;
}
void countSort(vector<int> &arr, int exp)
{
    int n = arr.size(), i;
    vector<int> output(n);
    vector<int> count(10, 0);

    for (i = 0 ; i < n ; i++)
        count[(arr[i] / exp) % 10]++;
  
    for (i = 1 ; i < 10 ; i++)
        count[i] += count[i - 1];

    for (i = n - 1 ; i >= 0 ; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
  
    for (i = 0 ; i < n ; i++)
        arr[i] = output[i];
}
void radixSort(vector<int> &arr)
{
    int n = arr.size();
    int m = max(arr);
    for (int exp = 1 ; m / exp > 0 ; exp *= 10)
        countSort(arr, exp);
}
