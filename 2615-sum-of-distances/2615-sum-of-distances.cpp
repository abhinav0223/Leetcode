class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }
        
        for (auto& [val, indices] : indexMap) {
            int m = indices.size();
            if (m == 1) continue; 
            vector<long long> prefix(m + 1, 0);
            for (int k = 0; k < m; k++) {
                prefix[k + 1] = prefix[k] + indices[k];
            }
            
            for (int k = 0; k < m; k++) {
                long long idx = indices[k];
                
                long long leftSum  = idx * k - prefix[k];
                long long rightSum = (prefix[m] - prefix[k + 1]) - idx * (m - k - 1);
                
                arr[indices[k]] = leftSum + rightSum;
            }
        }
        
        return arr;
    }
};