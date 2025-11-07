
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0);

        // Step 1: prefix sum of stations
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stations[i];

        // Step 2: compute initial power for each city
        vector<long long> power(n, 0);
        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        // Step 3: binary search on possible minimum power
        long long low = 0, high = 1e14, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid, power, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAchieve(long long minPower, vector<long long> power, int r, long long k) {
        int n = power.size();
        vector<long long> added(n, 0);
        long long used = 0, windowAdd = 0;

        for (int i = 0; i < n; ++i) {
            if (i - r - 1 >= 0) windowAdd -= added[i - r - 1];
            power[i] += windowAdd;

            if (power[i] < minPower) {
                long long need = minPower - power[i];
                used += need;
                if (used > k) return false;

                int pos = min(n - 1, i + r);
                added[pos] += need;
                windowAdd += need;
                power[i] += need;
            }
        }
        return true;
    }
};
