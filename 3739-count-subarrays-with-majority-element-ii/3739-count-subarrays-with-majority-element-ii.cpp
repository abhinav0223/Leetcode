class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (nums[i] == target ? 1 : -1);
        }
        vector<long long> sorted_vals(pre);
        sort(sorted_vals.begin(), sorted_vals.end());
        sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());

        int m = sorted_vals.size();
        vector<int> bit(m + 1, 0);

        auto update = [&](int pos) {
            for (++pos; pos <= m; pos += pos & (-pos)) bit[pos]++;
        };
        auto query = [&](int pos) {
            int res = 0;
            for (; pos > 0; pos -= pos & (-pos)) res += bit[pos];
            return res;
        };

        long long ans = 0;
        for (int j = 0; j <= n; j++) {
            int rank = lower_bound(sorted_vals.begin(), sorted_vals.end(), pre[j]) - sorted_vals.begin();
            ans += query(rank);
            update(rank);
        }

        return ans;
    }
};