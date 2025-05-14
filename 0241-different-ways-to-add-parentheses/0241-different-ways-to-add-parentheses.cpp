
class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];

        vector<int> results;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') results.push_back(l + r);
                        else if (c == '-') results.push_back(l - r);
                        else if (c == '*') results.push_back(l * r);
                    }
                }
            }
        }
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        memo[expression] = results;
        return results;
    }
};
