class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> pts1, pts2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) pts1.push_back({i, j});
                if (img2[i][j] == 1) pts2.push_back({i, j});
            }
        }
        
        if (pts1.empty() || pts2.empty()) return 0;
        
        unordered_map<int, int> count;
        int best = 0;
        
        for (auto& p1 : pts1) {
            for (auto& p2 : pts2) {
                int dx = p1.first - p2.first;
                int dy = p1.second - p2.second;
                int key = (dx + n) * 100 + (dy + n);
                count[key]++;
                best = max(best, count[key]);
            }
        }
        
        return best;
    }
};