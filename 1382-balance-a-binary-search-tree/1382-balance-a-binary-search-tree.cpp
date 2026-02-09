class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* buildBalancedBST(vector<int>& vals, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(vals[mid]);

        root->left = buildBalancedBST(vals, left, mid - 1);
        root->right = buildBalancedBST(vals, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return buildBalancedBST(vals, 0, vals.size() - 1);
    }
};
