#include <vector>

using namespace std;

void mergeSortedSplit(vector<int> &array, int s, int m, int e) {
  vector<int> temp;
  int i, j;
  i = s;
  j = m + 1;
  while (i <= m && j <= e) {
    if (array[i] <= array[j]) {
      temp.push_back(array[i]);
      ++i;
    } else {
      temp.push_back(array[j]);
      ++j;
    }
  }

  while (i <= m) {
    temp.push_back(array[i]);
    ++i;
  }
  while (j <= e) {
    temp.push_back(array[j]);
    ++j;
  }
  for (int i = s; i <= e; ++i)
    array[i] = temp[i - s];
}

void mergeSort(vector<int> &array, int s, int e) {
  if (s < e) {
    int m = (s + e) / 2;
    mergeSort(array, s, m);
    mergeSort(array, m + 1, e);
    mergeSortedSplit(array, s, m, e);
  }
}
