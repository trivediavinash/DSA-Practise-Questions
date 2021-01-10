/*
Given an array, cyclically rotate an array by one.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. Then following line contains 'n' integers forming the array. 

Output:
Output the cyclically rotated array by one.

Constraints:
1<=T<=1000
1<=N<=1000
0<=a[i]<=1000

Example:
Input:
2
5
1 2 3 4 5
8
9 8 7 6 4 2 1 3

Output:
5 1 2 3 4
3 9 8 7 6 4 2 1
*/

1.
#include <bits/stdc++.h>
using namespace std;
#define intt long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);


int main() {
    fast
    intt t;
    cin>>t;
    while(t--){
      vector<int> v;
      intt n;
      cin>>n;
      intt a[n];
      for(intt i=0;i<n;i++){
          cin>>a[i];       
        
    } 
    
     int f=a[n-1];
     v.push_back(f);
     for(intt i=0;i<n-1;i++){
         v.push_back(a[i]);

     }
     for(auto it: v){
         cout<<it<<" ";
     }
    cout<<endl;
    }
	return 0;
}

2.

#include <bits/stdc++.h>
using namespace std;

#define intt long long

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);


int main() {#include <bits/stdc++.h>
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
     
    
     int t=a[n-1];
     for(intt i=n-1;i>0;i--){
        
         a[i]=a[i-1];
         //a[0]=t;

     }
     a[0]=t;
     for(intt i=0;i<n;i++){
          cout<<a[i]<<" ";       
        
    } 
     
    cout<<endl;
    }
	return 0;
}
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
     
    
     int t=a[n-1];
     for(intt i=n-1;i>0;i--){
        
         a[i]=a[i-1];
         //a[0]=t;

     }
     a[0]=t;
     for(intt i=0;i<n;i++){
          cout<<a[i]<<" ";       
        
    } 
     
    cout<<endl;
    }
	return 0;
}
