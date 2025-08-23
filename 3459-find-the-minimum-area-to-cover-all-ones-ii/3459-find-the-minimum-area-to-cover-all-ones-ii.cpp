class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> ones;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    ones.push_back({i, j});

        auto rectArea = [&](const vector<pair<int,int>>& pts) {
            if (pts.empty()) return 0;
            int minr = INT_MAX, maxr = INT_MIN, minc = INT_MAX, maxc = INT_MIN;
            for (auto &p : pts) {
                minr = min(minr, p.first);
                maxr = max(maxr, p.first);
                minc = min(minc, p.second);
                maxc = max(maxc, p.second);
            }
            return (maxr - minr + 1) * (maxc - minc + 1);
        };

        int ans = INT_MAX;

      
        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = c1 + 1; c2 < m; c2++) {
                vector<pair<int,int>> g1, g2, g3;
                for (auto &p : ones) {
                    if (p.second <= c1) g1.push_back(p);
                    else if (p.second <= c2) g2.push_back(p);
                    else g3.push_back(p);
                }
                if (g1.empty() || g2.empty() || g3.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(g3));
            }
        }
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1 + 1; r2 < n; r2++) {
                vector<pair<int,int>> g1, g2, g3;
                for (auto &p : ones) {
                    if (p.first <= r1) g1.push_back(p);
                    else if (p.first <= r2) g2.push_back(p);
                    else g3.push_back(p);
                }
                if (g1.empty() || g2.empty() || g3.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(g3));
            }
        }

        for (int c = 0; c < m; c++) {
            vector<pair<int,int>> left, right;
            for (auto &p : ones) {
                if (p.second <= c) left.push_back(p);
                else right.push_back(p);
            }
            if (left.empty() || right.empty()) continue;
            for (int r = 0; r < n; r++) {
                vector<pair<int,int>> g1, g2;
                for (auto &p : left) {
                    if (p.first <= r) g1.push_back(p);
                    else g2.push_back(p);
                }
                if (g1.empty() || g2.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(right));
            }
        
            for (int r = 0; r < n; r++) {
                vector<pair<int,int>> g1, g2;
                for (auto &p : right) {
                    if (p.first <= r) g1.push_back(p);
                    else g2.push_back(p);
                }
                if (g1.empty() || g2.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(left));
            }
        }
        for (int r = 0; r < n; r++) {
            vector<pair<int,int>> top, bottom;
            for (auto &p : ones) {
                if (p.first <= r) top.push_back(p);
                else bottom.push_back(p);
            }
            if (top.empty() || bottom.empty()) continue;
            for (int c = 0; c < m; c++) {
                vector<pair<int,int>> g1, g2;
                for (auto &p : top) {
                    if (p.second <= c) g1.push_back(p);
                    else g2.push_back(p);
                }
                if (g1.empty() || g2.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(bottom));
            }
            for (int c = 0; c < m; c++) {
                vector<pair<int,int>> g1, g2;
                for (auto &p : bottom) {
                    if (p.second <= c) g1.push_back(p);
                    else g2.push_back(p);
                }
                if (g1.empty() || g2.empty()) continue;
                ans = min(ans, rectArea(g1) + rectArea(g2) + rectArea(top));
            }
        }

        return ans;
    }
};