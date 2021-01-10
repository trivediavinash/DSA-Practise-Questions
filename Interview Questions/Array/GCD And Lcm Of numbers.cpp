/*

GCD of two numbers

A , B
A=3, B=6

1. O(N) Sc

#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B;
    cin>>A>>B;
    vector<int>v;
	    int n=max(A,B);
        
	  for(int i=1;i<=n;i++){
	        if(A%i==0 and B%i==0){
	            v.push_back(i);
	        }
	    }
          
	      cout<<*max_element(v.begin(),v.end());  
          return 0;
}

2. T.C.==O(log(min(A,B))  Recursive. 
We are making Smaller no to smaller by doing moduls ,swapping  numbers on each call to ensure smaller no is processed  on each call.

class Solution
{
	public:
    int gcd(int A, int B) 
	{  
	   if(B==0){
        return A;
    }
    else{
        return gcd(B,A%B);
    }
   
	} 
};

2.Iterative 
 // Worst case -when two fibonacci no are passed  O(logn)...best case =when numbers are divisible by each other completly O(1)
int gcd(int A, int B) 
	{  
	   while(B){  //While B not become Zero.
        
            A=A%B;
           swap(A,B);

    }
    return A;


/////////////////////////////////////////////////////////////////////////////////////////////




#include <iostream>
using namespace std;

//Recusive Extended Eucleadean  for coprime numbers .
int extendedEucleadean(int a,int b, int &x, int &y){   //Pass by refrence.
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEucleadean(b, a%b, x1, y1);  //Calculating coefficient of every function call.
    x=y1;                  //Each time calculating coeff and assigning it to x and y.
    y=x1-y1*(a/b);
    return d;
}

//Eucledean ALgo
int eucledeanGcd(int a, int b) 
	{  
	   if(b==0){
        return a;
    }
    else{
        return eucledeanGcd(b,a%b);
    }
   
	} 

//LCM 
int lcm (int a, int b) {
    return a / eucledeanGcd(a, b) * b;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b,x,y;
        cin>>a>>b;
        cout<<eucledeanGcd(a,b)<<" "<<lcm(a,b)<<endl;
    //cout<<extendedEucleadean(a,b,x,y)<<endl;
        
    }
}