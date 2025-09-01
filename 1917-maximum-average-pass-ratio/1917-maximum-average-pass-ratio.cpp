struct Class {
    int pass, total;
    double gain() const {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};
struct Compare {
    bool operator()(const Class& a, const Class& b) {
        return a.gain() < b.gain();
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Class, vector<Class>, Compare> pq;
        
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }
        
        while (extraStudents--) {
            Class cur = pq.top(); pq.pop();
            cur.pass++;
            cur.total++;
            pq.push(cur);
        }
        
        double sum = 0.0;
        while (!pq.empty()) {
            Class c = pq.top(); pq.pop();
            sum += (double)c.pass / c.total;
        }
        
        return sum / classes.size();
    }
};
