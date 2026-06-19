class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0, cur = 0;
        for (int g : gain) {
            cur += g;
            maxAlt = max(maxAlt, cur);
        }
        return maxAlt;
    }
};