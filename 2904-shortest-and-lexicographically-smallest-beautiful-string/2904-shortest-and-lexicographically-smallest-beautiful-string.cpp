class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') cnt++;
                if (cnt == k) {
                    string cand = s.substr(i, j - i + 1);
                    if (best.empty() || cand.size() < best.size() ||
                        (cand.size() == best.size() && cand < best)) {
                        best = cand;
                    }
                    break; 
                }
            }
        }
        return best;
    }
};