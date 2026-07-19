class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26];
        for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        
        string stack;
        bool inStack[26] = {false};
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;
            
            while (!stack.empty() && stack.back() > c && last[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return stack;
    }
};