class Solution {
public:
    bool checkOnesSegment(string s) {
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1' && (i == 0 || s[i-1] == '0')) {
            count++;
            if (count > 1)
                return false;
        }
    }

    return true;
}
};