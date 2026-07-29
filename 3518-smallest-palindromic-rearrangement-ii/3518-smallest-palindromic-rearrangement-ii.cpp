class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int half[26];
        for (int i = 0; i < 26; i++) half[i] = cnt[i] / 2;
        int halfLen = n / 2;

        int midChar = -1;
        for (int i = 0; i < 26; i++) if (cnt[i] % 2 == 1) midChar = i;

        const long long CAP = 2000000LL;

        auto countPerms = [&](int half_[26]) -> long long {
            int total = 0;
            for (int i = 0; i < 26; i++) total += half_[i];
            if (total == 0) return 1;

            long long res = 1;
            int rem = total;
            for (int i = 0; i < 26; i++) {
                int ni = half_[i];
                if (ni == 0) continue;
                long long c = 1;
                for (int j = 1; j <= ni; j++) {
                    c = c * (rem - ni + j) / j;
                    if (c > CAP) { c = CAP + 1; break; }
                }
                if (c > CAP) return CAP + 1;
                res = res * c;
                if (res > CAP) return CAP + 1;
                rem -= ni;
            }
            return res;
        };

        long long kk = k;
        string result(halfLen, ' ');
        int remaining[26];
        for (int i = 0; i < 26; i++) remaining[i] = half[i];

        for (int pos = 0; pos < halfLen; pos++) {
            bool placed = false;
            for (int c = 0; c < 26; c++) {
                if (remaining[c] == 0) continue;
                remaining[c]--;
                long long cnt_ = countPerms(remaining);
                if (kk <= cnt_) {
                    result[pos] = 'a' + c;
                    placed = true;
                    break;
                } else {
                    kk -= cnt_;
                    remaining[c]++;
                }
            }
            if (!placed) return "";
        }

        if (kk != 1) return "";

        string firstHalf = result;
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        string mid = (midChar != -1) ? string(1, 'a' + midChar) : "";

        return firstHalf + mid + secondHalf;
    }
};