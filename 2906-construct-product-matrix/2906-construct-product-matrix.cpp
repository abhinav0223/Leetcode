class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = n * m;
        const int MOD = 12345;

        
        vector<long long> prefix(total + 1, 1), suffix(total + 1, 1);


        for (int i = 0; i < total; i++) {
            int r = i / m, c = i % m;
            prefix[i + 1] = (prefix[i] * (grid[r][c] % MOD)) % MOD;
        }
        for (int i = total - 1; i >= 0; i--) {
            int r = i / m, c = i % m;
            suffix[i] = (suffix[i + 1] * (grid[r][c] % MOD)) % MOD;
        }

        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < total; i++) {
            int r = i / m, c = i % m;
           
            p[r][c] = (prefix[i] * suffix[i + 1]) % MOD;
        }

        return p;
    }
};