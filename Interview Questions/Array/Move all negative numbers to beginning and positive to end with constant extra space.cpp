/*

An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.

*/

1.

#include <bits/stdc++.h>

using namespace std;
#define intt long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {
  fast
  intt t;
  cin >> t;

  while (t--) {

    intt n;
    cin >> n;
    intt a[n];
    for (intt i = 0; i < n; i++) {
      cin >> a[i];
    }
    intt j = 0, i = 0;
    while (j < n) {
      if (a[j] < 0) {
        swap(a[i], a[j]);
        i++, j++;
      } else j++;
    }
    for (intt i = 0; i < n; i++) {
      cout << a[i] << " ";

    }
    cout << endl;

  }
  return 0;
}
