class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) { oddCount++; oddChar = i; }
        }
        if (oddCount > 1) return "";

        int half = n / 2;
        int halfCnt[26];
        for (int i = 0; i < 26; i++) halfCnt[i] = cnt[i] / 2;

        auto buildFromCounts = [&](int localCnt[26], int start, string &res) -> bool {
            for (int pos = start; pos < half; pos++) {
                bool placed = false;
                for (int c = 0; c < 26; c++) {
                    if (localCnt[c] > 0) {
                        res[pos] = 'a' + c;
                        localCnt[c]--;
                        placed = true;
                        break;
                    }
                }
                if (!placed) return false;
            }
            return true;
        };

        for (int i = half; i >= 0; i--) {
            int localCnt[26];
            for (int k = 0; k < 26; k++) localCnt[k] = halfCnt[k];
            bool ok = true;
            for (int p = 0; p < i; p++) {
                int c = target[p] - 'a';
                if (localCnt[c] <= 0) { ok = false; break; }
                localCnt[c]--;
            }
            if (!ok) continue;

            if (i == half) {
                string res(half, 'a');
                for (int p = 0; p < half; p++) res[p] = target[p];
                string full;
                full.resize(n);
                for (int p = 0; p < half; p++) full[p] = res[p];
                if (n % 2 == 1) full[half] = 'a' + oddChar;
                for (int p = 0; p < half; p++) full[n - 1 - p] = res[p];
                if (full > target) {
                    return full;
                }
                continue;
            }

            int tc = target[i] - 'a';
            for (int c = tc + 1; c < 26; c++) {
                if (localCnt[c] > 0) {
                    int tryCnt[26];
                    for (int k = 0; k < 26; k++) tryCnt[k] = localCnt[k];
                    tryCnt[c]--;
                    string res(half, 'a');
                    for (int p = 0; p < i; p++) res[p] = target[p];
                    res[i] = 'a' + c;
                    if (buildFromCounts(tryCnt, i + 1, res)) {
                        string full;
                        full.resize(n);
                        for (int p = 0; p < half; p++) full[p] = res[p];
                        if (n % 2 == 1) full[half] = 'a' + oddChar;
                        for (int p = 0; p < half; p++) full[n - 1 - p] = res[p];
                        return full;
                    }
                }
            }
        }

        return "";
    }
};