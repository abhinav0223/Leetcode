class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> result;

        for (int num = 100; num <= 998; num += 2) { // only even numbers
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> temp_freq = freq;
            temp_freq[d1]--;
            temp_freq[d2]--;
            temp_freq[d3]--;

            if (temp_freq[d1] >= 0 && temp_freq[d2] >= 0 && temp_freq[d3] >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
