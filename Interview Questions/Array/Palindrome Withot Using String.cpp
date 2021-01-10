//Palindrome Number 


1. integer overflow

int main() {
    long long n;
    cin>>n;
    long long x=n;
    
    int rev=0;
        while(x>0){
            rev=(rev*10)+(x%10);
            x=x/10;
           
        }
       // if(rev==n) {cout<<"true";}
        cout<<rev;
      //  else cout<<" false";
    
}

2. o(log base 10 x)  //since dividing by 10 each time.

class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
       // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x<0 || x%10==0 and x!=0){
            return false;
        }
        while(x>rev){
            rev=(rev*10)+(x%10);
            x=x/10;
            
        }
          // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        
      return rev==x || x==rev/10 ;
    }
};