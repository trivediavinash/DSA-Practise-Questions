/*
Given two strings s1 and s2, remove those characters from first string which are present in second string. Both the strings are different and contain only lowercase characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is s1,s1 is first string.
The second line of each test case contains s2,s2 is second string.

Output:

Print the modified string(s1). For each test case, print the output in a new line.

Constraints:

1 ≤ T ≤ 15
1 ≤ s2 < s1 ≤ 50

Example:

Input:
2
geeksforgeeks
mask
removeccharaterfrom
string

Output:
geeforgee
emovecchaaefom

Company Tags
 Amazon Zoho

*/

1. Using hashmap

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
	cin>>t;


	while(t--){
	    unordered_set<char> s;
	    string s1, s2, ans;
	    cin>>s1>>s2;
	    
	    for(int i=0;i<s2.length();i++){
	        s.insert(s2[i]);
	     }
	     for(int i=0;i<s1.length();i++){
	         if(s.count(s1[i])){
	             continue;
	         }
	         ans.push_back(s1[i]);    //cout<<s1[i]; without storing in ans string;
	     }
	     
	     
	    cout<<ans<<endl;       //cout<<endl;
	   
	}
	 return 0;
}