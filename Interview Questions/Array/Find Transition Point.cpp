/*
You are given a sorted array containing only numbers 0 and 1. Find the transition point efficiently. The transition point is a point where "0" ends and "1" begins (0 based indexing).
Note that, if there is no "1" exists, print -1.
Note that, in case of all 1s print 0.

Example 1:

Input:
N = 5
C[] = {0,0,0,1,1}
Output: 3
Explanation: position 3 is 0 and next
one is 1, so answer is 3.
Example 2:

Input:
N = 4
C[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",so
the answer is -1.
Your Task:
The task is to complete the function transitionPoint() that takes array and N as input and returns the value of the position where "0" ends and "1" begins.

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 500000
0 ≤ C[i] ≤ 1

*/

1. 0.23 sec

// Function to find the transition point
int transitionPoint(int arr[], int n) {
   int s=0;
   int end=n-1;
   
   while(s<=end){
       int mid=s+(end-s)/2;
       if(arr[mid]==1 and arr[mid-1]==0 or mid==0 and arr[mid]==1){ //mid==0 && arr[mid]==1 for leftmost cases
           return mid;
           
       }
       else if (arr[mid]==1){
           end=mid-1;
       }
       else{
           s=mid+1;
       }
   
}
return -1;
}

2.  0.22 sec O(logN)

int transitionPoint(int arr[], int n) {
   int mid;
   int s = 0;
   int e = n-1;
while(s <= e)
{
      mid = s+(e - s)/2;
      if(arr[mid]==1 and arr[mid-1]==0  )
      return mid; 
      else if (arr[mid]==0 and arr[mid+1]==1) 
      return mid+1;
      
     else if (arr[mid]==1 and arr[mid-1]==1)
     e=mid-1; 
     else 
     s=mid+1;


}
return -1;
}

3. O(N) 0.28 sec

int transitionPoint(int arr[], int n) {
   
   for(int i=0;i<n;i++){
       if(arr[i]==1) {
           return i;
           break;
       }
   }
return -1;
}