class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int m = s.size();
        
        vector<int> nzIdx;
        vector<long long> prefixVal;
        vector<long long> prefixSum;
        prefixVal.push_back(0);
        prefixSum.push_back(0);
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                nzIdx.push_back(i);
                long long newVal = (prefixVal.back() * 10 + d) % MOD;
                prefixVal.push_back(newVal);
                prefixSum.push_back(prefixSum.back() + d);
            }
        }
        
        int k = nzIdx.size();
        vector<long long> pow10(k + 1);
        pow10[0] = 1;
        for (int i = 1; i <= k; i++) pow10[i] = (pow10[i-1] * 10) % MOD;
        
        int q = queries.size();
        vector<int> ans(q);
        
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            int a = lower_bound(nzIdx.begin(), nzIdx.end(), l) - nzIdx.begin();
            int b = upper_bound(nzIdx.begin(), nzIdx.end(), r) - nzIdx.begin();
            if (a >= b) {
                ans[i] = 0;
                continue;
            }
            long long xVal = (prefixVal[b] - prefixVal[a] * pow10[b - a] % MOD % MOD + MOD) % MOD;
            long long sumVal = prefixSum[b] - prefixSum[a];
            long long result = (xVal % MOD) * (sumVal % MOD) % MOD;
            ans[i] = (int)result;
        }
        
        return ans;
    }
};