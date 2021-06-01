/*
Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consist of three lines. The first line of each test case contains two space separated integers N and M, where N is the size of array A and M is the size of array B. The second line of each test case contains N space separated integers denoting elements of array A. The third line of each test case contains M space separated integers denoting elements of array B.

Output:
Correspoding to each test case, print the count of union elements of the two arrays.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N + M).

*/

1. Using Unordered_set (implemented as hashtable O(1) constant lookup and insert.can be done with map also
 #include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);


int main() {
      fast
      int t;
      cin>>t;
      unordered_set<int>s;
      vector<int> v;
  while(t--){
     
    int n ,m;
    cin>>n>>m;
    int a[n] ,b[m];
     
      
      for(int i=0;i<n;i++){
        
        cin>>a[i];
        s.insert(a[i]);
         
          
     }
     for(int j=0;j<m;j++){
        
         cin>>b[j];
         s.insert(b[j]);
     }  
  
    cout<<s.size();
    s.clear();
    cout<<endl;
       
        
   
     
   
   }
	return 0;
}


// IN case of distinct elements in array 

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int i=0, j=0, ans=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                ans++;
                i++;j++;
            }
            else if (a[i]>b[j]){
                j++;
            }
            else i++;
        }
        return (n-ans)+(m-ans)+ans;
    }
};

