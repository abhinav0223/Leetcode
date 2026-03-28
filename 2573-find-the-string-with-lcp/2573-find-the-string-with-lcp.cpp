class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        
        char nextChar = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] != ' ') continue;
            if (nextChar > 'z') return "";
            word[i] = nextChar++;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (word[j] != ' ' && word[j] != word[i]) return "";
                    word[j] = word[i];
                }
            }
        }
        

        vector<vector<int>> computed(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    computed[i][j] = 1 + computed[i + 1][j + 1];
                } else {
                    computed[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computed[i][j] != lcp[i][j]) return "";
            }
        }
        
        return word;
    }
};