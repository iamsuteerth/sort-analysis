#include <vector>
using namespace std;

void insertion_sort(vector<int> &array) {
  int i, key, j;
  int n = array.size();

  for (i = 1; i < n; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 and array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}
