class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        int count = 0;
        
        function<void(string&)> backtrack = [&](string& current) {
            if (current.size() == n) {
                count++;
                if (count == k) result = current;
                return;
            }
            
            for (char c : {'a', 'b', 'c'}) {
                if (current.empty() || current.back() != c) {
                    current.push_back(c);
                    backtrack(current);
                    if (!result.empty()) return; 
                    current.pop_back();
                }
            }
        };
        
        string curr = "";
        backtrack(curr);
        return result;
    }
};