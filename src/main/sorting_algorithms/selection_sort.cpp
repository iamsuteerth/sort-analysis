#include <iostream>
#include <vector>
#include <utility>
void selection_sort(vector<int> &array){
    int n = array.size();
    int min_idx;
    for(int i = 0 ; i < n ; i++){
            min_idx = i;
            for(int j = i + 1 ; j < n ; j++){
                if(array[j] < array[min_idx])
                    min_idx = j;
            }
            if(min_idx != i)
                swap(array[min_idx], array[i]);
    }
}
