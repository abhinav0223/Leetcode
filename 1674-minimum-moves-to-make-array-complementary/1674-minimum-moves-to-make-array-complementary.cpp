class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int lo    = min(a, b) + 1;
            int hi    = max(a, b) + limit;
            int exact = a + b;

            diff[lo]      -= 1;
            diff[hi + 1]  += 1;

            diff[exact]     -= 1;
            diff[exact + 1] += 1;
        }

        int ans     = 2 * (n / 2);
        int current = ans;

        for (int s = 2; s <= 2 * limit; s++) {
            current += diff[s];
            ans = min(ans, current);
        }

        return ans;
    }
};