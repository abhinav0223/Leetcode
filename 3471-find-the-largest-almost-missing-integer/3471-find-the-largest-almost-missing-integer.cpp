class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        for (int x : nums) {
            if (x <= ans) continue;
            int cnt = 0;
            for (int i = 0; i + k <= n; i++) {
                bool found = false;
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) { found = true; break; }
                }
                if (found) cnt++;
                if (cnt > 1) break;
            }
            if (cnt == 1) ans = max(ans, x);
        }
        return ans;
    }
};