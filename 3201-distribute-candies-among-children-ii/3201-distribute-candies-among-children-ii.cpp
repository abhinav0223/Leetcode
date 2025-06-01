class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long totalWays=0;
        for(int a=0;a<=n && a<=limit; ++a){
            int remaning=n-a;

            int minB=max(0,remaning-limit);
            int maxB=min(remaning,limit);

            if(minB<=maxB){
                totalWays +=(maxB-minB+1);
            }
        }
        return totalWays;

        
    }
};