class Solution {
public:
    int countPrimeSetBits(int left, int right) {
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;
        for (int abhinav = left; abhinav <= right; abhinav++) {
            int setBits = __builtin_popcount(abhinav);
            if (primes.count(setBits)) {
                count++;
            }
        }
        return count;
    }
};