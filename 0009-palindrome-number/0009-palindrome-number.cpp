class Solution {
public:
    bool isPalindrome(int x) {
        long long n=x;;
        long long  dup=n;
        long long revnum=0;
 if(x<0) return false;
        while (n>0){
            int ld=n%10;
            revnum=(revnum*10) + ld;
            n=n/10;

        }

        return(dup==revnum);
            }
        };