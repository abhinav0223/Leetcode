

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int minimalAns = INT_MAX;
            bool found = false;

            for (int bit = 0; bit <= 30; bit++) {
                if (((num >> bit) & 1) == 1) {
                    int candidate = num & ~(1 << bit);

                    if (candidate < 0) continue;

                    if ((candidate | (candidate + 1)) == num) {
                        if (candidate < minimalAns) {
                            minimalAns = candidate;
                            found = true;
                        }
                    }
                }
            }

            if (found) {
                ans[i] = minimalAns;
            } else {
                ans[i] = -1;
            }
        }

        return ans;
    }
};
