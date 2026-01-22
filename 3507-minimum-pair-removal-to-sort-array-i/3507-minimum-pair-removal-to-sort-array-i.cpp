class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int n = nums.size();
            int idx = 0;
            int bestSum = nums[0] + nums[1];

            for (int i = 1; i < n - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < bestSum) {
                    bestSum = s;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }
};
