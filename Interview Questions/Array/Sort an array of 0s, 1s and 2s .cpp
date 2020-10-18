/*
Sort an array of 0s, 1s and 2s 
Easy Accuracy: 48.12% Submissions: 100k+ Points: 2
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.

*/
1. Python Solution 

t=int(input())
while(t>0):
    t=t-1
    n=int(input())
    lst=list(map(int,input().split()))
    l1=[]
    l2=[]
    l3=[]
    for i in lst:
        if(i==0):
            l1.append(i)
        elif(i==1):
            l2.append(i)
        else:
            l3.append(i)
    s=l1+l2+l3
    #x=str(s)
   # ans=" ".join(x)
    for j in s:
        print(j,end=" ")
    print()    

 2 .Most Optimized DUtch Flag Algorithm o(N) ,o(1) 

#include <bits/stdc++.h>
using namespace std;
#define intt long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);



int main() {
    IOS
    int t;
    cin>>t;
    while(t--){
        intt n;
        cin>>n;
        intt a[n];
        for(intt i=0;i<n;i++){
            cin>>a[i];
        }

      int low=0;
      int mid=0;
      int high=n-1;
      while(mid<=high){
          if(a[mid]==0){
              swap(a[mid],a[low]);
              mid++;
              low++;
              
          }
          else if(a[mid]==2){
              swap(a[mid],a[high]);
              high--;
              
          }
          else{
              mid++;
              
          }
          
      }
       for(intt i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
            
       
    }
    return 0;
}

3.Method  Two pass counting sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int c1=0;
      int c2=0;
      int c3=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
          if(nums[i]==0){
              c1++;
          }
          else if(nums[i]==1){
              c2++;
          }
          else{
              c3++;
          }
      }
        
        
        
       
        
        
        
    int i = 0; 
  
     
    while (c1 > 0) { 
        nums[i++] = 0; 
        c1--; 
    } 
  
   
    while (c2> 0) { 
        nums[i++] = 1; 
        c2--; 
    } 
  
    
    while (c3 > 0) { 
        nums[i++] = 2; 
        c3--; 
    } 
        
        
        
        
    }
};

4. 0ms as compared to using while loop for modify the array.

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int c1=0;
      int c2=0;
      int c3=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
          if(nums[i]==0){
              c1++;
          }
          else if(nums[i]==1){
              c2++;
          }
          else{
              c3++;
          }
      }
        
        
        
       
        
    int index=0; 
        
    for(int i=0;i<c1;i++){
        nums[index++]=0;
    }
    for(int i=0;i<c2;i++){
        nums[index++]=1;
    }
    for(int i=0;i<c3;i++){
        nums[index++]=2;
    }
       
       
        
        
        
        
    }
};

    