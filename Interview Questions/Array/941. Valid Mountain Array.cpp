/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < A[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
*/

1. t.c.=o(N)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0;
       
           while(i<n-1 && arr[i]<arr[i+1] ){
                i++;
              
            }    
           if(i==0 or i==n-1) return false;  //if first elemnt is peak or last elemnt is peak.
        
           while(i<n-1 && arr[i]>arr[i+1]){
                i++;
                   
            }
           
          
            
      
       return i==n-1;
       
    }
};

2.

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       /* Two people climb from left and from right separately.
        If they are climbing the same mountain,
        they will meet at the same point.  */
            
            
        int n = arr.size(), i = 0, j = n - 1;
        while (i  < n-1 && arr[i] < arr[i + 1]) i++;
        while (j > 0 && arr[j - 1] > arr[j]) j--;
        return i <n-1 && i == j && j >0;
   
       
    }
};