class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int maxLen = 0;

        for (int y : arr2) {
            while (y > 0) {
                if (prefixes.count(y)) {
                    int len = to_string(y).length();
                    maxLen = max(maxLen, (int)len);
                    break;
                }
                y /= 10;
            }
        }

        return maxLen;
    }
};