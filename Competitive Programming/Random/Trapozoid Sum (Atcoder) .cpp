#include <bits/stdc++.h>
using namespace std;
#define intt long long 
 
 
int main() {
   intt n;
  cin>>n;
  intt sum=0;
  while(n--){
      intt a,b;
      cin>>a>>b;
      intt s1= b*(b+1)/2;
     // cout<<s1<<endl;
      intt x= a-1;
      intt s2= x*(x+1)/2;
     // cout<<s2<<endl;
      intt fsum= s1-s2;
     // cout<<fsum<<endl;
       sum +=fsum;
  }
  cout<<sum;
 
	return 0;
}