class Solution {
public:
    struct Node {
        int len = 0;
        char leftChar = 0, rightChar = 0;
        int prefLen = 0, sufLen = 0, maxLen = 0;
    };
    
    vector<Node> tree;
    string str;
    int n;
    
    Node merge(const Node& l, const Node& r) {
        if (l.len == 0) return r;
        if (r.len == 0) return l;
        Node res;
        res.len = l.len + r.len;
        res.leftChar = l.leftChar;
        res.rightChar = r.rightChar;
        
        res.prefLen = l.prefLen;
        if (l.prefLen == l.len && l.rightChar == r.leftChar) {
            res.prefLen += r.prefLen;
        }
        
        res.sufLen = r.sufLen;
        if (r.sufLen == r.len && r.leftChar == l.rightChar) {
            res.sufLen += l.sufLen;
        }
        
        res.maxLen = max(l.maxLen, r.maxLen);
        if (l.rightChar == r.leftChar) {
            res.maxLen = max(res.maxLen, l.sufLen + r.prefLen);
        }
        
        return res;
    }
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].len = 1;
            tree[node].leftChar = str[start];
            tree[node].rightChar = str[start];
            tree[node].prefLen = 1;
            tree[node].sufLen = 1;
            tree[node].maxLen = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
    
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node+1, start, mid, idx, ch);
        else update(2*node+2, mid+1, end, idx, ch);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        n = s.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
        
        int k = queryCharacters.size();
        vector<int> result(k);
        
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];
            str[idx] = ch;
            update(0, 0, n - 1, idx, ch);
            result[i] = tree[0].maxLen;
        }
        
        return result;
    }
};