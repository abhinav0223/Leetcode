class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0.0;
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int l = rect[0];
            int w = rect[1];
            double diag = sqrt(1.0 * l * l + 1.0 * w * w);
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } 
            else if (fabs(diag - maxDiag) < 1e-9) { // diagonals equal
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
