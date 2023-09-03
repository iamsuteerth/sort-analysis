#include <iostream>
#include <vector>
using namespace std;
void countSort(vector<int> &arr){
    int n = arr.size();
    int max = max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0);
    for (int i = 0 ; i < arr.size() ; i++) {
          count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0 ; i <= max_element ; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
