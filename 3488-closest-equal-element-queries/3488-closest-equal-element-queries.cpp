class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = (int)nums.size();

        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            auto& indices = indexMap[val];
            int m = (int)indices.size();

            if (m == 1) {
                answer.push_back(-1);
                continue;
            }

            int pos = (int)(lower_bound(indices.begin(), indices.end(), q)
                            - indices.begin());
            int minDist = INT_MAX;

            // Check predecessor
            int prevIdx = indices[(pos - 1 + m) % m];
            int d1 = abs(q - prevIdx);
            minDist = min(minDist, min(d1, n - d1));

            // Check successor
            int nextIdx = indices[(pos + 1) % m];
            int d2 = abs(q - nextIdx);
            minDist = min(minDist, min(d2, n - d2));

            answer.push_back(minDist);
        }

        return answer;
    }
};