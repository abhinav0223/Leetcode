class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        int n = s.size();
        vector<int> answer(n, n);
        int last = -n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c)
                last = i;
            answer[i] = i - last;
        }
        last = 2 * n;
        for( int i=n-1;i>=0;i--){
            if (s[i] == c)
                last = i;
            answer[i] = min(answer[i], last - i);
        }
        return answer;
    }
};