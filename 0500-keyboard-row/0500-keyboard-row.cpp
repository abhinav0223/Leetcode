class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        unordered_map<char,int> row;
        for (char c : row1) row[c] = 1;
        for (char c : row2) row[c] = 2;
        for (char c : row3) row[c] = 3;
        vector<string> result;
        for (string word : words) {
            int currentRow = row[tolower(word[0])];
            bool valid = true;
            for (char c : word) {
                if (row[tolower(c)] != currentRow) {
                    valid = false;
                    break;
                }
            }
            if (valid) result.push_back(word);
        }
        return result;
    }
};
