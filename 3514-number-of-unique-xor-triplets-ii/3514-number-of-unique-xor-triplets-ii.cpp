class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXV = 2049; 
        vector<bool> present(MAXV, false);
        for (int v : nums) present[v] = true;

        vector<int> V;
        for (int v = 0; v < MAXV; v++)
            if (present[v]) V.push_back(v);
        vector<bool> S2(MAXV, false);
        for (int a : V)
            for (int b : V)
                S2[a ^ b] = true;
        vector<bool> S3(MAXV, false);
        for (int x = 0; x < MAXV; x++) {
            if (!S2[x]) continue;
            for (int c : V)
                S3[x ^ c] = true;
        }

        int count = 0;
        for (int x = 0; x < MAXV; x++)
            if (S3[x]) count++;

        return count;
    }
};