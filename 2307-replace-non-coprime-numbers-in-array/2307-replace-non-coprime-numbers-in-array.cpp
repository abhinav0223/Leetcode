class Solution {
public:
        long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<long long> st;
    
    for (int num : nums) {
        st.push(num);
    
        while (st.size() > 1) {
            long long top1 = st.top();
            st.pop();
            long long top2 = st.top();
            
            if (gcd(top1, top2) > 1) {
                // Merge them
                long long merged = lcm(top1, top2);
                st.pop();
                st.push(merged);
            } else {
                // Not mergeable, push back top1 and break
                st.push(top1);
                break;
            }
        }
    }
    
    // Build the result from the stack
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }
    
    return result;
}
};