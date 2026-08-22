class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int num = n;
        while (num > 0) {
            int d = num % 10;
            sum += d;
            prod *= d;
            num /= 10;
        }
        return n % (prod+sum) == 0;
    }
};