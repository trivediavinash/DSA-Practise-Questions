/*
Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2

 

Company Tags
 Adobe BrowserStack MakeMyTrip MAQ Software Microsoft Morgan Stanley Philips Samsung

*/

1.
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
//int multiply(int x,int res_size,int res[]);
int multiply(int x,int res_size,int res[]){
    int carry=0;
    
    
    // One by one multiply n with individual digits of res[] 
    for(int i=0;i<res_size;i++){
        int prod=res[i]*x+carry;
        // Store last digit of 'prod' in res[]  
        res[i]=prod%10;
        // Put rest in carry 
        carry=prod/10;
        
    }
     // Put carry in res and increase result size 
    while(carry){
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}
// This function finds factorial of large numbers 
// and prints them 
void factorial(int n){
    int res[MAX]; // Maximum number of digits in output 
    res[0]=1;
	int res_size=1;
	
	 // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
	for(int x=2;x<=n;x++){
	        res_size=multiply(x,res_size,res);
	    
	}
	for(int i=res_size-1;i>=0;i--){
	    cout<<res[i];
	} 
	cout<<endl;
   
}
int main() {
	int  t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    factorial(n);
	}
	return 0;
}