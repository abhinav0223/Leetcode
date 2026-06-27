class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;
        
        int ans = 1; 
        if (freq.count(1)) {
            int c = freq[1];
            int candidate = (c % 2 == 0) ? c - 1 : c;
            ans = max(ans, candidate);
        }
        
        for (auto& entry : freq) {
            long long val = entry.first;
            if (val == 1) continue; 
            
            long long cur = val;
            int chainLen = 0;
            
            while (true) {
                long long next = cur * cur; 
                if (freq[cur] >= 2 && freq.count(next)) {
                    chainLen += 2; 
                    cur = next;      
                } else {
                    chainLen += 1;  
                    break;
                }
            }
            
            ans = max(ans, chainLen);
        }
        
        return ans;
    }
};