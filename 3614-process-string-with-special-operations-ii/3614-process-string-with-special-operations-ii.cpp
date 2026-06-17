class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lengthBefore(n);
        long long curLen = 0;
        for (int i = 0; i < n; i++) {
            lengthBefore[i] = curLen;
            char c = s[i];
            if (c == '*') {
                if (curLen > 0) curLen--;
            } else if (c == '#') {
                curLen = curLen * 2;
            } else if (c == '%') {
            } else {
    
                curLen++;
            }
        }
        
        long long finalLen = curLen;
        
        if (k < 0 || k >= finalLen) {
            return '.';
        }
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long Lbefore = lengthBefore[i];
            
            if (c == '*') {
                continue;
            } else if (c == '#') {
                if (k < Lbefore) {
                    continue; 
                } else {
                    k = k - Lbefore;
                    continue;
                }
            } else if (c == '%') {
                k = Lbefore - 1 - k;
                continue;
            } else {
            
                if (k == Lbefore) {
                    return c; 
                } else {
                    continue; 
                }
            }
        }
        
        return '.';
    }
};