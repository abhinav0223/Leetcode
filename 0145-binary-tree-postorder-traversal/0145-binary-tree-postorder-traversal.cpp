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
void postorderHelper(TreeNode* root,vector<int> &result){
    if(!root) return;
    postorderHelper(root->left,result);
    postorderHelper(root->right,result);
     result.push_back(root->val);

}
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;
        postorderHelper (root, result);
        return result;
        
    }
};