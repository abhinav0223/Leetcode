class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
    
    long long lcmll(long long a, long long b, long long cap) {
        long long g = gcdll(a, b);
        long long res = a / g;
        if (res > cap / b) return cap + 1;
        return res * b;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int subsets = 1 << n;
        vector<long long> lcmSub(subsets, 1);
        
        long long hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        for (int mask = 1; mask < subsets; mask++) {
            int lsb = mask & (-mask);
            int idx = __builtin_ctz(lsb);
            long long prevLcm = lcmSub[mask ^ lsb];
            if (prevLcm > hi) {
                lcmSub[mask] = hi + 1; 
            } else {
                lcmSub[mask] = lcmll(prevLcm, (long long)coins[idx], hi);
            }
        }
        
        auto countUpTo = [&](long long x) -> long long {
            long long count = 0;
            for (int mask = 1; mask < subsets; mask++) {
                int bits = __builtin_popcount(mask);
                long long l = lcmSub[mask];
                if (l > x) continue;
                long long cnt = x / l;
                if (bits % 2 == 1) count += cnt;
                else count -= cnt;
            }
            return count;
        };
        
        long long lo = 1;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countUpTo(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};