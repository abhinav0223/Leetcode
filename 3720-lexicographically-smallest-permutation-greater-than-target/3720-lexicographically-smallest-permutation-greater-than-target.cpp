class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cur(26, 0);
        for (char c : s) cur[c - 'a']++;

        int bestPos = -1;
        char bestChar = 0;
        vector<int> bestCnt(26, 0);

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (cur[c] > 0) {
                    bestPos = i;
                    bestChar = 'a' + c;
                    bestCnt = cur;
                    bestCnt[c]--;
                    break;
                }
            }

            
            if (cur[t] == 0) break;
            cur[t]--;
        }

        if (bestPos == -1) return "";

        string res = target.substr(0, bestPos);
        res += bestChar;

        for (int c = 0; c < 26; c++) {
            res.append(bestCnt[c], 'a' + c);
        }

        return res;
    }
};