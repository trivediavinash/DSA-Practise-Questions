/*
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
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
#define mp make_pair
#define vp vector<pair<int,int>>


int main() {
    fast
    intt t;
    cin>>t;
    while(t--){
       intt n,s;
       cin>>n>>s;
       intt a[n];
       for(intt i=0;i<n;i++){
           cin>>a[i];
       }
       intt sum=0,j=0;
       bool flag=true;
       for(intt i=0;i<n;i++){
           sum+=a[i];
           while(sum>s){
              sum=sum-a[j];
              j++;
           }
             if(sum==s){
                cout<<j+1<<" "<<i+1<<endl;
                flag=false;
                break;
                }
           
           
          
         
       }
       if(flag){
       cout<<-1<<endl;
       }
        
    }
	return 0;
}