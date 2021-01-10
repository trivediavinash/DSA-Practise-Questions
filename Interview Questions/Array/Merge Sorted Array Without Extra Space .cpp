/*
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

*/

1. O(M+N) O(M+N)

#include <bits/stdc++.h>
using namespace std;

void  mergeSortedArray(int arr1[] ,int arr2[], int n ,int m){
    
    vector<int>v;
    int j=0;
    int count=0;
    for(int i=0;i<n; ){
        if(arr1[i]<arr2[j]){
            v.push_back(arr1[i]);
            i++;
              
        }
        else{
            v.push_back(arr2[j]);
            j++;count++;
        }
        
    }
    
    for(int i=count;i<m;i++){
            v.push_back(arr2[i]);
             
        }

    for(auto x:v){
        cout<<x<<" ";
    }  
    
}

int main() {
    int n,m;
    cin>>n>>m;
    int arr1[n], arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    mergeSortedArray(arr1,arr2,n,m);
}
