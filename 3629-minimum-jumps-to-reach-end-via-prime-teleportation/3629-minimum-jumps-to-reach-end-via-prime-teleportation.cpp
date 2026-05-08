class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> primeToIndices;
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            for (int p = 2; (long long)p * p <= val; p++) {
                if (val % p == 0) {
                    primeToIndices[p].push_back(j);
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1) primeToIndices[val].push_back(j);
        }

        vector<int> dist(n, -1);
        unordered_set<int> usedPrimes;
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (int ni : {i - 1, i + 1}) {
                if (ni >= 0 && ni < n && dist[ni] == -1) {
                    dist[ni] = dist[i] + 1;
                    if (ni == n - 1) return dist[ni];
                    q.push(ni);
                }
            }
            if (isPrime(nums[i]) && !usedPrimes.count(nums[i])) {
                usedPrimes.insert(nums[i]);
                for (int j : primeToIndices[nums[i]]) {
                    if (dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        if (j == n - 1) return dist[j];
                        q.push(j);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};