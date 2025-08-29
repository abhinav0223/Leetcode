class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddx = (n + 1) / 2;
        long long evenx = n / 2;
        long long oddy = (m + 1) / 2;
        long long eveny = m / 2;

        return oddx * eveny + evenx * oddy;
    }
};
