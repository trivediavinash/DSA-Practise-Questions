/*Find the first non-repeating element in a given array A of N integers.
Note: Array consists of only positive and negative integers and not zero.

Input:
The first line of input is an integer T, denoting the number of test cases. Each test case has subsequent two lines of input. First line is an integer N, denoting size of integer array A. Second line consists of N space separated integers of the array A.

Output:
For each testcase, print the required answer. If no such element exists, then print 0

Constraints:
1 <= T <= 100;
1 <= N <= 107;
-1016 <= Ai <= 1016
{Ai !=0 }

Example:
Input:
4
5
-1 2 -1 3 2
6
9 4 9 6 7 4
3
1 1 1
2
-3 2
Output:
3
6
0
-3
*/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define intt long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

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
       unordered_map<int ,int> m;
       for(intt i=0;i<n;i++){
           
               m[a[i]]++;
           
       }
       for(intt i=0;i<n;i++){
           if(m[a[i]]==1){
               cout<<a[i]<<endl;
               break;
           }
       }
     //  cout<<"-1";
       
        
    }
	return 0;
}




