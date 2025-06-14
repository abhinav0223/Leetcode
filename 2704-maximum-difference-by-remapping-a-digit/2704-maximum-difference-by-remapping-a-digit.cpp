class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_val = num;
        int min_val = num;
        for (char d = '0'; d <= '9'; ++d) {
            string max_str = s;
            for (char &c : max_str) {
                if (c == d) c = '9';
            }
            max_val = max(max_val, stoi(max_str));
            string min_str = s;
            for (char &c : min_str) {
                if (c == d) c = '0';
            }
            min_val = min(min_val, stoi(min_str));
        }

        return max_val - min_val;
    }
};
