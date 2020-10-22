/*Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 or x==1){
            return x;
        }
        if(x==2){
            return 1;
        }
        for(long long int i=1;i<x ;i++){
            
           
               
               
            
                 if(i*i==x){
                     return i;
                 }
                 else if(i*i >x){
                     return i-1;
                 }
                   
        }    
          
       return -1;
        
    }
};

2 .log(n)
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 or x==1){
            return x;
        }
        if(x==2){
            return 1;
        }
        if(x==3){
            return 1;
        }
        int s=0,e=x-1;
        
        while(s<e){
            long long int mid=(s+e)/2;
            if(mid*mid==x ){
                return mid;
            }
            if(mid*mid>x and (mid-1)*(mid-1)<x){
                return mid-1;
            }
            else if(mid*mid>x){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
          
       return -1;
        
    }
};