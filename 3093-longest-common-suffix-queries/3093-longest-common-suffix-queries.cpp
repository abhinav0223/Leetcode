struct TrieNode {
    int children[26];
    int bestIdx;
    TrieNode() {
        fill(begin(children), end(children), -1);
        bestIdx = -1;
    }
};

class Solution {
    vector<TrieNode> trie;

    void updateBest(int node, int idx, const vector<string>& wc) {
        int& best = trie[node].bestIdx;
        if (best == -1 ||
            wc[idx].size() < wc[best].size() ||
            (wc[idx].size() == wc[best].size() && idx < best)) {
            best = idx;
        }
    }

    void insert(const string& rev, int idx, const vector<string>& wc) {
        int cur = 0;
        updateBest(cur, idx, wc);
        for (char c : rev) {
            int ch = c - 'a';
            if (trie[cur].children[ch] == -1) {
                trie[cur].children[ch] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].children[ch];
            updateBest(cur, idx, wc);
        }
    }

    int query(const string& rev) {
        int cur = 0;
        int best = trie[cur].bestIdx;
        for (char c : rev) {
            int ch = c - 'a';
            if (trie[cur].children[ch] == -1) break;
            cur = trie[cur].children[ch];
            best = trie[cur].bestIdx;
        }
        return best;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.emplace_back();

        for (int i = 0; i < (int)wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(rev, i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (auto& q : wordsQuery) {
            string rev = q;
            reverse(rev.begin(), rev.end());
            ans.push_back(query(rev));
        }
        return ans;
    }
};