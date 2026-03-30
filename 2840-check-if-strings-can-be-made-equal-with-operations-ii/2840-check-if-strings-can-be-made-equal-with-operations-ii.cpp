class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int freq[2][26] = {};
        
        for (int i = 0; i < s1.size(); i++) {
            freq[i % 2][s1[i] - 'a']++;
            freq[i % 2][s2[i] - 'a']--;
        }
        
        for (int parity = 0; parity < 2; parity++)
            for (int c = 0; c < 26; c++)
                if (freq[parity][c] != 0)
                    return false;
        
        return true;
    }
};