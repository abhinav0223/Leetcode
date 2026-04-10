class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < (int)nums.size(); i++)
            indices[nums[i]].push_back(i);

        int result = INT_MAX;

        for (auto& [val, idx] : indices) {
            if (idx.size() < 3) continue;
            for (int i = 0; i + 2 < (int)idx.size(); i++) {
                int dist = 2 * (idx[i + 2] - idx[i]);
                result = min(result, dist);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};