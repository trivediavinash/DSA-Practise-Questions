/*
Kth smallest element 
Medium Accuracy: 58.64% Submissions: 100k+ Points: 4
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.
Testcase 2: 4th smallest elemets in the given array is 15.

*/

Method 
1.
#include <iostream>

#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
		    cin>>arr[i];
		    
		    
		    
	     }
	     int k;
		 cin>>k;
	     sort(arr,arr+n);
	   cout<<arr[k-1]<<endl;
	     
	}
	return 0;
}




Faltu


#include <iostream>
#include<climits>
#include <algorithm>
using namespace std;

int partition (int arr[],  int l, int r)
{
  l=0;
  //r=n-1;
  int i= l -1;
  int pivot =arr[r];
  
  for(int j=l;j<=r-1;j++){
      if(arr[j]<pivot){
          i++;
          swap(arr[i],arr[j]);
        }
  }
  swap(arr[i+1],arr[r]);
  return i+1;
}

int kthSmallest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of  
    // elements in array 
    if (k > 0 && k <= r - l + 1) { 
  
        // Partition the array around last  
        // element and get position of pivot  
        // element in sorted array 
        int index = partition(arr, l, r); 
  
        // If position is same as k 
        if (index - l == k - 1) 
            return arr[index]; 
  
        // If position is more, recur  
        // for left subarray 
        if (index - l > k - 1)  
            return kthSmallest(arr, l, index - 1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, index + 1, r,  
                            k - index + l - 1); 
    } 
  
} 
  

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
		    cin>>arr[i];
		    
		    
		    
	     }
	     int k;
		 cin>>k;
	 
	     cout<<kthSmallest(arr, 0,   n-1,  k)<<endl;
	}
	return 0;
}