/*
Given a string S as input. You have to reverse the given string. 
*/
1. 

#include <iostream>
#include<string> 
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.length();
	    int mid=n/2;
	    for(int i=0;i<mid;i++){
	        swap(s[i],s[n-i-1]);
	    }
	    cout<<s<<endl;
	}
	return 0;
}

2.
#include <iostream>
#include<string> 
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int m=0;
	    int n=s.length()-1;
	     
	    while(m<n){
	        swap(s[m],s[n]);
	        m=m+1;
	        n=n-1;
	    }
	   
	    cout<<s<<endl;
	}
	return 0;
}