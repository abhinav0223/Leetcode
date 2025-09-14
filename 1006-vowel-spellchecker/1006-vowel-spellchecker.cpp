class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;


        for (string word : wordlist) {
            string lower = toLower(word);
            string masked = maskVowels(lower);
            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = word;
            if (!vowelError.count(masked)) vowelError[masked] = word;
        }
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseInsensitive.count(lowerQ)) {
                ans.push_back(caseInsensitive[lowerQ]);
                continue;
            }
            string maskedQ = maskVowels(lowerQ);
            if (vowelError.count(maskedQ)) {
                ans.push_back(vowelError[maskedQ]);
                continue;
            }

            ans.push_back(""); // no match
        }
        return ans;
    }

private:
    string toLower(string s) {
        for (auto &c : s) c = tolower(c);
        return s;
    }

    string maskVowels(string s) {
        for (auto &c : s) {
            if (isVowel(c)) c = '*';
        }
        return s;
    }

    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
};