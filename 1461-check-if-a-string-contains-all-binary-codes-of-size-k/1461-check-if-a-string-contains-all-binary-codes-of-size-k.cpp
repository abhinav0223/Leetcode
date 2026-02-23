class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1 << k;

        if (n < k + total - 1) return false;

        vector<bool> seen(total, false);
        int mask = total - 1;
        int hash = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                if (!seen[hash]) {
                    seen[hash] = true;
                    count++;
                    if (count == total) return true;
                }
            }
        }
        return false;
    }
};