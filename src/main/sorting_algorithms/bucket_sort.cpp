#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(vector<int> &bucket) {
  int n = bucket.size();
  for (int i = 1; i < n; i++) {
    int key = bucket[i];
    int j = i - 1;
    while (j >= 0 && bucket[j] > key) {
      bucket[j + 1] = bucket[j];
      j--;
    }
    bucket[j + 1] = key;
  }
}

void bucketSort(vector<int> &arr) {
  int n = arr.size();

  if (n == 0)
    return;

  int max_val = *max_element(arr.begin(), arr.end());
  int min_val = *min_element(arr.begin(), arr.end());

  if (max_val == min_val)
    return;
  // Avoid division by zero

  int range = max_val - min_val + 1;
  int num_buckets = 10;

  if (range <= 0 || num_buckets <= 0)
    return;

  vector<vector<int>> buckets(num_buckets);
  for (int i = 0; i < n; i++) {
    int index = (arr[i] - min_val) * num_buckets / range;
    buckets[index].push_back(arr[i]);
  }

  for (int i = 0; i < num_buckets; i++) {
    insertionSort(buckets[i]);
  }

  int index = 0;
  for (int i = 0; i < num_buckets; i++) {
    for (int j = 0; j < buckets[i].size(); j++) {
      arr[index++] = buckets[i][j];
    }
  }
}
