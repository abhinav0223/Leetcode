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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  
        int maxindex = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxindex]) {
                maxindex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxindex]);
        root->left = buildTree(nums, left, maxindex - 1);
        root->right = buildTree(nums, maxindex + 1, right);

        return root;
    }
};
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}