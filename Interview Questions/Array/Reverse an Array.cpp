/*
Given an array A of size N, print the reverse of it.

Input:
First line contains an integer denoting the test cases 'T'. T testcases follow. Each testcase contains two lines of input. First line contains N the size of the array A. The second line contains the elements of the array.

Output:
For each testcase, in a new line, print the array in reverse order.

Constraints:
1 <= T <= 100
1 <= N <=100
0 <= Ai <= 100

Example:
Input:
1
4
1 2 3 4
Output:
4 3 2 1

*/

1.
#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        
	    }
	    int j=n-1;
	    for(int i=0;i<n/2;i++){
	       swap(a[i],a[j]);
	       //swap(a[i],a[n-1-i]);
	       j--;
	        
	    }
	    for(int i=0;i<n;i++){
	        cout<<a[i]<<" ";
	     }
	     cout<<endl;
	    
	}
	return 0;
}
//Reverse an array without using subtract sign ‘-‘ anywhere in the code

1.Method 1:
1- Store array elements into a vector in C++.
2- Then reverse the vector using predefined functions.
3- Then store reversed elements into the array back.

Method 2:
1- Store array elements into a stack.
2- As the stack follows Last In First Out, so we can store elements from
top of the stack into the array which will be itself in a reverse manner.

Method 3:
1- In this method, the idea is to use a negative sign but by storing it into a variable.
2- By using this statement x = (INT_MIN/INT_MAX), we get -1 in a variable x.
3- As INT_MIN and INT_MAX have same values just of opposite signs, so on dividing them it will give -1.
4- Then ‘x’ can be used in decrementing the index from last.
