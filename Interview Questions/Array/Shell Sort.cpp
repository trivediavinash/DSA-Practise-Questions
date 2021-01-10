// Shell Sort    

#include <bits/stdc++.h>
using namespace std;

void shellsort(int a[],int n){
    for(int gap=n/2;gap>=1;gap=gap/2){
       for(int j=gap;j<n;j++){
           for(int i=j-gap; i>=0;i=i-gap){   //i=i-gap to swap elements before i  if any
               if(a[i+gap]>a[i]){
                   break;
               }
               swap(a[i+gap],a[i]);
           }
       }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    shellsort(a,n);
}
