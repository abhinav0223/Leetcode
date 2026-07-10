class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });
        
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[idx[i]] = i;
        
        vector<long long> sortedNums(n);
        for (int i = 0; i < n; i++) sortedNums[i] = nums[idx[i]];
        
        vector<int> comp(n);
        int c = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i-1] > maxDiff) c++;
            comp[i] = c;
        }
        
        // farthest[i] = furthest index reachable in one hop from i (rightward)
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(sortedNums.begin(), sortedNums.end(), sortedNums[i] + maxDiff) - sortedNums.begin() - 1;
        }
        // make it monotonic (prefix max) so nxt[i] is furthest reachable considering all j<=i in same expanding front too
        for (int i = 1; i < n; i++) nxt[i] = max(nxt[i], nxt[i-1]);
        
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k-1][up[k-1][i]];
            }
        }
        
        vector<int> ans(queries.size());
        for (int qi = 0; qi < (int)queries.size(); qi++) {
            int u = queries[qi][0], v = queries[qi][1];
            if (u == v) { ans[qi] = 0; continue; }
            int pu = pos[u], pv = pos[v];
            if (comp[pu] != comp[pv]) { ans[qi] = -1; continue; }
            
            if (pu > pv) swap(pu, pv);
            
            int cur = pu;
            int steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            steps++; // final hop covers pv since nxt[cur] >= pv now
            ans[qi] = steps;
        }
        
        return ans;
    }
};