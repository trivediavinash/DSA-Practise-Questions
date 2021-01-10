



/*Given a string S. Your task is to remove all duplicates characters from the string S

NOTE:
1.) Order of characters in output string should be same as given in input string.
2.) String S contains only lowercase characters ['a'-'z'].

input:
Input contain a single string S.

Output:
Print the string S with no any duplicate characters.

Constraints:
Test Files 1 to 5:
1<=|S|<=100
Test Files 6 to 10:
1<=|S|<=100000

Sample Output #1
hacker

Sample Output #1
hacker

Sample Input #2
hackerearth

Sample Output #2
hackert

Sample Input #3
programming

Sample Output #3
progamin 

*/

1. o(N*N)
#include<bits/stdc++.h>
using namespace std;
int main() {
   string a;
    cin>>a;
    for(int i=0;i<a.length();i++)
   {
     int fl=0;
     for(int j=0;j<i;j++) {
       if(a[i]==a[j]) fl=1;
     }
     if(fl!=1) cout<<a[i];
    }
return 0;
}


2.  o(N) 
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string a;
    cin>>a;
    unordered_set <long long > s;   //keep addresses of charector hashed we can declare like this also unordered_set < char > s;
    string ans;   
   for(int i=0;i<a.size();i++){
      s.insert(a[i]);
      }
    for(long long  i=0;i<a.size();i++){
          if(s.find(a[i])!=s.end()){
              s.erase(a[i]);
              ans+=a[i];     //cout<<a[i];  if we dont want to use extra space by string ans.
          }
         
      }
     cout<<ans<<endl;    //cout<<endl;
  
return 0;
}

