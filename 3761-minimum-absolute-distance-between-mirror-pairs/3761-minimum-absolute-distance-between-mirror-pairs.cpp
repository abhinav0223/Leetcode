class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> valToIndices;
        for (int i = 0; i < (int)nums.size(); i++) {
            valToIndices[nums[i]].push_back(i);
        }

        auto reverseNum = [](int x) -> int {
            int rev = 0;
            while (x > 0) {
                rev = rev * 10 + x % 10;
                x /= 10;
            }
            return rev;
        };

        int minDist = INT_MAX;

        for (int i = 0; i < (int)nums.size(); i++) {
            int r = reverseNum(nums[i]);

            auto it = valToIndices.find(r);
            if (it == valToIndices.end()) continue;

            const vector<int>& candidates = it->second;
            auto pos = upper_bound(candidates.begin(), candidates.end(), i);
            if (pos != candidates.end()) {
                int j = *pos;
                minDist = min(minDist, j - i); 
            }

        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};