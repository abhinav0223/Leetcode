class Solution {
public:
    string getCanonicalForm(const string& word) {
        string even, odd;
        for (int i = 0; i < word.size(); ++i) {
            if (i % 2 == 0)
                even += word[i];
            else
                odd += word[i];
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        return even + "|" + odd;
    }

    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> uniqueForms;
        for (const string& word : words) {
            uniqueForms.insert(getCanonicalForm(word));
        }
        return uniqueForms.size();
    }
};
