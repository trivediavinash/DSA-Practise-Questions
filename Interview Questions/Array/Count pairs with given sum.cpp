/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= K <= 108
1 <= Arr[i] <= 106

 

Company Tags
 Accolite Adobe Amazon FactSet Flipkart Goldman Sachs Hike

*/
Here we have hashed all the values once .
1. O(N) + O(N) O(1)

class Solution {
  public:
    int getPairsCount(int arr[], int n, int k) {
      int ans = 0;
      unordered_map < int, int > um;
      for (int i = 0; i < n; i++) {
        um[arr[i]]++;
      }
      for (int i = 0; i < n; i++) {
        int target = k - arr[i];
        if (um.count(target)) {
          if (target == arr[i]) { // for duplicate cases like 1 1 1 1   k = 2 
            um[arr[i]]--;
            ans += um[target];

          } else {
            ans += um[target]; //add the no of occurance of taget value 
            um[arr[i]]--; // decrease the count of occurance of current value as it is paired with the value and hence no need do consider it again in map .
          }
        }

      }
      return ans;
    }
};

2. O(N) O(1)

class Solution {
  public:
    int getPairsCount(int arr[], int n, int k) {
      int ans = 0;
      unordered_map < int, int > um;

      for (int i = 0; i < n; i++) {
        int target = k - arr[i];
        if (um.count(target)) {

          ans += um[target]; //counting the occurance of target 
          // um[arr[i]]--;
        }
        um[arr[i]]++; //hashing all the elements no matter what.
      }
      return ans;
    }
};





