class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int x = 1; x <= n; x++) {
            if (isGood(x)) count++;
        }
        return count;
    }
    
private:
    bool isGood(int x) {
        bool different = false;
        int temp = x;
        while (temp > 0) {
            int d = temp % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) different = true;
            temp /= 10;
        }
        return different;
    }
};