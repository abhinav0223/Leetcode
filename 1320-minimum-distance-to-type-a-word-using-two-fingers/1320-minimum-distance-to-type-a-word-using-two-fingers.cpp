
class Solution {
public:
    int minimumDistance(string word) {
      
        auto getPos = [](char c) -> pair<int,int> {
            int idx = c - 'A';
            return {idx / 6, idx % 6};
        };
        
        auto dist = [&](char a, char b) -> int {
            if (a == ' ') return 0; 
            auto [x1, y1] = getPos(a);
            auto [x2, y2] = getPos(b);
            return abs(x1 - x2) + abs(y1 - y2);
        };
        
        int n = word.size();
        
        const int INF = 1e9;
        const int UNPLACED = 26;
        vector<int> dp(27, INF);
        dp[UNPLACED] = 0; 
        
        for (int i = 0; i < n - 1; i++) {
            char cur = word[i];
            char nxt = word[i + 1];
            vector<int> ndp(27, INF);
            
            for (int j = 0; j <= 26; j++) {
                if (dp[j] == INF) continue;
                
                char other = (j == 26) ? ' ' : ('A' + j);
                int cost1 = dp[j] + dist(cur, nxt);
                int newOther1 = j; 
                ndp[newOther1] = min(ndp[newOther1], cost1);
                
               
                int cost2 = dp[j] + dist(other, nxt);
                int newOther2 = cur - 'A'; 
                ndp[newOther2] = min(ndp[newOther2], cost2);
            }
            
            dp = ndp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};