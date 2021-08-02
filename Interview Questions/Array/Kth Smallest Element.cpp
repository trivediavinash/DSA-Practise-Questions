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

Method O(NLogN) O(1) 
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


2.  Worst-case performance	О(n2) -   
Best-case performance	О(n)    n + n/2 + n/4 + n/8 = n(1+ 1/2 + 1/4 ) = n 
Average performance	O(n)
class Solution{
    int lomutopartition(int  arr[],int left, int right){
        int i = left-1 , j = left ;
        int random = left + rand() % (right - left+1);
        swap(arr[right], arr[random]);
        int pivot = arr[right];
        while(j<right){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
            j++;
        }
        swap(arr[i+1],arr[right]);  
        return i+1;
    }
    
    

    int findKthLargest(int  arr[],int left, int right, int k) {
     
        while(true){
             int idx = lomutopartition(arr, left , right);
             if(idx == k-1) {
                 return arr[k-1];
                 break;
             }
            else if(idx < k-1)  left = idx+1;
            else if (idx>k-1)  right = idx-1;
        
            
        }
         return 0;
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        return findKthLargest( arr, l,  r ,  k ) ;
        
    }
};

3 .  O(Nlogk) O(Logk)
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;   //max heap
       
       
        for(int i = 0 ;i<=r ;i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();    
        }
        
        return pq.top();
    }
};

