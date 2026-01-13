class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;
        long double low = 1e18, high = -1e18;

        for (auto &sq : squares) {
            long double y = sq[1];
            long double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        long double target = totalArea / 2.0;

        auto belowArea = [&](long double Y) -> long double {
            long double area = 0;
            for (auto &sq : squares) {
                long double y = sq[1];
                long double l = sq[2];

                if (Y <= y) continue;
                else if (Y >= y + l) area += l * l;
                else area += l * (Y - y);
            }
            return area;
        };

        for (int iter = 0; iter < 80; iter++) {   
            long double mid = (low + high) / 2.0;
            if (belowArea(mid) >= target) high = mid;
            else low = mid;
        }

        return (double)high;
    }
};