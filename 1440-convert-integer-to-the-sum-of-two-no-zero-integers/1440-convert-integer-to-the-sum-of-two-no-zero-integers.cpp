bool isNoZero(int num) {
    while (num > 0) {
        if (num % 10 == 0)
         return false; 
        num /= 10;
    }
    return true;
}
 class Solution {
 public:
    vector<int> getNoZeroIntegers(int n) {
        int a,b;
          for (a = 1; a < n; a++) {
        b = n - a;
        if (isNoZero(a) && isNoZero(b)) {
            return {a, b};
        }
    }
    return {};
    }
};