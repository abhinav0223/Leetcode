class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string half;
        int mid = -1;
        for (int i = 0; i < 26; i++) {
            half += string(cnt[i] / 2, 'a' + i);
            if (cnt[i] % 2) mid = i;
        }
        string res = half;
        if (mid != -1) res += char('a' + mid);
        string rev = half;
        reverse(rev.begin(), rev.end());
        res +=rev;
        return res;    }
};