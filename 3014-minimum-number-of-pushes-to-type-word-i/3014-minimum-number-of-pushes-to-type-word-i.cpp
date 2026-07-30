class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int pushes = 0;
        int key = 0; 
        for (int i = 0; i < n; i++) {
            int pushCount = i / 8 + 1;
            pushes += pushCount;
        }
        return pushes;
    }
};