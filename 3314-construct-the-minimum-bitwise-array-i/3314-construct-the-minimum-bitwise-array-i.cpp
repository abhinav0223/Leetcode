class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            int best = INT_MAX;

            // Try removing each set bit
            for (int b = 0; b <= 31; b++) {
                if (p & (1 << b)) {
                    int x = p ^ (1 << b);  // turn off bit b
                    if ( (x | (x + 1)) == p ) {
                        best = min(best, x);
                    }
                }
            }

            if (best == INT_MAX) ans.push_back(-1);
            else ans.push_back(best);
        }

        return ans;
    }
};