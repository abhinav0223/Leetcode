class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> freq;
        freq.reserve(power.size() * 2);

        for (int v : power) freq[v]++;

        vector<long long> vals;
        vals.reserve(freq.size());
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        vector<long long> sumAtVal(vals.size());
        for (int i = 0; i < vals.size(); ++i)
            sumAtVal[i] = vals[i] * freq[vals[i]];

        int n = vals.size();
        vector<long long> dp(n, 0);
        dp[0] = sumAtVal[0];

        for (int i = 1; i < n; ++i) {
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            long long take = sumAtVal[i] + (j >= 0 ? dp[j] : 0LL);
            long long skip = dp[i - 1];
            dp[i] = max(skip, take);
        }

        return dp[n - 1];
    }
};