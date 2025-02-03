class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> record;

        for (const string& op : ops) {
            if (op == "C") {
                if (!record.empty()) record.pop();
            } 
            else if (op == "D") {
                if (!record.empty()) record.push(2 * record.top());
            } 
            else if (op == "+") {
                int top1 = record.top(); record.pop();
                int top2 = record.top();
                record.push(top1); 
                record.push(top1 + top2);
            } 
            else {
                record.push(stoi(op)); 
            }
        }
        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }

        return sum;
    }
};
