class Solution {
public:
    bool isInside(int x, int y, int x1, int y1, int x2, int y2) {
        return (x1 <= x && x <= x2 && y2 <= y && y <= y1);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int Ax = points[i][0], Ay = points[i][1];
                int Bx = points[j][0], By = points[j][1];

                // A must be upper-left of B
                if (Ax <= Bx && Ay >= By) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int Cx = points[k][0], Cy = points[k][1];

                        // Check if point k lies inside/on rectangle A-B
                        if (isInside(Cx, Cy, Ax, Ay, Bx, By)) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) count++;
                }
            }
        }

        return count;
    }
};
