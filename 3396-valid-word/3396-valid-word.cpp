class Solution {
public:
    bool isValid(const string& word) {  // <-- changed name here
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) return false;

            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
