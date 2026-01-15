class Solution {
public:
    int  maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        auto maxGap = [&](vector<int>& bars) -> int {
            sort(bars.begin(), bars.end());
            int longest = 1, cur = 1;

            for (int i = 1; i < (int)bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    cur++;
                } else {
                    longest = max(longest, cur);
                    cur = 1;
                }
            }
            longest = max(longest, cur);

            // if longest consecutive removable bars = L, gap size becomes L+1
            return longest + 1;
        };

        int hg = maxGap(hBars);
        int vg = maxGap(vBars);

        int side = min(hg, vg);
        return side * side;
    }
};
