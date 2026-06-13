class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (const string& word : words) {
            int total = 0;
            for (char c : word)
                total += weights[c - 'a'];
            result += (char)('z' - (total % 26));
        }
        return result;
    }
};