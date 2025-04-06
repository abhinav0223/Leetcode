/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> result;
    if (!root) return result; 
    
    queue<TreeNode*> q;
    q.push(root);
    
    bool leftToRight = true;  
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level(levelSize);
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* currentNode = q.front();
            q.pop();
        
            int index = leftToRight ? i : levelSize - 1 - i;
            level[index] = currentNode->val;
            
            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
        }
        
        result.push_back(level);
        leftToRight = !leftToRight;  
    }
    
    return result;
}
};