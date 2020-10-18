/*Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).

*/





#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define intt long long
#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)
#define vl vector<ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define mod 1000000007


int main() {
    fast
    intt t;
    cin>>t;
    while(t--){
        intt n;
        cin>>n;
        intt a[n];
        for(intt i=0;i<n;i++){
            cin>>a[i];
        }
      
        
        intt initial_sum  = 0;  
        initial_sum=accumulate(a, a+n, initial_sum); 
        intt left_sum=0;
        bool flag=true;
        for(intt i=0;i<n;i++){
           
            initial_sum-=a[i];
            if(left_sum==initial_sum){
                flag=false;
                cout<<i+1<<endl;
            }
             
            left_sum+=a[i];
             
        }
        if(flag){
      cout<< -1<<endl;
        }
    }
    //cout<<initial_sum;
    
  
	return 0;
}