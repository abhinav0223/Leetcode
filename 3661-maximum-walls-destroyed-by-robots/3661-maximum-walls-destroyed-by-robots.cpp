class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return robots[a] < robots[b];
        });

        vector<int> sortedWalls = walls;
        sort(sortedWalls.begin(), sortedWalls.end());

        auto countWalls = [&](long long lo, long long hi) -> int {
            if (lo > hi) return 0;
            auto l = lower_bound(sortedWalls.begin(), sortedWalls.end(), (int)lo);
            auto r = upper_bound(sortedWalls.begin(), sortedWalls.end(), (int)hi);
            return (int)(r - l);
        };


        vector<long long> leftLo(n), leftHi(n), rightLo(n), rightHi(n);
        vector<int> leftCount(n), rightCount(n);

        for (int i = 0; i < n; i++) {
            int  ri   = idx[i];
            long pos  = robots[ri];
            long dist = distance[ri];

            long prev = (i > 0)     ? (long)robots[idx[i - 1]] : LLONG_MIN;
            long next = (i < n - 1) ? (long)robots[idx[i + 1]] : LLONG_MAX;

            leftLo[i]  = max(pos - dist, prev + 1);
            leftHi[i]  = pos;
            rightLo[i] = pos;
            rightHi[i] = min(pos + dist, next - 1);

            leftCount[i]  = countWalls(leftLo[i],  leftHi[i]);
            rightCount[i] = countWalls(rightLo[i], rightHi[i]);
        }

        vector<long long> dp(2);
        dp[0] = leftCount[0];
        dp[1] = rightCount[0];

        for (int i = 1; i < n; i++) {
            vector<long long> ndp(2);

            long long oLo = max(rightLo[i - 1], leftLo[i]);
            long long oHi = min(rightHi[i - 1], leftHi[i]);
            int overlap = (oLo <= oHi) ? countWalls(oLo, oHi) : 0;

            ndp[0] = max(dp[0] + leftCount[i],
                         dp[1] + leftCount[i] - overlap);

           
            ndp[1] = max(dp[0] + rightCount[i],
                         dp[1] + rightCount[i]);

            dp = ndp;
        }

        return (int)max(dp[0], dp[1]);
    }
};