class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0); 
        
        for (int i = n - 1; i >= 0; i--) {
            vector<long long> newCnt(k, 0);
            int r = nums[i] % k;
            newCnt[r] += 1; 
            for (int xp = 0; xp < k; xp++) {
                if (cnt[xp] == 0) continue;
                int nr = (int)(((long long)r * xp) % k);
                newCnt[nr] += cnt[xp];
            }
            for (int x = 0; x < k; x++) result[x] += newCnt[x];
            cnt = move(newCnt);
        }
        
        return result;
    }
};