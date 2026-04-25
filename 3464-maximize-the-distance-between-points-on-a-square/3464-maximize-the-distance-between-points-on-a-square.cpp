class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        auto toPerim = [&](int x, int y) -> long long {
            if (y == 0) return x;
            if (x == side) return (long long)side + y;
            if (y == side) return 2LL * side + (side - x);
            return 3LL * side + (side - y);
        };

        long long P = 4LL * side;
        int n = (int)points.size();

        vector<long long> pos(n);
        for (int i = 0; i < n; i++)
            pos[i] = toPerim(points[i][0], points[i][1]);
        sort(pos.begin(), pos.end());

        auto check = [&](long long m) -> bool {
            for (int s = 0; s < n; s++) {
                long long cap = pos[s] + P - m;
                int cnt = 1;
                long long cur = pos[s];
                int i = s;

                while (cnt < k) {
                    long long need = cur + m;
                    if (need > cap) break;

                    int lo = i + 1, hi = s + n - 1, found = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) >> 1;
                        long long v = pos[mid % n] + (mid >= n ? P : 0LL);
                        if (v >= need) { found = mid; hi = mid - 1; }
                        else lo = mid + 1;
                    }
                    if (found == -1) break;

                    long long v = pos[found % n] + (found >= n ? P : 0LL);
                    if (v > cap) break;

                    cur = v;
                    i = found;
                    cnt++;
                }
                if (cnt == k) return true;
            }
            return false;
        };

        long long lo = 1, hi = 2LL * side, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (check(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return (int)ans;
    }
};