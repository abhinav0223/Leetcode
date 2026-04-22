class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& query : queries) {
            for (const string& dictWord : dictionary) {
                if (diffCount(query, dictWord) <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        
        return result;
    }

private:
    int diffCount(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != b[i]) count++;
            if (count > 2) return count;
        }
        return count;
    }
};