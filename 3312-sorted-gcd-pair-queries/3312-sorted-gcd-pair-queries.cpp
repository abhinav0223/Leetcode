class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<long long> freq(maxVal + 1, 0);
        for (int v : nums) freq[v]++;
        vector<long long> cntMultiple(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int m = g; m <= maxVal; m += g) {
                cntMultiple[g] += freq[m];
            }
        }
    
        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long c = cntMultiple[g];
            long long pairs = c * (c - 1) / 2;
            for (int m = 2 * g; m <= maxVal; m += g) {
                pairs -= exact[m];
            }
            exact[g] = pairs;
        }
        
        vector<long long> prefix(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            int lo = 1, hi = maxVal, res = maxVal;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] > q) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            answer.push_back(res);
        }
        
        return answer;
    }
};